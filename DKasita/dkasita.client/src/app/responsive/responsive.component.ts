import { Component, EventEmitter, AfterViewInit, Output} from '@angular/core';
import { BreakpointObserver, Breakpoints } from '@angular/cdk/layout';

@Component({
  selector: 'app-responsive',
  templateUrl: './responsive.component.html',
  styleUrl: './responsive.component.css'
})
export class ResponsiveComponent implements AfterViewInit {

  @Output() menuIzquierdaChange = new EventEmitter<boolean>();
  menuIzquierda: boolean = false;

  constructor(private responsive: BreakpointObserver) {

  }

  ngAfterViewInit() {
    this.responsive.observe([Breakpoints.Handset]).subscribe(result => {
      this.menuIzquierda = result.matches;
      this.menuIzquierdaChange.emit(this.menuIzquierda);
      console.log("El menu esta en: "+this.menuIzquierda)
    });
  }

}
