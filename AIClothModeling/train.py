import torch
from torch import nn, optim
from torch.utils.data import Dataset, DataLoader
from torchvision import transforms, models
from PIL import Image
import json
import os

# Dataset personalizado
class RopaDataset(Dataset):
    def __init__(self, json_path, img_dir, transform=None):
        with open(json_path, "r") as f:
            self.data = json.load(f)
        self.img_dir = img_dir
        self.transform = transform

    def __len__(self):
        return len(self.data)

    def __getitem__(self, idx):
        item = self.data[idx]
        # Cargar imagen
        img_path = os.path.join(self.img_dir, item["imagen"])
        image = Image.open(img_path).convert("RGB")
        if self.transform:
            image = self.transform(image)
        # Parámetros
        params = torch.tensor([
            item["largo_manga"],
            item["ancho_torso"],
            item["largo_total"],
            item["cuello_tipo"]
        ], dtype=torch.float32)
        # Color RGB normalizado 0-1
        color = torch.tensor([c/255 for c in item["color"]], dtype=torch.float32)
        return image, params, color

# ------------------------------
# Transformaciones de imagen
# ------------------------------
transform = transforms.Compose([
    transforms.Resize((128,128)),
    transforms.ToTensor(),
])

dataset = RopaDataset("datasets/labels.json", "datasets/images", transform)
dataloader = DataLoader(dataset, batch_size=16, shuffle=True)

# ------------------------------
# Modelo simple
# ------------------------------
class RopaNet(nn.Module):
    def __init__(self):
        super().__init__()
        # Backbone CNN para imagen
        self.cnn = models.resnet18(weights=None)  # o weights='IMAGENET1K_V1'
        self.cnn.fc = nn.Identity()  # quitamos la última capa
        # MLP para parametros y color
        self.fc_params = nn.Sequential(
            nn.Linear(512, 128),
            nn.ReLU(),
            nn.Linear(128, 4)  # 4 parametros: largo_manga, ancho, largo_total, cuello
        )
        self.fc_color = nn.Sequential(
            nn.Linear(512, 64),
            nn.ReLU(),
            nn.Linear(64, 3)  # RGB
        )

    def forward(self, x):
        features = self.cnn(x)
        out_params = self.fc_params(features)
        out_color = self.fc_color(features)
        return out_params, out_color

# ------------------------------
# Entrenamiento
# ------------------------------
device = "cuda" if torch.cuda.is_available() else "cpu"
model = RopaNet().to(device)
optimizer = optim.Adam(model.parameters(), lr=1e-3)
criterion_params = nn.MSELoss()
criterion_color = nn.MSELoss()

for epoch in range(10):
    for images, params, color in dataloader:
        images = images.to(device)
        params = params.to(device)
        color = color.to(device)

        optimizer.zero_grad()
        pred_params, pred_color = model(images)
        loss_params = criterion_params(pred_params, params)
        loss_color = criterion_color(pred_color, color)
        loss = loss_params + loss_color
        loss.backward()
        optimizer.step()

    print(f"Epoch {epoch+1} - Loss: {loss.item():.4f}")

torch.save(model.state_dict(), "models/ropanet.pth")
print(" Entrenamiento completado y modelo guardado.")