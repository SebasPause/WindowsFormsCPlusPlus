import { HttpClient, HttpHeaders } from '@angular/common/http';
import { Injectable } from '@angular/core';
import { Categoria } from './models/Categoria/Categoria';
import { Observable, catchError, throwError } from 'rxjs';

@Injectable({
  providedIn: 'root'
})
export class CategoriasService {

  constructor(private http: HttpClient) { }

  public GetAll() {
    //let headers = new HttpHeaders({ 'Authorization': 'Bearer ' + localStorage.getItem('token') });
    return this.http.get<Categoria[]>(`/api/categoria`, { })
      .toPromise();
  }
}
