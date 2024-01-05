#include "TetrisMenu.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]

int main(array<String^>^ args) {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	Tetris1::TetrisMenu form;
	Application::Run(% form);
	return 0;
}