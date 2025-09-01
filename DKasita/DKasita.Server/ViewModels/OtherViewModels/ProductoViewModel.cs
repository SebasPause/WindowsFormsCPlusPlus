using Model.Entities;

namespace DKasita.Server.ViewModels.OtherViewModels
{
    public class ProductoViewModel
    {
        public Guid Id { get; set; }
        public string? Nombre { get; set; }
        public string? Descripcion { get; set; }
        public Boolean? Destacado { get; set; }
        public int? Posicion { get; set; }
        public Double? Precio { get; set; }
        public int? Pisos { get; set; }
        public string? Relleno { get; set; }
        public string? URL { get; set; }
        public Guid CategoriaId { get; set; }
    }
}
