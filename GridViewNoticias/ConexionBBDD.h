#include <cstdlib>
#include <iostream>
#include "Usuario.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace MySql::Data::MySqlClient;

#pragma once
ref class ConexionBBDD
{
private:
	MySqlConnection^ conexion;
public:
	
	ConexionBBDD() {}

	void setConexion(MySqlConnection^ conexion) {
		this->conexion = conexion;
	}

	MySqlConnection^ getConexion() {
		return this->conexion;
	}

	MySqlConnection^ CrearConexion() {
		conexion = gcnew MySqlConnection("Server=localhost;Port=3306;Database=nascor;Uid=root;Pwd=;");
		return conexion;
	}

	MySqlDataReader^ ObtenerNoticias() {
		conexion = CrearConexion();
		MySqlCommand^ comando = gcnew MySqlCommand("SELECT * FROM noticias", conexion);
		MySqlDataReader^ reader = nullptr;
		try
		{
			conexion->Open();
			reader = comando->ExecuteReader();

			return reader;
		}
		catch (Exception^ ex)
		{
			MessageBox::Show("Error al conectar a la base de datos: " + ex->Message);
			return nullptr;
		}
	}

	MySqlDataReader^ ObtenerNoticiasUsuario(int idUsuario) {
		conexion = CrearConexion();
		MySqlCommand^ comando = gcnew MySqlCommand("SELECT * FROM noticias where user_id="+idUsuario, conexion);
		MySqlDataReader^ reader = nullptr;
		try
		{
			conexion->Open();
			reader = comando->ExecuteReader();

			return reader;
		}
		catch (Exception^ ex)
		{
			MessageBox::Show("Error al conectar a la base de datos: " + ex->Message);
			return nullptr;
		}
	}

	Usuario^ ObtenerUsuario(String^ correo, String^ password) {
		conexion = CrearConexion();
		MySqlCommand^ comando = gcnew MySqlCommand("SELECT * FROM usuario where email='"+correo+"' and password='"+password+"'",conexion);
		MySqlDataReader^ reader = nullptr;
		Usuario^ usuario = nullptr;

		try {
			conexion->Open();
			reader = comando->ExecuteReader();

			if (reader != nullptr) {
				while (reader->Read()) {
					usuario = gcnew Usuario(reader->GetInt32(0), reader->GetString(1), reader->GetString(2), reader->GetString(3), reader->GetDateTime(4).ToString());
				}
			}

			if (reader != nullptr) {
				reader->Close();
			}
			cerrarConexion();

			return usuario;
		}
		catch (Exception^ ex)
		{
			MessageBox::Show("Error al conectar a la base de datos: " + ex->Message);
			return nullptr;
		}
	}

	void cerrarConexion() {
		conexion->Close();
	}

	void q(String^ q) {
		try
		{
			if (conexion == nullptr) {
				conexion = CrearConexion();
			}

			MySqlCommand^ comando = gcnew MySqlCommand(q, conexion);

			conexion->Open();
			comando->ExecuteNonQuery();
			MessageBox::Show("Query ejecutada correctamente.");
		}
		catch (Exception^ ex)
		{
			MessageBox::Show("Error al ejecutar la query: " + ex->Message);
		}
		finally {
			conexion->Close();
		}
	}

};





