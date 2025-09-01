import { Component } from '@angular/core';
import { UserService } from '../shared/user.service';
import { Router } from '@angular/router';

@Component({
  selector: 'app-register',
  templateUrl: './register.component.html',
  styleUrl: './register.component.css'
})
export class RegisterComponent {
  constructor(public service: UserService, private router: Router) { }

  ngOnInit() {
    if (this.service.formModel) {
      this.service.formModel.reset();
    }
  }

  onSubmit() {
    this.service.register().subscribe(
      (res: any) => {
        if (res.succeeded) {
          this.service.formModel.reset();
          alert("Registro completado con exito");
        } else {
          var isDuplicate = false;
          res.errors.forEach((element: { code: any; }) => {
            switch (element.code) {
              case 'DuplicateEmail':
                isDuplicate = true;
                break;
              case 'DuplicateUserName':
                //El usuario no esta disponible
                isDuplicate = true;
                break;
              default:
                //Registro fallido
                alert("Registro fallido,vuelva a intentarlo");
                break;
            }
          });
          if (isDuplicate)
            alert("Usuario duplicado, vuelva a intentarlo");

        }
      },
        (      err: any) => {
        console.log(err);
      }
    );
  }
}
