using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace DKasita.Server.ViewModels.OtherViewModels
{
    public class UsuarioViewModel
    {
        public Guid id { get; set; }
        public required string FullName { get; set; }
        public string? Image { get; set; }
    }
}
