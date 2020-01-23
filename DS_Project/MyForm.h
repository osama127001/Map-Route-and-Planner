#pragma once

//To convert std::string to Martial
//System::String^ X = gcnew String(s.c_str());

//To Convert Marshal To std::string
//include<msclr\marshal_cppstd.h>
//msclr::interop::marshal_context mystring;
//std::string myname = mystring.marshal_as<std::string>(TextBox1->Text);

#include "Graph.h"
#include "LinkedList.h"
#include "Node.h"
#include "Map_Pak.h"

#include<string>
#include<msclr\marshal_cppstd.h>
#include<atlstr.h>
#include<conio.h>

namespace DSProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			textBox3->Enabled = false;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;


	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;

	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  MAP;


	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  textBox4;







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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->MAP = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(111, 484);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(356, 50);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Find Path!";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Palatino Linotype", 9, System::Drawing::FontStyle::Bold));
			this->label1->Location = System::Drawing::Point(107, 310);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(58, 21);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Source";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Palatino Linotype", 9, System::Drawing::FontStyle::Bold));
			this->label2->Location = System::Drawing::Point(106, 438);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(92, 21);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Destination";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(203, 309);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(264, 22);
			this->textBox1->TabIndex = 6;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(204, 437);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(263, 22);
			this->textBox2->TabIndex = 7;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(37, 572);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(45, 17);
			this->label3->TabIndex = 8;
			this->label3->Text = L"PATH";
			// 
			// MAP
			// 
			this->MAP->AutoSize = true;
			this->MAP->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->MAP->Font = (gcnew System::Drawing::Font(L"Palatino Linotype", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->MAP->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->MAP->Location = System::Drawing::Point(237, 34);
			this->MAP->Name = L"MAP";
			this->MAP->Size = System::Drawing::Size(456, 57);
			this->MAP->TabIndex = 9;
			this->MAP->Text = L"Map Route and Planner";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(203, 252);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(264, 22);
			this->textBox3->TabIndex = 11;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Palatino Linotype", 9, System::Drawing::FontStyle::Bold));
			this->label4->Location = System::Drawing::Point(107, 253);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(82, 21);
			this->label4->TabIndex = 12;
			this->label4->Text = L"Enter City";
			this->label4->Click += gcnew System::EventHandler(this, &MyForm::label4_Click);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Font = (gcnew System::Drawing::Font(L"Palatino Linotype", 9, System::Drawing::FontStyle::Bold));
			this->checkBox1->Location = System::Drawing::Point(183, 178);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(220, 25);
			this->checkBox1->TabIndex = 13;
			this->checkBox1->Text = L"Inter-city Path Calculation";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->Column1,
					this->Column2
			});
			this->dataGridView1->Location = System::Drawing::Point(572, 188);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(297, 380);
			this->dataGridView1->TabIndex = 14;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellContentClick);
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Source";
			this->Column1->Name = L"Column1";
			this->Column1->ReadOnly = true;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Destinations";
			this->Column2->Name = L"Column2";
			this->Column2->ReadOnly = true;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(572, 138);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(297, 44);
			this->button2->TabIndex = 16;
			this->button2->Text = L"Give Suggestions";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Palatino Linotype", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(107, 372);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(73, 21);
			this->label5->TabIndex = 18;
			this->label5->Text = L"Through";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(204, 371);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(263, 22);
			this->textBox4->TabIndex = 17;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(933, 598);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->MAP);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
	{
		try
		{
			if (checkBox1->Checked == false && (textBox4->Text == "" || textBox4->Text == " "))
			{
				String^ AA = gcnew String(" ");
				std::string CityNames[12] = { "Karachi", "Islamabad", "Gilgit", "Lahore", "Rawalpindi", "Multan", "Sukker", "Hyderabad", "Quetta", "Murree", "Peshawar", "Attock" };
				msclr::interop::marshal_context Context;
				std::string C_Name_1 = Context.marshal_as<std::string>(textBox1->Text);
				std::string C_Name_2 = Context.marshal_as<std::string>(textBox2->Text);

				Graph G1;
				if (textBox1->Text == textBox2->Text)
				{
					textBox1->Text = "";
					textBox2->Text = " ";
					textBox1->Focus();
					MessageBox::Show("Inputs are same, Please Enter Different values");
					return; //asks output again.
				}


				LinkedList Shortest_Path;
				std::string F = "D:\\OKHAN Data\\EME\\Semester 4\\Data Structures\\Project\\test.txt";
				G1.Read_andCreateGraph(F);
				LinkedList Paths;

				Paths = G1.TjKSTRA_ALGO_ForShortestPath(G1.Search_andReturn(C_Name_1), G1.Search_andReturn(C_Name_2)); //define source with a proper value, // Paths Does not contain destination sometimes.
				Shortest_Path = G1.SHORTEST_PATH(G1.Search_andReturn(C_Name_1), G1.Search_andReturn(C_Name_2), Paths);

				Node *temp = Shortest_Path.GetHead();
				AA = AA + "Path ";
				while (temp != NULL)
				{
					if (temp == Shortest_Path.GetHead()) { AA = AA + " = "; }
					else { AA = AA + " -> "; }
					String^ A = gcnew String(temp->Data->City_Name.c_str());
					AA = AA + A;
					temp = temp->Next;
					label3->Text = gcnew String(AA);					
				}
				Graph_Node *Destination = G1.Search_andReturn(C_Name_2);
				float Min_Dist = Destination->Shortest_Distance;

				Map_Pak^ obj = gcnew Map_Pak(this, label3->Text, Min_Dist, checkBox1->Checked, textBox3->Text);
				obj->Show();
				MyForm::Hide();

				return;
			}
			else if (checkBox1->Checked == false && (textBox4->Text != "" || textBox4->Text != " "))
			{
				String^ AA = gcnew String(" ");
				std::string CityNames[12] = { "Karachi", "Islamabad", "Gilgit", "Lahore", "Rawalpindi", "Multan", "Sukker", "Hyderabad", "Quetta", "Murree", "Peshawar", "Attock" };
				msclr::interop::marshal_context Context;
				std::string C_Name_1 = Context.marshal_as<std::string>(textBox1->Text);
				std::string C_Name_2 = Context.marshal_as<std::string>(textBox2->Text);
				std::string C_Name_3 = Context.marshal_as<std::string>(textBox4->Text);



				Graph G1;
				if (textBox1->Text == textBox2->Text)
				{
					textBox1->Text = "";
					textBox2->Text = " ";
					textBox1->Focus();
					MessageBox::Show("Inputs are same, Please Enter Different values");
					return; //asks output again.
				}

				LinkedList Shortest_Path;
				std::string F = "D:\\OKHAN Data\\EME\\Semester 4\\Data Structures\\Project\\test.txt";
				G1.Read_andCreateGraph(F);
				LinkedList Paths;

				Paths = G1.TjKSTRA_ALGO_ForShortestPath(G1.Search_andReturn(C_Name_1), G1.Search_andReturn(C_Name_3)); //define source with a proper value, // Paths Does not contain destination sometimes.
				Shortest_Path = G1.SHORTEST_PATH(G1.Search_andReturn(C_Name_1), G1.Search_andReturn(C_Name_3), Paths);

				Graph G2;
				G2.Read_andCreateGraph(F);

				LinkedList Paths2 = G2.TjKSTRA_ALGO_ForShortestPath(G2.Search_andReturn(C_Name_3), G2.Search_andReturn(C_Name_2)); //define source with a proper value, // Paths Does not contain destination sometimes.
				LinkedList Shortest_Path_2 = G2.SHORTEST_PATH(G2.Search_andReturn(C_Name_3), G2.Search_andReturn(C_Name_2), Paths2);


				//now link the two lists
				Shortest_Path_2.Delete_Start();
				Node *temp = Shortest_Path_2.GetHead();
				while (temp != NULL)
				{
					Shortest_Path.Insert_End(temp->Data);
					temp = temp->Next;
				}

				temp = Shortest_Path.GetHead();
				AA = AA + "Path ";
				while (temp != NULL)
				{
					if (temp == Shortest_Path.GetHead()) { AA = AA + " = "; }
					else { AA = AA + " -> "; }
					String^ A = gcnew String(temp->Data->City_Name.c_str());
					AA = AA + A;
					temp = temp->Next;
					label3->Text = gcnew String(AA);
				}
				Graph_Node *Through = G1.Search_andReturn(C_Name_3);
				float Min_Dist = Through->Shortest_Distance;
				Graph_Node *Destination = G2.Search_andReturn(C_Name_2);
				Min_Dist = Min_Dist + Destination->Shortest_Distance;

				Map_Pak^ obj = gcnew Map_Pak(this, label3->Text, Min_Dist, checkBox1->Checked, textBox3->Text);
				obj->Show();
				MyForm::Hide();

				return;
			}
			else if (checkBox1->Checked == true)
			{
				if (textBox3->Text == "" || textBox3->Text == " ")
				{
					MessageBox::Show("Please Enter a City for Inter-city calculation.!");
				}
				else
				{
					/////////////////////////////////////////--FORCITIES--///////////////////////////////////////
					if (textBox3->Text == "Karachi")
					{
						if (textBox4->Text->Length == 0)
						{
							String^ AA = gcnew String(" ");
							std::string CityNames[12] = { "Karachi", "Islamabad", "Gilgit", "Lahore", "Rawalpindi", "Multan", "Sukker", "Hyderabad", "Quetta", "Murree", "Peshawar", "Attock" };
							msclr::interop::marshal_context Context;
							std::string C_Name_1 = Context.marshal_as<std::string>(textBox1->Text);
							std::string C_Name_2 = Context.marshal_as<std::string>(textBox2->Text);

							Graph G1;
							if (textBox1->Text == textBox2->Text)
							{
								textBox1->Text = "";
								textBox2->Text = " ";
								textBox1->Focus();
								MessageBox::Show("Inputs are same, Please Enter Different values");
								return; //asks output again.
							}


							LinkedList Shortest_Path;
							std::string F = "D:\\OKHAN Data\\EME\\Semester 4\\Data Structures\\Project\\test3.txt";
							G1.Read_andCreateGraph(F);
							LinkedList Paths;

							Paths = G1.TjKSTRA_ALGO_ForShortestPath(G1.Search_andReturn(C_Name_1), G1.Search_andReturn(C_Name_2)); //define source with a proper value, // Paths Does not contain destination sometimes.
							Shortest_Path = G1.SHORTEST_PATH(G1.Search_andReturn(C_Name_1), G1.Search_andReturn(C_Name_2), Paths);

							Node *temp = Shortest_Path.GetHead();
							AA = AA + "Path ";
							while (temp != NULL)
							{
								if (temp == Shortest_Path.GetHead()) { AA = AA + " = "; }
								else { AA = AA + " -> "; }
								String^ A = gcnew String(temp->Data->City_Name.c_str());
								AA = AA + A;
								temp = temp->Next;
								label3->Text = gcnew String(AA);
							}
							Graph_Node *Destination = G1.Search_andReturn(C_Name_2);
							float Min_Dist = Destination->Shortest_Distance;

							Map_Pak^ obj = gcnew Map_Pak(this, label3->Text, Min_Dist, checkBox1->Checked, textBox3->Text);
							obj->Show();
							MyForm::Hide();

							return;

						}
						else
						{
							String^ AA = gcnew String(" ");
							std::string CityNames[12] = { "Karachi", "Islamabad", "Gilgit", "Lahore", "Rawalpindi", "Multan", "Sukker", "Hyderabad", "Quetta", "Murree", "Peshawar", "Attock" };
							msclr::interop::marshal_context Context;
							std::string C_Name_1 = Context.marshal_as<std::string>(textBox1->Text);
							std::string C_Name_2 = Context.marshal_as<std::string>(textBox2->Text);
							std::string C_Name_3 = Context.marshal_as<std::string>(textBox4->Text);



							Graph G1;
							if (textBox1->Text == textBox2->Text)
							{
								textBox1->Text = "";
								textBox2->Text = " ";
								textBox1->Focus();
								MessageBox::Show("Inputs are same, Please Enter Different values");
								return; //asks output again.
							}

							LinkedList Shortest_Path;
							std::string F = "D:\\OKHAN Data\\EME\\Semester 4\\Data Structures\\Project\\test3.txt";
							G1.Read_andCreateGraph(F);
							LinkedList Paths;

							Paths = G1.TjKSTRA_ALGO_ForShortestPath(G1.Search_andReturn(C_Name_1), G1.Search_andReturn(C_Name_3)); //define source with a proper value, // Paths Does not contain destination sometimes.
							Shortest_Path = G1.SHORTEST_PATH(G1.Search_andReturn(C_Name_1), G1.Search_andReturn(C_Name_3), Paths);

							Graph G2;
							G2.Read_andCreateGraph(F);

							LinkedList Paths2 = G2.TjKSTRA_ALGO_ForShortestPath(G2.Search_andReturn(C_Name_3), G2.Search_andReturn(C_Name_2)); //define source with a proper value, // Paths Does not contain destination sometimes.
							LinkedList Shortest_Path_2 = G2.SHORTEST_PATH(G2.Search_andReturn(C_Name_3), G2.Search_andReturn(C_Name_2), Paths2);


							//now link the two lists
							Shortest_Path_2.Delete_Start();
							Node *temp = Shortest_Path_2.GetHead();
							while (temp != NULL)
							{
								Shortest_Path.Insert_End(temp->Data);
								temp = temp->Next;
							}

							temp = Shortest_Path.GetHead();
							AA = AA + "Path ";
							while (temp != NULL)
							{
								if (temp == Shortest_Path.GetHead()) { AA = AA + " = "; }
								else { AA = AA + " -> "; }
								String^ A = gcnew String(temp->Data->City_Name.c_str());
								AA = AA + A;
								temp = temp->Next;
								label3->Text = gcnew String(AA);
							}
							Graph_Node *Through = G1.Search_andReturn(C_Name_3);
							float Min_Dist = Through->Shortest_Distance;
							Graph_Node *Destination = G2.Search_andReturn(C_Name_2);
							Min_Dist = Min_Dist + Destination->Shortest_Distance;

							Map_Pak^ obj = gcnew Map_Pak(this, label3->Text, Min_Dist, checkBox1->Checked, textBox3->Text);
							obj->Show();
							MyForm::Hide();

							return;

						}
					}
					if (textBox3->Text == "Multan")
					{
						if (textBox4->Text->Length == 0)
						{
							String^ AA = gcnew String(" ");
							std::string CityNames[12] = { "Karachi", "Islamabad", "Gilgit", "Lahore", "Rawalpindi", "Multan", "Sukker", "Hyderabad", "Quetta", "Murree", "Peshawar", "Attock" };
							msclr::interop::marshal_context Context;
							std::string C_Name_1 = Context.marshal_as<std::string>(textBox1->Text);
							std::string C_Name_2 = Context.marshal_as<std::string>(textBox2->Text);

							Graph G1;
							if (textBox1->Text == textBox2->Text)
							{
								textBox1->Text = "";
								textBox2->Text = " ";
								textBox1->Focus();
								MessageBox::Show("Inputs are same, Please Enter Different values");
								return; //asks output again.
							}


							LinkedList Shortest_Path;
							std::string F = "D:\\OKHAN Data\\EME\\Semester 4\\Data Structures\\Project\\test2.txt";
							G1.Read_andCreateGraph(F);
							LinkedList Paths;

							Paths = G1.TjKSTRA_ALGO_ForShortestPath(G1.Search_andReturn(C_Name_1), G1.Search_andReturn(C_Name_2)); //define source with a proper value, // Paths Does not contain destination sometimes.
							Shortest_Path = G1.SHORTEST_PATH(G1.Search_andReturn(C_Name_1), G1.Search_andReturn(C_Name_2), Paths);

							Node *temp = Shortest_Path.GetHead();
							AA = AA + "Path ";
							while (temp != NULL)
							{
								if (temp == Shortest_Path.GetHead()) { AA = AA + " = "; }
								else { AA = AA + " -> "; }
								String^ A = gcnew String(temp->Data->City_Name.c_str());
								AA = AA + A;
								temp = temp->Next;
								label3->Text = gcnew String(AA);
							}
							Graph_Node *Destination = G1.Search_andReturn(C_Name_2);
							float Min_Dist = Destination->Shortest_Distance;

							Map_Pak^ obj = gcnew Map_Pak(this, label3->Text, Min_Dist, checkBox1->Checked, textBox3->Text);
							obj->Show();
							MyForm::Hide();

							return;

						}
						else
						{
							String^ AA = gcnew String(" ");
							std::string CityNames[12] = { "Karachi", "Islamabad", "Gilgit", "Lahore", "Rawalpindi", "Multan", "Sukker", "Hyderabad", "Quetta", "Murree", "Peshawar", "Attock" };
							msclr::interop::marshal_context Context;
							std::string C_Name_1 = Context.marshal_as<std::string>(textBox1->Text);
							std::string C_Name_2 = Context.marshal_as<std::string>(textBox2->Text);
							std::string C_Name_3 = Context.marshal_as<std::string>(textBox4->Text);



							Graph G1;
							if (textBox1->Text == textBox2->Text)
							{
								textBox1->Text = "";
								textBox2->Text = " ";
								textBox1->Focus();
								MessageBox::Show("Inputs are same, Please Enter Different values");
								return; //asks output again.
							}

							LinkedList Shortest_Path;
							std::string F = "D:\\OKHAN Data\\EME\\Semester 4\\Data Structures\\Project\\test2.txt";
							G1.Read_andCreateGraph(F);
							LinkedList Paths;

							Paths = G1.TjKSTRA_ALGO_ForShortestPath(G1.Search_andReturn(C_Name_1), G1.Search_andReturn(C_Name_3)); //define source with a proper value, // Paths Does not contain destination sometimes.
							Shortest_Path = G1.SHORTEST_PATH(G1.Search_andReturn(C_Name_1), G1.Search_andReturn(C_Name_3), Paths);

							Graph G2;
							G2.Read_andCreateGraph(F);

							LinkedList Paths2 = G2.TjKSTRA_ALGO_ForShortestPath(G2.Search_andReturn(C_Name_3), G2.Search_andReturn(C_Name_2)); //define source with a proper value, // Paths Does not contain destination sometimes.
							LinkedList Shortest_Path_2 = G2.SHORTEST_PATH(G2.Search_andReturn(C_Name_3), G2.Search_andReturn(C_Name_2), Paths2);


							//now link the two lists
							Shortest_Path_2.Delete_Start();
							Node *temp = Shortest_Path_2.GetHead();
							while (temp != NULL)
							{
								Shortest_Path.Insert_End(temp->Data);
								temp = temp->Next;
							}

							temp = Shortest_Path.GetHead();
							AA = AA + "Path ";
							while (temp != NULL)
							{
								if (temp == Shortest_Path.GetHead()) { AA = AA + " = "; }
								else { AA = AA + " -> "; }
								String^ A = gcnew String(temp->Data->City_Name.c_str());
								AA = AA + A;
								temp = temp->Next;
								label3->Text = gcnew String(AA);
							}
							Graph_Node *Through = G1.Search_andReturn(C_Name_3);
							float Min_Dist = Through->Shortest_Distance;
							Graph_Node *Destination = G2.Search_andReturn(C_Name_2);
							Min_Dist = Min_Dist + Destination->Shortest_Distance;

							Map_Pak^ obj = gcnew Map_Pak(this, label3->Text, Min_Dist, checkBox1->Checked, textBox3->Text);
							obj->Show();
							MyForm::Hide();

							return;

						}

					}
					else 
					{
						MessageBox::Show("City Graph is Not available.");
					}
				}				
			}
			else { MessageBox::Show("Please Uncheck the (Inter-city Path Calculation) Check Box.!"); return; }
		}
		catch (Exception^ e)
		{
			MessageBox::Show("Error: " + e->Message + ". Please Check the inputs correctly and Try again!");
			return;
		}
	}
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) 
	{

	}
