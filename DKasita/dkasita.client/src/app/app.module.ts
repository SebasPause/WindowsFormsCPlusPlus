import { HttpClientModule } from '@angular/common/http';
import { NgModule } from '@angular/core';
import { BrowserModule } from '@angular/platform-browser';
import { RouterModule } from '@angular/router';
import { ReactiveFormsModule } from "@angular/forms";
import { FormsModule } from '@angular/forms';

import { AppRoutingModule } from './app-routing.module';
import { AppComponent } from './app.component';
import { UserService } from './shared/user.service';
import { HomeComponent } from './home/home.component';
import { MenuComponent } from './menu/menu.component';
import { provideAnimationsAsync } from '@angular/platform-browser/animations/async';
import { ResponsiveComponent } from './responsive/responsive.component';
import { RegisterComponent } from './register/register.component';
import { CategoriasComponent } from './categorias/categorias.component';

@NgModule({
  declarations: [
    AppComponent,
    HomeComponent,
    MenuComponent,
    ResponsiveComponent,
    RegisterComponent,
    CategoriasComponent
  ],
  imports: [
    BrowserModule.withServerTransition({ appId: 'ng-cli-universal' }), HttpClientModule,
    AppRoutingModule,
    ReactiveFormsModule,
    FormsModule,
    RouterModule.forRoot([
      { path: '', component: HomeComponent, pathMatch: 'full' }
    ]),
  ],
  providers: [UserService, provideAnimationsAsync()],
  bootstrap: [AppComponent]
})
export class AppModule { }
