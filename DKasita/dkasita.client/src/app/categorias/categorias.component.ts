import { Component } from '@angular/core';
import { ActivatedRoute, Router } from '@angular/router';
import { CategoriasService } from '../shared/categorias.service';
import { Categoria } from '../shared/models/Categoria/Categoria';

@Component({
  selector: 'app-categorias',
  templateUrl: './categorias.component.html',
  styleUrl: './categorias.component.css'
})
export class CategoriasComponent {

  categorias: Categoria[] | undefined;
  constructor(private router: Router, private route: ActivatedRoute, private categoriasService: CategoriasService) {

  }

  public getAll(): void {
    this.categoriasService.GetAll()
      .then((x) => {
        this.categorias = x;
        console.log(x);
      });
  }
}
