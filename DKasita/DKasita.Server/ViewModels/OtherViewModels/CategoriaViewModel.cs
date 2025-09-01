using Model.Entities;

namespace DKasita.Server.ViewModels.OtherViewModels
{
    public class CategoriaViewModel
    {
        public Guid ID { get; set; }
        public string? Nombre { get; set; }
        public string? Descripcion { get; set; }
        public string? URL { get; set; }
        public Enum? Tipo { get; set; }
    }
}
