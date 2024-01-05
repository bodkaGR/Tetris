#include "TetrisMenu.h"

void Tetris1::TetrisMenu::InitializeComponent(void)
{
	System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(TetrisMenu::typeid));
	this->button_Easy = (gcnew System::Windows::Forms::Button());
	this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
	this->button1_Hard = (gcnew System::Windows::Forms::Button());
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
	this->SuspendLayout();
	// 
	// button_Easy
	// 
	this->button_Easy->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(204)));
	this->button_Easy->Location = System::Drawing::Point(194, 392);
	this->button_Easy->Name = L"button_Easy";
	this->button_Easy->Size = System::Drawing::Size(188, 75);
	this->button_Easy->TabIndex = 0;
	this->button_Easy->Text = L"Play";
	this->button_Easy->UseVisualStyleBackColor = true;
	this->button_Easy->Click += gcnew System::EventHandler(this, &TetrisMenu::button1_Easy_Click);
	// 
	// pictureBox1
	// 
	this->pictureBox1->Location = System::Drawing::Point(0, 0);
	this->pictureBox1->Name = L"pictureBox1";
	this->pictureBox1->Size = System::Drawing::Size(586, 656);
	this->pictureBox1->TabIndex = 1;
	this->pictureBox1->TabStop = false;
	this->pictureBox1->Image = Image::FromFile(imagePath);
	// 
	// button1_Hard
	// 
	this->button1_Hard->BackColor = System::Drawing::Color::Transparent;
	this->button1_Hard->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(204)));
	this->button1_Hard->Location = System::Drawing::Point(194, 499);
	this->button1_Hard->Name = L"button1_Hard";
	this->button1_Hard->Size = System::Drawing::Size(188, 75);
	this->button1_Hard->TabIndex = 2;
	this->button1_Hard->Text = L"Hard Level";
	this->button1_Hard->UseVisualStyleBackColor = false;
	this->button1_Hard->Click += gcnew System::EventHandler(this, &TetrisMenu::button1_Hard_Click_1);
	// 
	// TetrisMenu
	// 
	this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
	this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
	this->AutoSize = true;
	this->BackColor = System::Drawing::Color::DeepSkyBlue;
	this->ClientSize = System::Drawing::Size(582, 653);
	this->Controls->Add(this->button1_Hard);
	this->Controls->Add(this->button_Easy);
	this->Controls->Add(this->pictureBox1);
	this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
	this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
	this->MaximizeBox = false;
	this->Name = L"TetrisMenu";
	this->Text = L"TetrisMenu";
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
	this->ResumeLayout(false);
}

System::Void Tetris1::TetrisMenu::button1_Easy_Click(System::Object^ sender, System::EventArgs^ e) {
	choiceLevel = true;
	game = gcnew Tetris(choiceLevel);
	game->Show();
	this->Hide();
}

System::Void Tetris1::TetrisMenu::button1_Hard_Click_1(System::Object^ sender, System::EventArgs^ e) {
	choiceLevel = false;
	game = gcnew Tetris(choiceLevel);
	game->Show();
	this->Hide();
}

Tetris1::TetrisMenu::TetrisMenu(void) {
	InitializeComponent();
}

Tetris1::TetrisMenu::~TetrisMenu()
{
	if (components)
	{
		delete components;
	}
}