private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

	if (checkBox1->Checked == false)
	{
		textBox3->Enabled = false;
		label4->Enabled = false;
	}

	if (checkBox1->Checked == true)
	{
		textBox3->Enabled = true;
		label4->Enabled = true;
	}


}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) 
{
	std::string CityNames[12] = { "Karachi", "Islamabad", "Gilgit", "Lahore", "Rawalpindi", "Multan", "Sukker", "Hyderabad", "Quetta", "Murree", "Peshawar", "Attock" };
	std::string Karachi_Names[13] = {"Clifton", "Gulshan-Iqbal", "Gulustan-Johar", "Cantt", "ISPH-Road", "Tariq-Road", "Teen-Talwar", "Bahadurabad", "Sohrab-Goat", "Sea-View", "NIPA", "Defence", "Lal-Qila"};
	std::string Multan_Names[6] = { "Saddar", "Canttonment", "Gulgasht", "Dera-Adda", "HPC-Colony", "Gulshan" };
	
	if (checkBox1->Checked == false)
	{
		dataGridView1->Rows->Clear();
		for (int i = 0; i < 12; i++)
		{
			dataGridView1->Rows->Add(gcnew String(CityNames[i].c_str()), gcnew String(CityNames[i].c_str()));
		}
	}

	else if (checkBox1->Checked == true )
	{
		if (textBox3->Text == "Multan")
		{
			dataGridView1->Rows->Clear();
			for (int i = 0; i < 6; i++)
			{
				dataGridView1->Rows->Add(gcnew String(Multan_Names[i].c_str()), gcnew String(Multan_Names[i].c_str()));
			}
		}
		else if (textBox3->Text == "Karachi")
		{
			dataGridView1->Rows->Clear();
			for (int i = 0; i < 13; i++)
			{
				dataGridView1->Rows->Add(gcnew String(Karachi_Names[i].c_str()), gcnew String(Karachi_Names[i].c_str()));
			}
		}
		else
		{
			dataGridView1->Rows->Clear();
			MessageBox::Show("City Graph Not available!.");
		}
	}
}
private: System::Void dataGridView1_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
}
private: System::Void label4_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) 
{

}
};
}
