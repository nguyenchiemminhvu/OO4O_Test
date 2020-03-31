#pragma once

#ifndef __DB_DIALOG_H__
#define __DB_DIALOG_H__

#include <oracl.h>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Runtime::InteropServices;

namespace OO4O_Test 
{

	/// <summary>
	/// Summary for DBDialog
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class DBDialog : public System::Windows::Forms::Form
	{
	public:
		static ODatabase LoginNewSession()
		{
			OSession newSession;
			newSession.Open();

			DBDialog ^diag = gcnew DBDialog();
			diag->ShowDialog(nullptr);
			ODatabase db = diag->GetDatabase();
			return db;
		}

	public:
		ODatabase *_db;
		ODatabase GetDatabase()
		{
			return *_db;
		}

		! DBDialog()
		{
			if (_db)
			{
				delete _db;
				_db = NULL;
			}
		}

	public:
		DBDialog(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			_db = new ODatabase();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~DBDialog()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textDBName;
	private: System::Windows::Forms::TextBox^  textUsername;
	private: System::Windows::Forms::TextBox^  textPassword;



	private: System::Windows::Forms::Button^  ButtonOK;
	private: System::Windows::Forms::Button^  ButtonCancel;



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textDBName = (gcnew System::Windows::Forms::TextBox());
			this->textUsername = (gcnew System::Windows::Forms::TextBox());
			this->textPassword = (gcnew System::Windows::Forms::TextBox());
			this->ButtonOK = (gcnew System::Windows::Forms::Button());
			this->ButtonCancel = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 22);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(53, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"DB Name";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 53);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(55, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Username";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(13, 86);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(53, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Password";
			// 
			// textDBName
			// 
			this->textDBName->Location = System::Drawing::Point(84, 19);
			this->textDBName->Name = L"textDBName";
			this->textDBName->Size = System::Drawing::Size(204, 20);
			this->textDBName->TabIndex = 3;
			// 
			// textUsername
			// 
			this->textUsername->Location = System::Drawing::Point(84, 50);
			this->textUsername->Name = L"textUsername";
			this->textUsername->Size = System::Drawing::Size(204, 20);
			this->textUsername->TabIndex = 4;
			// 
			// textPassword
			// 
			this->textPassword->Location = System::Drawing::Point(84, 83);
			this->textPassword->Name = L"textPassword";
			this->textPassword->PasswordChar = '*';
			this->textPassword->Size = System::Drawing::Size(204, 20);
			this->textPassword->TabIndex = 5;
			// 
			// ButtonOK
			// 
			this->ButtonOK->Location = System::Drawing::Point(132, 116);
			this->ButtonOK->Name = L"ButtonOK";
			this->ButtonOK->Size = System::Drawing::Size(75, 23);
			this->ButtonOK->TabIndex = 6;
			this->ButtonOK->Text = L"OK";
			this->ButtonOK->UseVisualStyleBackColor = true;
			this->ButtonOK->Click += gcnew System::EventHandler(this, &DBDialog::ButtonOK_Click);
			// 
			// ButtonCancel
			// 
			this->ButtonCancel->Location = System::Drawing::Point(213, 116);
			this->ButtonCancel->Name = L"ButtonCancel";
			this->ButtonCancel->Size = System::Drawing::Size(75, 23);
			this->ButtonCancel->TabIndex = 7;
			this->ButtonCancel->Text = L"Cancel";
			this->ButtonCancel->UseVisualStyleBackColor = true;
			this->ButtonCancel->Click += gcnew System::EventHandler(this, &DBDialog::ButtonCancel_Click);
			// 
			// DBDialog
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(301, 151);
			this->Controls->Add(this->ButtonCancel);
			this->Controls->Add(this->ButtonOK);
			this->Controls->Add(this->textPassword);
			this->Controls->Add(this->textUsername);
			this->Controls->Add(this->textDBName);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"DBDialog";
			this->Text = L"Database Connection";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
private: System::Void ButtonOK_Click(System::Object^  sender, System::EventArgs^  e) {
			 String ^sDBName = this->textDBName->Text;
			 String ^sUsername = this->textUsername->Text;
			 String ^sPassword= this->textPassword->Text;

			 IntPtr pDBName = Marshal::StringToHGlobalAnsi(sDBName);
			 IntPtr pUsername = Marshal::StringToHGlobalAnsi(sUsername);
			 IntPtr pPassword = Marshal::StringToHGlobalAnsi(sPassword);

			 char *cDBName = (char *)pDBName.ToPointer();
			 char *cUsername = (char *)pUsername.ToPointer();
			 char *cPassword = (char *)pPassword.ToPointer();

			 _db->Open(cDBName, cUsername, cPassword);

			 Marshal::FreeHGlobal(pDBName);
			 Marshal::FreeHGlobal(pUsername);
			 Marshal::FreeHGlobal(pPassword);

			 this->Close();
		 }
private: System::Void ButtonCancel_Click(System::Object^  sender, System::EventArgs^  e) {
			this->Close();
		 }
};
}

#endif // __DB_DIALOG_H__