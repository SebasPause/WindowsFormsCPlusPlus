using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace DKasita.Server.ViewModels.ApplicationUser
{
    public class LoginModel
    {
        public required string UserName { get; set; }
        public required string Password { get; set; }
    }
}
