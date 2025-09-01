using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Model.Entities
{
    public class Producto : Base
    {
        public string? Nombre { get; set; }
        public string? Descripcion { get; set; }
        public Boolean? Destacado { get; set; }
        public int? Posicion { get; set; }
        public Double? Precio { get; set; }
        public int? Pisos { get; set; }
        public string? Relleno { get; set; }
        public string? URL { get; set; }
        public virtual Categoria? Categoria { get; set; }

    }
}
