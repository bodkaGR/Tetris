#pragma once
#include "Declare.h"
#include "Tetris.h"

namespace Tetris1 {

	public ref class TetrisMenu : public System::Windows::Forms::Form {
	private:
		System::Windows::Forms::Button^ button_Easy;
		System::Windows::Forms::Button^ button1_Hard;
		System::ComponentModel::Container ^components;
		System::Windows::Forms::PictureBox^ pictureBox1;
		Tetris^ game;
		String^ imagePath = "D:\\Programing\\Tetris_1\\image.jpg";

		bool choiceLevel;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void);

		System::Void button1_Easy_Click(System::Object^ sender, System::EventArgs^ e);

		System::Void button1_Hard_Click_1(System::Object^ sender, System::EventArgs^ e);

	public:
		TetrisMenu(void);

	protected:
		~TetrisMenu();

#pragma endregion
	};
}
