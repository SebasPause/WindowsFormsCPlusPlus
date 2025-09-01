import { ChangeDetectorRef, Component, OnInit } from '@angular/core';
import { Navigation, Router } from '@angular/router';
import { ResponsiveComponent } from '../responsive/responsive.component';

@Component({
  selector: 'app-menu',
  templateUrl: './menu.component.html',
  styleUrls: ['./menu.component.css']
})
export class MenuComponent {

  menuIzquierda: boolean = false;
  showMenu: boolean = false; // Controla el estado desplegado del menú
  constructor(private router: Router, private cdr: ChangeDetectorRef) {
    
  }

  onMenuIzquierdaChange(menuIzquierda: boolean) {
    this.menuIzquierda = menuIzquierda;
    if (this.menuIzquierda == false) {
      this.showMenu = false;
    }
    this.cdr.detectChanges(); // Forzar la detección de cambios
    console.log('menuIzquierda ha cambiado:', this.menuIzquierda); // Para confirmar el cambio
  }

}
