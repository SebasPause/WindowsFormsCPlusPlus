#include <cstdlib>
#include <iostream>
#include <string>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

#pragma once
ref class Usuario
{

private:
	int idUsuario;
	String^ nombreCompleto;
	String^ correo;
	String^ contrasenia;
	String^ fechaAlta;

public:
	Usuario() {}

	Usuario(int idUsuario, String^ nombreCompleto, String^ correo, String^ contrasenia, String^ fechaAlta) {
		this->idUsuario = idUsuario;
		this->nombreCompleto = nombreCompleto;
		this->correo = correo;
		this->contrasenia = contrasenia;
		this->fechaAlta = fechaAlta;
	}

	void setIdUsuario(int idUsuario) {
		this->idUsuario = idUsuario;
	}

	int getIdUsuario() {
		return this->idUsuario;
	}

	void setNombreCompleto(String^ nombreCompleto) {
		this->nombreCompleto = nombreCompleto;
	}

	String^ getNombreCompleto() {
		return this->nombreCompleto;
	}

	void setCorreo(String^ correo) {
		this->correo = correo;
	}

	String^ getCorreo() {
		return this->correo;
	}

	void setContrasenia(String^ contrasenia) {
		this->correo = contrasenia;
	}

	String^ getContrasenia() {
		return this->contrasenia;
	}

	void setFechaAlta(String^ fechaAlta) {
		this->fechaAlta = fechaAlta;
	}

	String^ getFechaAlta() {
		return this->fechaAlta;
	}

};



