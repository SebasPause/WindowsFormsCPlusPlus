using System;
using System.Collections.Generic;
using System.Text;

namespace DKasita.Server.ViewModels.ApplicationUser
{
    public class ApplicationUserModel
    {
        public required string UserName { get; set; }
        public required string Email { get; set; }
        public required string Password { get; set; }
        public required string FullName { get; set; }
    }
}
