# -*- coding: utf-8 -*-
import torch
from torchvision import transforms, models
from PIL import Image
import json
import os
from train import RopaNet

# ------------------------------
# Configuracion
# ------------------------------
model_path = "models/ropanet.pth"
image_path = "datasets/images/camisa2.jpg"
output_json = "datasets/labels.json"

device = "cuda" if torch.cuda.is_available() else "cpu"

# ------------------------------
# Transformación de la imagen
# ------------------------------
transform = transforms.Compose([
    transforms.Resize((128,128)),
    transforms.ToTensor(),
])

# ------------------------------
# Cargar modelo entrenado
# ------------------------------
model = RopaNet().to(device)
model.load_state_dict(torch.load(model_path, map_location=device))
model.eval()

# ------------------------------
# Cargar imagen
# ------------------------------
img = Image.open(image_path).convert("RGB")
img_tensor = transform(img).unsqueeze(0).to(device)  # batch size 1

# ------------------------------
# Prediccion
# ------------------------------
with torch.no_grad():
    pred_params, pred_color = model(img_tensor)

# Convertir a lista
pred_params = pred_params.cpu().squeeze().tolist()
pred_color = [int(c*255) for c in pred_color.cpu().squeeze().tolist()]

# Crear diccionario listo para cloth_generation.py
output_data = [{
    "imagen": os.path.basename(image_path),
    "largo_manga": pred_params[0],
    "ancho_torso": pred_params[1],
    "largo_total": pred_params[2],
    "cuello_tipo": int(round(pred_params[3])),  # redondear cuello tipo
    "color": pred_color
}]

# Guardar JSON
with open(output_json, "w") as f:
    json.dump(output_data, f, indent=4)

print(f"Prediccion completada y guardada en {output_json}")
print(f"Parametros: {pred_params}")
print(f"Color RGB: {pred_color}")
