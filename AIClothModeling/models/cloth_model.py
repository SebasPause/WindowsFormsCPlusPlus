import torch
import torch.nn as nn
import torchvision.models as models

class ClothModel(nn.Module):
    def __init__(self):
        super().__init__()
        base = models.mobilenet_v2(pretrained=True)
        # Ajustamos la �ltima capa para 4 salidas: 3 regresi�n + 1 clasificaci�n
        base.classifier[1] = nn.Linear(1280, 4)
        self.model = base

    def forward(self, x):
        return self.model(x)





