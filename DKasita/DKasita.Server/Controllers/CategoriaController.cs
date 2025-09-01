using DKasita.Server.ViewModels.OtherViewModels;
using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using Model;
using Model.Entities;
using System.Data.Entity;
using static System.Reflection.Metadata.BlobBuilder;

namespace DKasita.Server.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class CategoriaController : ControllerBase
    {
        private readonly MyDbContext _context;

        public CategoriaController(MyDbContext context)
        {
            _context = context;
        }

        [HttpGet("todas")]
        public async Task<IActionResult> GetCategorias()
        {
            var categorias = await _context.Categorias.ToListAsync(); // Asegúrate de tener una DbSet<Categoria> en tu DbContext
            if (categorias == null || !categorias.Any())
            {
                return NotFound("No se encontraron categorías.");
            }

            return Ok(categorias);
        }

        /*//api/categoria
        [Authorize]
        [HttpGet]
        public async Task<IActionResult> GetAll()
        {
            List<Categoria> categorias;
            List<CategoriaViewModel> categoriasLista = new List<CategoriaViewModel>();
            CategoriaViewModel categoriaVM;
            try
            {
                categorias = _context.Categorias.ToList();
                foreach (Categoria item in categorias)
                {
                    categoriaVM = new CategoriaViewModel();
                    categoriaVM.Nombre = item.Nombre;
                    categoriaVM.Descripcion = item.Descripcion;
                    categoriaVM.URL = item.URL;
                    categoriaVM.Tipo = item.Tipo;
                    categoriasLista.Add(categoriaVM);
                }
                return new OkObjectResult(categoriasLista);
            }
            catch (Exception ex)
            {
                return BadRequest(ex.Message);
            }
        } //fin getAll*/

        //api/categoria
        [Authorize]
        [HttpGet]
        public async Task<IActionResult> GetAllTartas()
        {
            List<Categoria> categorias;
            List<CategoriaViewModel> categoriasLista = new List<CategoriaViewModel>();
            CategoriaViewModel categoriaVM;
            try
            {
                categorias = _context.Categorias.ToList();
                foreach (Categoria item in categorias)
                {
                    categoriaVM = new CategoriaViewModel();
                    categoriaVM.Nombre = item.Nombre;
                    categoriaVM.Descripcion = item.Descripcion;
                    categoriaVM.URL = item.URL;
                    categoriaVM.Tipo = item.Tipo;
                    if (!categoriaVM.Tipo.Equals(Tipo.Tarta))
                    {
                        categoriasLista.Add(categoriaVM);
                    }
                }
                return new OkObjectResult(categoriasLista);
            }
            catch (Exception ex)
            {
                return BadRequest(ex.Message);
            }
        } //fin getAllTartas

        //api/categoria
        [Authorize]
        [HttpGet]
        public async Task<IActionResult> GetAllPostres()
        {
            List<Categoria> categorias;
            List<CategoriaViewModel> categoriasLista = new List<CategoriaViewModel>();
            CategoriaViewModel categoriaVM;
            try
            {
                categorias = _context.Categorias.ToList();
                foreach (Categoria item in categorias)
                {
                    categoriaVM = new CategoriaViewModel();
                    categoriaVM.Nombre = item.Nombre;
                    categoriaVM.Descripcion = item.Descripcion;
                    categoriaVM.URL = item.URL;
                    categoriaVM.Tipo = item.Tipo;
                    if (!categoriaVM.Tipo.Equals(Tipo.Postre))
                    {
                        categoriasLista.Add(categoriaVM);
                    }
                }
                return new OkObjectResult(categoriasLista);
            }
            catch (Exception ex)
            {
                return BadRequest(ex.Message);
            }
        } //fin getAllPostres

        //api/categoria
        [Authorize]
        [HttpGet]
        public async Task<IActionResult> GetAllResto()
        {
            List<Categoria> categorias;
            List<CategoriaViewModel> categoriasLista = new List<CategoriaViewModel>();
            CategoriaViewModel categoriaVM;
            try
            {
                categorias = _context.Categorias.ToList();
                foreach (Categoria item in categorias)
                {
                    categoriaVM = new CategoriaViewModel();
                    categoriaVM.Nombre = item.Nombre;
                    categoriaVM.Descripcion = item.Descripcion;
                    categoriaVM.URL = item.URL;
                    categoriaVM.Tipo = item.Tipo;
                    if (!categoriaVM.Tipo.Equals(Tipo.Resto))
                    {
                        categoriasLista.Add(categoriaVM);
                    }
                }
                return new OkObjectResult(categoriasLista);
            }
            catch (Exception ex)
            {
                return BadRequest(ex.Message);
            }
        } //fin getAllResto

        [HttpPost]
        [Route("insert")]
        public async Task<IActionResult> Insert([FromBody] CategoriaViewModel model)
        {
            try
            {
                Categoria categoria = new Categoria();
                categoria.Id = model.ID;
                categoria.Nombre = model.Nombre;
                categoria.Descripcion = model.Descripcion;
                categoria.URL = model.URL;
                categoria.Tipo = (Tipo?)model.Tipo;
                _context.Categorias.Add(categoria);

                await _context.SaveChangesAsync();

                String message = "Alta correcta";
                return Ok(new { message });
            }
            catch (Exception ex)
            {
                return BadRequest(ex.Message);
            }
        }

        [Authorize]
        [HttpPut("actualizarCategoria")]
        public async Task<IActionResult> Update([FromBody] CategoriaViewModel model)
        {
            try
            {
                var entity = _context.Categorias.FirstOrDefault(a => a.Id == model.ID);
                if(entity != null)
                {
                    entity.Nombre = model.Nombre;
                    entity.Descripcion = model.Descripcion;
                    entity.URL = model.URL;
                    entity.Tipo = (Tipo?)model.Tipo;
                }

                await _context.SaveChangesAsync();

                String message = "Datos modificados correctamente";
                return Ok(new { message });
            }
            catch (Exception ex)
            {
                return BadRequest(ex.Message);
            }
        }
    }
}
