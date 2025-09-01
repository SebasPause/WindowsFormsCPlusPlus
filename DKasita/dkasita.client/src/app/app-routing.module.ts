import { NgModule } from '@angular/core';
import { RouterModule, Routes } from '@angular/router';
import { HomeComponent } from './home/home.component';
import { AppComponent } from './app.component';
import { RegisterComponent } from './register/register.component';
import { CategoriasComponent } from './categorias/categorias.component';

const routes: Routes = [
  { path: 'inicio', component: HomeComponent },
  { path: 'categorias', component: CategoriasComponent },
  { path: 'registro', component: RegisterComponent },

  { path: '', redirectTo: '/inicio', pathMatch: 'full' }
];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
export class AppRoutingModule { }
