#pragma once
#include "Declare.h"
#include "Shape.h"

namespace Tetris1 {

	using namespace declare;

	public ref class Tetris : public System::Windows::Forms::Form {
	private:
		int size;
		int linesRemoved;
		int score;
		int Interval;
		bool isStop;
		bool isKeyPressed = false;
		bool isGameOver;
		
		bool choiceLevel;
		
		Shape^ currentShape;
		array<int, 2>^ map = gcnew array<int, 2>(20, 10);
		System::ComponentModel::IContainer^ components;
		Windows::Forms::Label^ loseLabel;
		System::Windows::Forms::Label^ label1;
		System::Windows::Forms::Label^ label2;
		System::Windows::Forms::Label^ labelGameOver;
		System::Windows::Forms::Button^ button1_Restart;

		System::Windows::Forms::Timer^ timer1;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void);
#pragma endregion

		Void button1_Restart_Click(System::Object^ sender, System::EventArgs^ e);
		
		System::Void update(Object^ sender, EventArgs^ e);

		void KeyFunc(Object^ sender, KeyEventArgs^ e);

		void PauseGame();

		void ResumeGame();

	public:
		Tetris(int choice);

		void Init();

		bool IsIntersects();

		void DrawGrid(Graphics^ g);

		void OnPaint(Object^ sender, PaintEventArgs^ e);

		void CheckIsGameOver(Graphics^ e);

		void Merge();

		void DrawMapFirstLevel(Graphics^ e);

		void DrawMapSecondLevel(Graphics^ e);

		void ResetArea();

		bool Collide();

		bool CollideHor(int dir);

		void SliceMap();

		void ShowNextShapeFirstLevel(Graphics^ g);

		void ShowNextShapeSecondLevel(Graphics^ g);

	protected:
		~Tetris();
	};
}
