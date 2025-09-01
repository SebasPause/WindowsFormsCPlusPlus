using Microsoft.EntityFrameworkCore;
using Model;
using Newtonsoft.Json;

var builder = WebApplication.CreateBuilder(args);

// Configuración de la cadena de conexión
builder.Services.AddDbContext<MyDbContext>(options =>
{
    options.UseSqlServer(
        builder.Configuration.GetConnectionString("DefaultConnection"), // Obtén la cadena de conexión del archivo appsettings.json
        b => b.MigrationsAssembly("Model") // Especifica el ensamblado donde se generarán las migraciones
    );
});

// Configuración de CORS
builder.Services.AddCors(options =>
{
    options.AddPolicy("AllowAllOrigins",
        builder =>
        {
            builder.AllowAnyOrigin()   // Permitir cualquier origen
                   .AllowAnyMethod()   // Permitir cualquier método (GET, POST, etc.)
                   .AllowAnyHeader();  // Permitir cualquier encabezado
        });
});

builder.Services.AddControllers()
    .AddNewtonsoftJson(options =>
    {
        options.SerializerSettings.ReferenceLoopHandling = ReferenceLoopHandling.Ignore;
    });


// Otras configuraciones (opcional)
//builder.Services.AddControllers(); // Si estás usando controladores
builder.Services.AddEndpointsApiExplorer(); // Para explorar endpoints (opcional)

var app = builder.Build();

// Configuración del pipeline de la aplicación
if (app.Environment.IsDevelopment())
{
    app.UseDeveloperExceptionPage();
}

app.UseHttpsRedirection();
app.UseAuthorization();

// Aplicar la política de CORS
app.UseCors("AllowAllOrigins");

app.MapControllers(); // Mapea los controladores a las rutas

app.Run();