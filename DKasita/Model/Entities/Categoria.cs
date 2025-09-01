using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Model.Entities

{

    
    public class Categoria : Base
    {
        public string? Nombre { get; set; }
        public string? Descripcion { get; set; }
        public string? URL { get; set; }
        public Tipo? Tipo { get; set; }

        public virtual ICollection<Producto>? Productos { get; set; }

    }
    public enum Tipo
    {
        Tarta,
        Postre,
        Resto
    }
}
