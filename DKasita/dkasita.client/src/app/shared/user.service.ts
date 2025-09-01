import { Injectable } from '@angular/core';
import { FormBuilder, FormGroup, Validators } from '@angular/forms';
import { HttpClient } from '@angular/common/http';

@Injectable({
  providedIn: 'root'
})
export class UserService {

  formModel: FormGroup;
  readonly BaseURI = 'http://localhost:4001/api';

  constructor(private fb: FormBuilder, private http: HttpClient) {
    this.formModel = this.fb.group({
      // Define aquí los campos del formulario con sus validaciones
      FullName: ['', Validators.required],
      Email: ['', [Validators.required, Validators.email]],
      Passwords: this.fb.group({
        Password: ['', [Validators.required, Validators.minLength(4)]],
        ConfirmPassword: ['', Validators.required]
      }, { validator: this.comparePasswords })
    });
  }
  
  


  comparePasswords(fb: FormGroup) {
    let confirmPswrdCtrl = fb.get('ConfirmPassword');
    if (confirmPswrdCtrl != null) {
      if (confirmPswrdCtrl.errors == null || 'passwordMismatch' in confirmPswrdCtrl.errors) {
        if (fb.get('Password')?.value != confirmPswrdCtrl.value)
          confirmPswrdCtrl.setErrors({ passwordMismatch: true });
        else
          confirmPswrdCtrl.setErrors(null);
      }
    }
  }

  register() {
    var body = {
      FullName: this.formModel.value.FullName,
      Email: this.formModel.value.Email,
      Password: this.formModel.value.Passwords.Password
    }
    return this.http.post(this.BaseURI + '/ApplicationUser/Registro', body);
  }

  login(formData: any) {
    return this.http.post(this.BaseURI + '/ApplicationUser/Login', formData);
  }
}
