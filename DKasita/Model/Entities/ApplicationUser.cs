using Microsoft.AspNet.Identity.EntityFramework;
using Microsoft.AspNetCore.Identity;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Model.Entities
{
    public class ApplicationUser : IdentityUser<Guid>
    {
        public required string FullName { get; set; }
        public string? ImageUrl { get; set; }

        public required Boolean administrator { get; set; }

    }
}
