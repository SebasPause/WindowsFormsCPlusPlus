#include "Noticia.h"
#pragma once

namespace GridViewNoticias {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::DataGridView^ dataGridView1;









	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ id;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ titulo;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ texto;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ categoria;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ fecha;
	private: System::Windows::Forms::DataGridViewButtonColumn^ eliminar;










		MySqlConnection^ conexion;
		MySqlConnection^ CrearConexion() {
			conexion = gcnew MySqlConnection("Server=localhost;Port=3306;Database=nascor;Uid=root;Pwd=;");
			return conexion;
		}

		MySqlDataReader^ SeleccionarDatos() {
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
			}
		}
		void q(String^ q) {
			MySqlCommand^ comando = gcnew MySqlCommand(q, conexion);
			try
			{
				conexion->Open();
				comando->ExecuteNonQuery();
				MessageBox::Show("Query ejecuta correctamente.");
			}
			catch (Exception^ ex)
			{
				MessageBox::Show("Error al ejecutar la query: " + ex->Message);
			}
			finally {
				conexion->Close();
			}
		}
		void mostrarDatos() {
			MySqlDataReader^ reader = SeleccionarDatos();
			int i = 0;
			if (dataGridView1->Rows->Count >= 1) {
				dataGridView1->Rows->Clear();
				dataGridView1->Refresh();
			}
			while (reader->Read()) {
				dataGridView1->Rows->Add();

				dataGridView1->Rows[i]->Cells[0]->Value = reader->GetInt32(0);
				dataGridView1->Rows[i]->Cells[1]->Value = reader->GetString(1);
				dataGridView1->Rows[i]->Cells[2]->Value = reader->GetString(2);
				dataGridView1->Rows[i]->Cells[3]->Value = reader->GetString(3);
				dataGridView1->Rows[i]->Cells[4]->Value = reader->GetDateTime(4);
				i++;
			};

			if (reader != nullptr) {
				reader->Close();
			}
			conexion->Close();
		}

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->id = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->titulo = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->texto = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->categoria = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->fecha = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->eliminar = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(465, 487);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"load";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->id, this->titulo,
					this->texto, this->categoria, this->fecha, this->eliminar
			});
			this->dataGridView1->Location = System::Drawing::Point(34, 43);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(1002, 370);
			this->dataGridView1->TabIndex = 3;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellContentClick);
			// 
			// id
			// 
			this->id->HeaderText = L"ID";
			this->id->MinimumWidth = 11;
			this->id->Name = L"id";
			this->id->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->id->Width = 50;
			// 
			// titulo
			// 
			this->titulo->HeaderText = L"Titulo";
			this->titulo->Name = L"titulo";
			this->titulo->Width = 150;
			// 
			// texto
			// 
			this->texto->HeaderText = L"Texto";
			this->texto->Name = L"texto";
			this->texto->Width = 400;
			// 
			// categoria
			// 
			this->categoria->HeaderText = L"Categoria";
			this->categoria->Name = L"categoria";
			this->categoria->Width = 150;
			// 
			// fecha
			// 
			this->fecha->HeaderText = L"Fecha";
			this->fecha->Name = L"fecha";
			// 
			// eliminar
			// 
			this->eliminar->HeaderText = L"Eliminar";
			this->eliminar->Name = L"eliminar";
			this->eliminar->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->eliminar->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Automatic;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1079, 571);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		//Primera manera, la mas optima
		mostrarDatos();

		/* Segunda manera
		MySqlDataReader^ reader = SeleccionarDatos();
		//array<Noticia^>^ datos = gcnew array<Noticia^>(100);
		int i = 0;
		while (reader->Read()) {
			datos[i] = gcnew Noticia(reader->GetInt32(0), reader->GetString(1), reader->GetString(2), reader->GetString(3), reader->GetDateTime(4));
			i++;
		};

		if (reader != nullptr) {
			reader->Close();
		}
		conexion->Close();

		i = 0;
		for each (Noticia ^ dato in datos) {
			if (dato != nullptr) {
				dataGridView1->Rows->Add();

				dataGridView1->Rows[i]->Cells[0]->Value = dato->id;
				dataGridView1->Rows[i]->Cells[1]->Value = dato->titulo;
				dataGridView1->Rows[i]->Cells[2]->Value = dato->texto;
				dataGridView1->Rows[i]->Cells[3]->Value = dato->categoria;
				dataGridView1->Rows[i]->Cells[4]->Value = dato->fecha;
				i++;
			}
			else {
				break;
			}
			
		}*/
		
	}
	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		if (e->RowIndex >= 0 && e->ColumnIndex == 5 && e->RowIndex < (dataGridView1->Rows->Count -1)) {
			int fila = e->RowIndex;
			String^ id = dataGridView1->Rows[fila]->Cells[0]->Value->ToString();

			q("DELETE FROM noticias WHERE id="+Convert::ToInt32(id));
			mostrarDatos();
		}
	}
};
}
