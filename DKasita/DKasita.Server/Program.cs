using Microsoft.EntityFrameworkCore;
using Model;
using Newtonsoft.Json;

var builder = WebApplication.CreateBuilder(args);

// Configuraci�n de la cadena de conexi�n
builder.Services.AddDbContext<MyDbContext>(options =>
{
    options.UseSqlServer(
        builder.Configuration.GetConnectionString("DefaultConnection"), // Obt�n la cadena de conexi�n del archivo appsettings.json
        b => b.MigrationsAssembly("Model") // Especifica el ensamblado donde se generar�n las migraciones
    );
});

// Configuraci�n de CORS
builder.Services.AddCors(options =>
{
    options.AddPolicy("AllowAllOrigins",
        builder =>
        {
            builder.AllowAnyOrigin()   // Permitir cualquier origen
                   .AllowAnyMethod()   // Permitir cualquier m�todo (GET, POST, etc.)
                   .AllowAnyHeader();  // Permitir cualquier encabezado
        });
});

builder.Services.AddControllers()
    .AddNewtonsoftJson(options =>
    {
        options.SerializerSettings.ReferenceLoopHandling = ReferenceLoopHandling.Ignore;
    });


// Otras configuraciones (opcional)
//builder.Services.AddControllers(); // Si est�s usando controladores
builder.Services.AddEndpointsApiExplorer(); // Para explorar endpoints (opcional)

var app = builder.Build();

// Configuraci�n del pipeline de la aplicaci�n
if (app.Environment.IsDevelopment())
{
    app.UseDeveloperExceptionPage();
}

app.UseHttpsRedirection();
app.UseAuthorization();

// Aplicar la pol�tica de CORS
app.UseCors("AllowAllOrigins");

app.MapControllers(); // Mapea los controladores a las rutas

app.Run();