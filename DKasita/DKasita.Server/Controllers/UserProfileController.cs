using DKasita.Server.ViewModels.OtherViewModels;
using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Identity;
using Microsoft.AspNetCore.Mvc;
using Model;
using Model.Entities;
using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DKasita.Server.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class UserProfileController : ControllerBase
    {
        private UserManager<ApplicationUser> _userManager;
        private readonly MyDbContext _context;

        public UserProfileController(UserManager<ApplicationUser> userManager,MyDbContext context)
        {
            _userManager = userManager;
            _context = context;
        }

        [HttpGet]
        [Authorize]
        //GET : /api/UserProfile
        public async Task<Object> GetUserProfile()
        {
            string userId = User.Claims.First(c => c.Type == "UserID").Value;
            var user = await _userManager.FindByIdAsync(userId);
            return new
            {
                user?.Id,
                user?.FullName,
                user?.Email,
                user?.UserName
            };
        }

        [Authorize]
        [HttpPut("update")]
        public async Task<IActionResult> Update([FromBody] UsuarioViewModel model)
        {
            try
            {
                var entity = _context.ApplicationUsers.FirstOrDefault(a => a.Id == model.id);
                entity.FullName = model.FullName;
                entity.ImageUrl = model.Image;

                await _context.SaveChangesAsync();
                String message = "Modificado con exito";
                return Ok(new { message });
            }
            catch (Exception ex)
            {
                return BadRequest(ex.Message);
            }
        }

    }
}
