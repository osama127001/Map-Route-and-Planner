#pragma once

#include<exception>

namespace DSProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Map_Pak
	/// </summary>
	public ref class Map_Pak : public System::Windows::Forms::Form
	{
	public:
		Form ^ obj;
		bool chkbx;
		String^ Map;
		Map_Pak(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

		}

		Map_Pak(Form^ obj1, String^ Paths_Line, float Min, bool Inter_City, String^ city)
		{
			obj = obj1;
			InitializeComponent();
			label3->Text = Convert::ToString(Min);
			label1->Text = Paths_Line;
			chkbx = Inter_City;
			Map = city;
			//
			//TODO: Add the constructor code here
			//
			font1 = gcnew System::Drawing::Font("Verdana", 3, FontStyle::Regular, GraphicsUnit::Millimeter);
			font2 = gcnew System::Drawing::Font("Verdana", 3, FontStyle::Regular, GraphicsUnit::Millimeter);

		}


	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Map_Pak()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Diagnostics::Process^  process1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Drawing::Font^ font1;
	private: System::Drawing::Font^ font2;

	protected:

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
			this->process1 = (gcnew System::Diagnostics::Process());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// process1
			// 
			this->process1->StartInfo->Domain = L"";
			this->process1->StartInfo->LoadUserProfile = false;
			this->process1->StartInfo->Password = nullptr;
			this->process1->StartInfo->StandardErrorEncoding = nullptr;
			this->process1->StartInfo->StandardOutputEncoding = nullptr;
			this->process1->StartInfo->UserName = L"";
			this->process1->SynchronizingObject = this;
			this->process1->Exited += gcnew System::EventHandler(this, &Map_Pak::process1_Exited);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(357, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(355, 52);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Show Result";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Map_Pak::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(1014, 586);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(126, 52);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Back";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Map_Pak::button2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Myriad Hebrew", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(9, 540);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(45, 21);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Path";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Myriad Hebrew", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(12, 574);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(85, 21);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Distance: ";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Myriad Hebrew", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(103, 574);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(33, 21);
			this->label3->TabIndex = 4;
			this->label3->Text = L"val";
			// 
			// Map_Pak
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1152, 650);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"Map_Pak";
			this->Text = L"Map_Pak";
			this->Load += gcnew System::EventHandler(this, &Map_Pak::Map_Pak_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void process1_Exited(System::Object^  sender, System::EventArgs^  e) {

	}
	private: System::Void Map_Pak_Load(System::Object^  sender, System::EventArgs^  e) 
	{

	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

		if (!chkbx)
		{
			button1->Text = "View Map of Pakistan";
			//Pakistan_Map
			// Get a Graphics object

			Graphics^ pg = CreateGraphics();

			// Get a Pen

			Pen^ pen1 = gcnew Pen(Color::Black, 4.0);
			/// text
			pg->DrawString(L"Karachi", font1, Brushes::Red, 35, 190);
			pg->DrawString(L"Quetta", font1, Brushes::Red, 85, 80);
			pg->DrawString(L"Hedrabad", font1, Brushes::Red, 80, 275);
			pg->DrawString(L"Sukker", font1, Brushes::Red, 250, 270);

			pg->DrawString(L"Lahore", font1, Brushes::Red, 450, 190);
			pg->DrawString(L"Multan", font1, Brushes::Red, 365, 310);
			pg->DrawString(L"Rawalpindi", font1, Brushes::Red, 460, 410);
			pg->DrawString(L"Murree", font1, Brushes::Red, 720, 380);

			pg->DrawString(L"Islamabad", font1, Brushes::Red, 520, 300);
			pg->DrawString(L"Attock", font1, Brushes::Red, 530, 235);
			pg->DrawString(L"peshawar", font1, Brushes::Red, 660, 180);
			pg->DrawString(L"Gilgit", font1, Brushes::Red, 750, 25);

			//adding distance
			pg->DrawString(L"686km", font2, Brushes::Blue, 15, 150);
			pg->DrawString(L"165km", font2, Brushes::Blue, 15, 235);
			pg->DrawString(L"474km", font2, Brushes::Blue, 165, 270);
			pg->DrawString(L"739km", font2, Brushes::Blue, 95, 185);
			pg->DrawString(L"397km", font2, Brushes::Blue, 190, 180);
			pg->DrawString(L"934km", font2, Brushes::Blue, 280, 140);

			pg->DrawString(L"784km", font2, Brushes::Blue, 350, 235);
			pg->DrawString(L"470km", font2, Brushes::Blue, 315, 285);
			pg->DrawString(L"349km", font2, Brushes::Blue, 425, 255);
			pg->DrawString(L"? km", font2, Brushes::Blue, 455, 305);
			pg->DrawString(L"536km", font2, Brushes::Blue, 400, 360);
			pg->DrawString(L"70km", font2, Brushes::Blue, 590, 385);

			pg->DrawString(L"23km", font2, Brushes::Blue, 485, 355);
			pg->DrawString(L"56km", font2, Brushes::Blue, 615, 325);
			pg->DrawString(L"184km", font2, Brushes::Blue, 580, 245);
			pg->DrawString(L"236km", font2, Brushes::Blue, 695, 275);
			pg->DrawString(L"25km", font2, Brushes::Blue, 525, 260);
			pg->DrawString(L"385km", font2, Brushes::Blue, 480, 245);

			pg->DrawString(L"420km", font2, Brushes::Blue, 490, 200);
			pg->DrawString(L"90km", font2, Brushes::Blue, 590, 180);
			pg->DrawString(L"575km", font2, Brushes::Blue, 700, 102);

			// Draw a line

			pg->DrawLine(pen1, 100, 100, 30, 200);
			pg->DrawLine(pen1, 100, 100, 80, 270);
			pg->DrawLine(pen1, 30, 200, 80, 270);
			pg->DrawLine(pen1, 80, 270, 250, 260);
			pg->DrawLine(pen1, 250, 260, 450, 210);
			pg->DrawLine(pen1, 100, 100, 450, 210);
			pg->DrawLine(pen1, 100, 100, 250, 260);
			pg->DrawLine(pen1, 250, 260, 400, 300);
			pg->DrawLine(pen1, 400, 300, 450, 210);
			pg->DrawLine(pen1, 400, 300, 460, 400);
			pg->DrawLine(pen1, 460, 400, 510, 310);
			pg->DrawLine(pen1, 460, 400, 720, 370);
			pg->DrawLine(pen1, 450, 210, 510, 310);
			pg->DrawLine(pen1, 400, 300, 510, 310);
			pg->DrawLine(pen1, 510, 310, 720, 370);
			pg->DrawLine(pen1, 720, 370, 650, 180);
			pg->DrawLine(pen1, 650, 180, 530, 230);
			pg->DrawLine(pen1, 450, 210, 530, 230);
			pg->DrawLine(pen1, 530, 230, 510, 310);
			pg->DrawLine(pen1, 650, 180, 510, 310);
			pg->DrawLine(pen1, 650, 180, 750, 20);
			SolidBrush^ sb3 = gcnew SolidBrush(Color::Black);

			pg->FillEllipse(sb3, 25, 192, 12, 12);
			pg->FillEllipse(sb3, 95, 95, 12, 12);
			pg->FillEllipse(sb3, 75, 265, 12, 12);
			pg->FillEllipse(sb3, 245, 255, 12, 12);
			pg->FillEllipse(sb3, 395, 295, 12, 12);
			pg->FillEllipse(sb3, 455, 395, 12, 12);
			pg->FillEllipse(sb3, 445, 205, 12, 12);
			pg->FillEllipse(sb3, 525, 225, 12, 12);
			pg->FillEllipse(sb3, 645, 175, 12, 12);
			pg->FillEllipse(sb3, 505, 305, 12, 12);
			pg->FillEllipse(sb3, 715, 365, 12, 12);
			pg->FillEllipse(sb3, 745, 15, 12, 12);


			// Dispose of the Graphics object

			delete pg;

		}
		else if (chkbx)
		{
			if (Map == "Karachi")
			{
				button1->Text = "View Map of Karachi";
				//Karachi_Map
				Graphics^ pg = CreateGraphics();

				Pen^ pen1 = gcnew Pen(Color::Black, 4.0);

				// Draw a line

				pg->DrawLine(pen1, 100, 100, 150, 200);
				pg->DrawLine(pen1, 150, 200, 100, 300);
				pg->DrawLine(pen1, 100, 300, 200, 350);
				pg->DrawLine(pen1, 200, 350, 500, 350);
				pg->DrawLine(pen1, 200, 350, 350, 270);
				pg->DrawLine(pen1, 350, 270, 150, 200);
				pg->DrawLine(pen1, 500, 350, 600, 300);
				pg->DrawLine(pen1, 600, 300, 500, 200);
				pg->DrawLine(pen1, 500, 200, 350, 270);
				pg->DrawLine(pen1, 500, 200, 650, 200);
				pg->DrawLine(pen1, 650, 200, 580, 100);
				pg->DrawLine(pen1, 580, 100, 500, 200);
				pg->DrawLine(pen1, 500, 200, 400, 150);
				pg->DrawLine(pen1, 400, 150, 350, 270);
				pg->DrawLine(pen1, 580, 100, 400, 70);
				pg->DrawLine(pen1, 400, 70, 250, 120);
				pg->DrawLine(pen1, 250, 120, 100, 100);
				////text at vertcies
				pg->DrawString(L"Clifton", font1, Brushes::Red, 90, 85);
				pg->DrawString(L"Gulshan Iqbal", font1, Brushes::Red, 250, 120);
				pg->DrawString(L"Gulistan johar", font1, Brushes::Red, 400, 55);
				pg->DrawString(L"Cantt", font1, Brushes::Red, 575, 85);
				pg->DrawString(L"Bahadurabad", font1, Brushes::Red, 650, 200);
				pg->DrawString(L"Teen Talwar", font1, Brushes::Red, 510, 200);
				pg->DrawString(L"Laal Qilla", font1, Brushes::Red, 600, 300);
				pg->DrawString(L"Defence", font1, Brushes::Red, 500, 350);
				pg->DrawString(L"N.I.P.A", font1, Brushes::Red, 200, 355);
				pg->DrawString(L"Sea view", font1, Brushes::Red, 350, 270);
				pg->DrawString(L"Tariq Road", font1, Brushes::Red, 410, 140);
				pg->DrawString(L"Sohrab Goat", font1, Brushes::Red, 105, 290);
				pg->DrawString(L"ISPH Road", font1, Brushes::Red, 150, 185);


				/// The distance between 2 cities
				pg->DrawString(L"1", font2, Brushes::Blue, 175, 110);
				pg->DrawString(L"4", font2, Brushes::Blue, 325, 95);
				pg->DrawString(L"6", font2, Brushes::Blue, 490, 85);
				pg->DrawString(L"4", font2, Brushes::Blue, 630, 140);
				pg->DrawString(L"3", font2, Brushes::Blue, 550, 135);
				pg->DrawString(L"8", font2, Brushes::Blue, 580, 175);
				pg->DrawString(L"5", font2, Brushes::Blue, 430, 170);
				pg->DrawString(L"7", font2, Brushes::Blue, 540, 250);
				pg->DrawString(L"1", font2, Brushes::Blue, 425, 235);
				pg->DrawString(L"2", font2, Brushes::Blue, 375, 210);
				pg->DrawString(L"2", font2, Brushes::Blue, 550, 325);
				pg->DrawString(L"3", font2, Brushes::Blue, 350, 350);
				pg->DrawString(L"4", font2, Brushes::Blue, 275, 310);
				pg->DrawString(L"7", font2, Brushes::Blue, 140, 325);
				pg->DrawString(L"5", font2, Brushes::Blue, 125, 250);
				pg->DrawString(L"9", font2, Brushes::Blue, 240, 235);
				pg->DrawString(L"5", font2, Brushes::Blue, 135, 150);

				/// drawing a spots
				SolidBrush^ sb3 = gcnew SolidBrush(Color::Black);

				pg->FillEllipse(sb3, 96, 96, 12, 12);
				pg->FillEllipse(sb3, 245, 115, 12, 12);
				pg->FillEllipse(sb3, 395, 65, 12, 12);
				pg->FillEllipse(sb3, 575, 95, 12, 12);
				pg->FillEllipse(sb3, 640, 192, 12, 12);
				pg->FillEllipse(sb3, 495, 195, 12, 12);
				pg->FillEllipse(sb3, 395, 145, 12, 12);
				pg->FillEllipse(sb3, 345, 262, 12, 12);
				pg->FillEllipse(sb3, 595, 292, 12, 12);
				pg->FillEllipse(sb3, 495, 342, 12, 12);
				pg->FillEllipse(sb3, 195, 345, 12, 12);
				pg->FillEllipse(sb3, 95, 295, 12, 12);
				pg->FillEllipse(sb3, 145, 195, 12, 12);
				// Dispose of the Graphics object

				delete pg;
			}
			else if (Map == "Multan")
			{
				button1->Text = "View Map of Multan";
				//Multan_Map
				// Get a Graphics object

				Graphics^ pg = CreateGraphics();

				// Get a Pen

				Pen^ pen1 = gcnew Pen(Color::Black, 4.0);

				// Draw a line

				pg->DrawLine(pen1, 100, 100, 30, 200);
				pg->DrawLine(pen1, 100, 100, 500, 100);

				pg->DrawLine(pen1, 500, 100, 600, 200);
				pg->DrawLine(pen1, 600, 200, 500, 300);
				pg->DrawLine(pen1, 500, 300, 100, 100);

				pg->DrawLine(pen1, 500, 300, 100, 300);
				pg->DrawLine(pen1, 100, 300, 30, 200);
				pg->DrawLine(pen1, 100, 300, 500, 100);


				// adding text

				pg->DrawString(L"Gulgasht", font1, Brushes::Red, 40, 190);
				pg->DrawString(L"Canttonment", font1, Brushes::Red, 96, 80);
				pg->DrawString(L"HPC-Colony", font1, Brushes::Red, 500, 80);
				pg->DrawString(L"Saddar", font1, Brushes::Red, 600, 205);
				pg->DrawString(L"Dera-Adda", font1, Brushes::Red, 500, 305);
				pg->DrawString(L"Gulshan", font1, Brushes::Red, 100, 305);


				//ading distance
				pg->DrawString(L"4", font2, Brushes::Blue, 65, 150);
				pg->DrawString(L"1", font2, Brushes::Blue, 300, 100);
				pg->DrawString(L"2", font2, Brushes::Blue, 550, 130);
				pg->DrawString(L"5", font2, Brushes::Blue, 500, 250);
				pg->DrawString(L"7", font2, Brushes::Blue, 300, 300);
				pg->DrawString(L"3", font2, Brushes::Blue, 65, 230);



				/// drawing a spots
				SolidBrush^ sb3 = gcnew SolidBrush(Color::Black);

				pg->FillEllipse(sb3, 25, 192, 12, 12);
				pg->FillEllipse(sb3, 95, 95, 12, 12);
				pg->FillEllipse(sb3, 495, 95, 12, 12);
				pg->FillEllipse(sb3, 595, 195, 12, 12);
				pg->FillEllipse(sb3, 495, 295, 12, 12);
				pg->FillEllipse(sb3, 95, 295, 12, 12);
				// Dispose of the Graphics object

				delete pg;

			}
			else
			{
				MessageBox::Show("City Map is Not Available!");
			}
		}




	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		Map_Pak::Hide();		
		obj->Show();


	}
};
}
