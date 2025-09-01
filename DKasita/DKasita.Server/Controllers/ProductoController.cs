using DKasita.Server.ViewModels.OtherViewModels;
using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using Model;
using Model.Entities;
using System.Net;
using static System.Reflection.Metadata.BlobBuilder;

namespace DKasita.Server.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class ProductoController : ControllerBase
    {
        private readonly MyDbContext _context;

        public ProductoController(MyDbContext context)
        {
            _context = context;
        }

        //api/categoria
        [Authorize]
        [HttpGet]
        public async Task<IActionResult> GetAll()
        {
            List<Producto> productos;
            List<ProductoViewModel> productosLista = new List<ProductoViewModel>();
            ProductoViewModel productoVM;
            try
            {
                productos = _context.Productos.ToList();
                foreach (Producto item in productos)
                {
                    productoVM = new ProductoViewModel();
                    productoVM.Nombre = item.Nombre;
                    productoVM.Descripcion = item.Descripcion;
                    productoVM.Relleno = item.Relleno;
                    productoVM.URL = item.URL;
                    productoVM.Pisos = item.Pisos;
                    productoVM.Posicion = item.Posicion;
                    productoVM.Precio = item.Precio;
                    productoVM.Destacado = item.Destacado;
                    productoVM.CategoriaId = item.Categoria.Id;
                    productosLista.Add(productoVM);
                }
                return new OkObjectResult(productosLista);
            }
            catch (Exception ex)
            {
                return BadRequest(ex.Message);
            }
        } //fin getAll

        //api/categoria
        [Authorize]
        [HttpGet]
        public async Task<IActionResult> GetAllByCategoria(Guid categoriaID)
        {
            List<Producto> productos;
            List<ProductoViewModel> productosLista = new List<ProductoViewModel>();
            ProductoViewModel productoVM;
            try
            {
                if (categoriaID == Guid.Empty)
                    return BadRequest("Invalid book id");
                productos = _context.Productos.Where(p => p.Categoria.Id == categoriaID).OrderBy(c => c.Posicion).ToList();
                foreach (Producto item in productos)
                {
                    productoVM = new ProductoViewModel();
                    productoVM.Nombre = item.Nombre;
                    productoVM.Descripcion = item.Descripcion;
                    productoVM.Relleno = item.Relleno;
                    productoVM.URL = item.URL;
                    productoVM.Pisos = item.Pisos;
                    productoVM.Posicion = item.Posicion;
                    productoVM.Precio = item.Precio;
                    productoVM.Destacado = item.Destacado;
                    productoVM.CategoriaId = item.Categoria.Id;
                    productosLista.Add(productoVM);
                }
                return new OkObjectResult(productosLista);
            }
            catch (Exception ex)
            {
                return BadRequest(ex.Message);
            }
        } //fin getAllByCategoria

       

        [HttpPost]
        [Route("insert")]
        public async Task<IActionResult> Insert([FromBody] ProductoViewModel model)
        {
            try
            {
                Producto producto = new Producto();
                producto.Nombre = model.Nombre;
                producto.Descripcion = model.Descripcion;
                producto.Relleno = model.Relleno;
                producto.URL = model.URL;
                producto.Pisos = model.Pisos;
                producto.Posicion = model.Posicion;
                producto.Precio = model.Precio;
                producto.Destacado = model.Destacado;
                producto.Categoria.Id = model.CategoriaId;
                _context.Productos.Add(producto);

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
        [HttpPut("actualizarProducto")]
        public async Task<IActionResult> Update([FromBody] ProductoViewModel model)
        {
            try
            {
                var entity = _context.Productos.FirstOrDefault(a => a.Id == model.Id);
                if(entity != null)
                {
                    entity.Nombre = model.Nombre;
                    entity.Descripcion = model.Descripcion;
                    entity.Relleno = model.Relleno;
                    entity.URL = model.URL;
                    entity.Pisos = model.Pisos;
                    entity.Posicion = model.Posicion;
                    entity.Precio = model.Precio;
                    entity.Destacado = model.Destacado;
                    entity.Categoria.Id = model.CategoriaId;
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
