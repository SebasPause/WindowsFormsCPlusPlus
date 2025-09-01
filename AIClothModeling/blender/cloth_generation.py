import bpy
import json
import os

# --- Configuracion ---
# Ruta base donde está el script
base_dir = os.path.dirname(os.path.abspath(__file__))

# Construimos las rutas
json_path = os.path.join(base_dir, "..", "datasets", "labels.json")
export_dir = os.path.join(base_dir, "..", "datasets", "exports")
base_mesh_path = os.path.join(base_dir, "..", "blender", "Male_Tshirt.fbx")

# Normalizamos (importante en Windows)
json_path = os.path.normpath(json_path)
export_dir = os.path.normpath(export_dir)
base_mesh_path = os.path.normpath(base_mesh_path)

if not os.path.exists(export_dir):
    os.makedirs(export_dir)

# Limpiar escena
bpy.ops.object.select_all(action='SELECT')
bpy.ops.object.delete(use_global=False)

# ------------------------------
# Cargar dataset con parametros
# ------------------------------
if not os.path.exists(json_path):
    raise FileNotFoundError(f"No se encontro el archivo JSON: {json_path}")
with open(json_path, "r") as f:
    data = json.load(f)

# ------------------------------
# Generar ropa
# ------------------------------
for i, entry in enumerate(data):
    # Importar la malla base
    bpy.ops.import_scene.fbx(filepath=base_mesh_path)
    ropa = bpy.context.selected_objects[0]
    ropa.name = f"camisa_{i}"

    # Obtener parametros
    largo_manga = float(entry.get("largo_manga", 1.0))
    ancho_torso = float(entry.get("ancho_torso", 1.0))
    largo_total = float(entry.get("largo_total", 1.0))
    cuello_tipo = int(entry.get("cuello_tipo", 0))

    # Escalado directo de la malla segun parametros
    ropa.scale[0] *= ancho_torso     # ancho torso (X)
    ropa.scale[1] *= largo_total     # largo total (Y)
    ropa.scale[2] *= largo_manga     # largo mangas (Z)

    # Ajuste simple de cuello (solo deformacion basica)
    if cuello_tipo == 1:  # cuello tipo V
        bpy.context.view_layer.objects.active = ropa
        bpy.ops.object.mode_set(mode='EDIT')
        bpy.ops.mesh.select_all(action='DESELECT')
        bpy.ops.object.mode_set(mode='OBJECT')

        mesh = ropa.data
        max_z = max(v.co.z for v in mesh.vertices)
        for v in mesh.vertices:
            if v.co.z > 0.9 * max_z:
                v.co.x *= 0.6  # estrechar para cuello V

        bpy.ops.object.mode_set(mode='OBJECT')

    # Exportar a FBX
    export_path = os.path.join(export_dir, f"camisa_{i}.fbx")
    bpy.ops.export_scene.fbx(
        filepath=export_path,
        use_selection=True,
        apply_unit_scale=True,
        bake_space_transform=True,
        add_leaf_bones=False
    )

    # Eliminar objeto antes de pasar al siguiente
    bpy.ops.object.delete()

print(f"{len(data)} camisetas generadas con Shape Keys y exportadas en: {export_dir}")