#include "Tetris.h"

void Tetris1::Tetris::InitializeComponent(void) {
	this->components = (gcnew System::ComponentModel::Container());
	System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Tetris::typeid));
	this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
	this->label1 = (gcnew System::Windows::Forms::Label());
	this->label2 = (gcnew System::Windows::Forms::Label());
	this->button1_Restart = (gcnew System::Windows::Forms::Button());
	this->labelGameOver = (gcnew System::Windows::Forms::Label());
	this->KeyPreview = true;
	this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
	this->MaximizeBox = false;
	this->DoubleBuffered = true;
	this->SuspendLayout();
	// 
	// timer1
	// 
	this->timer1->Interval = 500;
	// 
	// label1
	// 
	this->label1->AutoSize = true;
	this->label1->BackColor = System::Drawing::Color::LightSkyBlue;
	this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(204)));
	this->label1->Location = System::Drawing::Point(372, 38);
	this->label1->Name = L"label1";
	this->label1->Size = System::Drawing::Size(95, 36);
	this->label1->TabIndex = 0;
	this->label1->Text = L"label1";
	// 
	// label2
	// 
	this->label2->AutoSize = true;
	this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(204)));
	this->label2->Location = System::Drawing::Point(372, 98);
	this->label2->Name = L"label2";
	this->label2->Size = System::Drawing::Size(95, 36);
	this->label2->TabIndex = 1;
	this->label2->Text = L"label2";
	// 
	// button1
	// 
	this->button1_Restart->CausesValidation = false;
	this->button1_Restart->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(204)));
	this->button1_Restart->Location = System::Drawing::Point(195, 415);
	this->button1_Restart->Name = L"button1";
	this->button1_Restart->Size = System::Drawing::Size(161, 68);
	this->button1_Restart->TabIndex = 2;
	this->button1_Restart->Text = L"Restart";
	this->button1_Restart->UseVisualStyleBackColor = true;
	this->button1_Restart->UseWaitCursor = true;
	this->button1_Restart->Click += gcnew System::EventHandler(this, &Tetris::button1_Restart_Click);
	// 
	// labelGameOver
	// 
	this->labelGameOver->AutoSize = true;
	this->labelGameOver->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(204)));
	this->labelGameOver->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
	this->labelGameOver->Location = System::Drawing::Point(180, 276);
	this->labelGameOver->Name = L"labelGameOver";
	this->labelGameOver->Size = System::Drawing::Size(200, 39);
	this->labelGameOver->TabIndex = 2;
	this->labelGameOver->Text = L"Game Over";
	// 
	// Tetris
	// 
	this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
	this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
	this->BackColor = System::Drawing::Color::LightSkyBlue;
	this->ClientSize = System::Drawing::Size(582, 653);
	this->Controls->Add(this->label2);
	this->Controls->Add(this->label1);
	this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
	this->Name = L"Tetris";
	this->Text = L"Tetris";
	this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Tetris::OnPaint);
	this->ResumeLayout(false);
	this->PerformLayout();
}

Void Tetris1::Tetris::button1_Restart_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Controls->Remove(labelGameOver);
	this->Controls->Remove(button1_Restart);
	ResetArea();
	InitializeComponent();
	Init();
}

System::Void Tetris1::Tetris::update(Object^ sender, EventArgs^ e) {
	ResetArea();
	if (!Collide()) {
		currentShape->MoveDown();
	}
	else {
		Merge();
		SliceMap();
		timer1->Interval = Interval;

		if (!choiceLevel) {
			currentShape->ResetShapeNextLevel(3, 0);
		}
		else if (choiceLevel) {
			currentShape->ResetShape(3, 0);
		}

		if (Collide()) {
			for (int i = 0; i < 20; i++) {
				for (int j = 0; j < 10; j++) {
					map[i, j] = 0;
				}
			}
			timer1->Tick -= gcnew EventHandler(this, &Tetris::update);
			timer1->Stop();
			isGameOver = true;
		}
	}
	Merge();
	Invalidate();
}

void Tetris1::Tetris::PauseGame() {
	timer1->Stop();
}

void Tetris1::Tetris::ResumeGame() {
	timer1->Start();
}

void Tetris1::Tetris::KeyFunc(Object^ sender, KeyEventArgs^ e) {
	switch (e->KeyCode) {
	case Keys::A:
		if (!IsIntersects()) {
			ResetArea();
			currentShape->RotateShape();
			Merge();
			Invalidate();
		}
		break;
	case Keys::Down:
		timer1->Interval = 50;
		break;
	case Keys::Right:
		if (!CollideHor(1)) {
			ResetArea();
			currentShape->MoveRight();
			Merge();
			Invalidate();
		}
		break;
	case Keys::Left:
		if (!CollideHor(-1)) {
			ResetArea();
			currentShape->MoveLeft();
			Merge();
			Invalidate();
		}
		break;
	case Keys::Space:
		PauseGame();
		break;
	case Keys::X:
		ResumeGame();
		break;

	}
}

Tetris1::Tetris::Tetris(int choice) : choiceLevel(choice) {
	InitializeComponent();
	this->KeyUp += gcnew KeyEventHandler(this, &Tetris::KeyFunc);
	Init();
}

void Tetris1::Tetris::Init() {
	Interval = 500;
	size = 25;
	score = 0;
	linesRemoved = 0;
	isStop = false;
	isGameOver = false;

	if (!choiceLevel) {
		currentShape = gcnew Shape(3, 0, 2);
	}
	else if (choiceLevel) {
		currentShape = gcnew Shape(3, 0, 1);
	}

	this->timer1->Tick += gcnew EventHandler(this, &Tetris::update);

	label1->Text = "Score: " + score;
	label2->Text = "Lines: " + linesRemoved;

	linesRemoved = 0;
	timer1->Start();
	Invalidate();
}

bool Tetris1::Tetris::IsIntersects() {
	for (int i = currentShape->y; i < currentShape->y + currentShape->sizeMatrix; i++) {
		for (int j = currentShape->x; j < currentShape->x + currentShape->sizeMatrix; j++) {
			if (j >= 0 && j <= 9) {
				if (map[i, j] != 0 && currentShape->matrix[i - currentShape->y, j - currentShape->x] == 0) {
					return true;
				}
			}
		}
	}
	return false;
}

void Tetris1::Tetris::DrawGrid(Graphics^ g) {
	for (int i = 0; i <= 20; i++) {
		g->DrawLine(Pens::Black, Point(50, 50 + i * size), Point(50 + 10 * size, 50 + i * size));
	}
	for (int i = 0; i <= 10; i++) {
		g->DrawLine(Pens::Black, Point(50 + i * size, 50), Point(50 + i * size, 50 + 20 * size));
	}
}

void Tetris1::Tetris::OnPaint(Object^ sender, PaintEventArgs^ e) {
	if (isGameOver) {
		CheckIsGameOver(e->Graphics);
		this->Controls->Add(this->button1_Restart);
	}
	else {
		DrawGrid(e->Graphics);

		if (!choiceLevel) {
			DrawMapSecondLevel(e->Graphics);
			ShowNextShapeSecondLevel(e->Graphics);
		}
		else if (choiceLevel) {
			DrawMapFirstLevel(e->Graphics);
			ShowNextShapeFirstLevel(e->Graphics);
		}
	}
}

void Tetris1::Tetris::CheckIsGameOver(Graphics^ e) {
	this->BackColor = Color::Black;

	this->Controls->Add(this->labelGameOver);
	this->Controls->Remove(label1);
	this->Controls->Remove(label2);
}

void Tetris1::Tetris::Merge() {
	for (int i = currentShape->y; i < currentShape->y + currentShape->sizeMatrix; i++) {
		for (int j = currentShape->x; j < currentShape->x + currentShape->sizeMatrix; j++) {
			if (currentShape->matrix[i - currentShape->y, j - currentShape->x] != 0) {
				map[i, j] = currentShape->matrix[i - currentShape->y, j - currentShape->x];
			}
		}
	}
}

void Tetris1::Tetris::DrawMapFirstLevel(Graphics^ e) {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 10; j++) {
			if (map[i, j] == 1) {
				e->FillRectangle(Brushes::Blue, Rectangle(50 + j * (size)+1, 50 + i * (size)+1, size - 1, size - 1));
			}
			if (map[i, j] == 2) {
				e->FillRectangle(Brushes::Red, Rectangle(50 + j * (size)+1, 50 + i * (size)+1, size - 1, size - 1));
			}
			if (map[i, j] == 3) {
				e->FillRectangle(Brushes::Purple, Rectangle(50 + j * (size)+1, 50 + i * (size)+1, size - 1, size - 1));
			}
			if (map[i, j] == 4) {
				e->FillRectangle(Brushes::Cyan, Rectangle(50 + j * (size)+1, 50 + i * (size)+1, size - 1, size - 1));
			}
			if (map[i, j] == 5) {
				e->FillRectangle(Brushes::Yellow, Rectangle(50 + j * (size)+1, 50 + i * (size)+1, size - 1, size - 1));
			}
		}
	}
}

void Tetris1::Tetris::DrawMapSecondLevel(Graphics^ e) {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 10; j++) {
			if (map[i, j] == 6) {
				e->FillRectangle(Brushes::Blue, Rectangle(50 + j * (size)+1, 50 + i * (size)+1, size - 1, size - 1));
			}
			if (map[i, j] == 7) {
				e->FillRectangle(Brushes::Red, Rectangle(50 + j * (size)+1, 50 + i * (size)+1, size - 1, size - 1));
			}
			if (map[i, j] == 8) {
				e->FillRectangle(Brushes::Purple, Rectangle(50 + j * (size)+1, 50 + i * (size)+1, size - 1, size - 1));
			}
			if (map[i, j] == 9) {
				e->FillRectangle(Brushes::Cyan, Rectangle(50 + j * (size)+1, 50 + i * (size)+1, size - 1, size - 1));
			}
			if (map[i, j] == 10) {
				e->FillRectangle(Brushes::Yellow, Rectangle(50 + j * (size)+1, 50 + i * (size)+1, size - 1, size - 1));
			}
			if (map[i, j] == 11) {
				e->FillRectangle(Brushes::Blue, Rectangle(50 + j * (size)+1, 50 + i * (size)+1, size - 1, size - 1));
			}
			if (map[i, j] == 12) {
				e->FillRectangle(Brushes::Red, Rectangle(50 + j * (size)+1, 50 + i * (size)+1, size - 1, size - 1));
			}
			if (map[i, j] == 13) {
				e->FillRectangle(Brushes::Purple, Rectangle(50 + j * (size)+1, 50 + i * (size)+1, size - 1, size - 1));
			}
			if (map[i, j] == 14) {
				e->FillRectangle(Brushes::Cyan, Rectangle(50 + j * (size)+1, 50 + i * (size)+1, size - 1, size - 1));
			}
			if (map[i, j] == 15) {
				e->FillRectangle(Brushes::Yellow, Rectangle(50 + j * (size)+1, 50 + i * (size)+1, size - 1, size - 1));
			}
			if (map[i, j] == 16) {
				e->FillRectangle(Brushes::Cyan, Rectangle(50 + j * (size)+1, 50 + i * (size)+1, size - 1, size - 1));
			}
			if (map[i, j] == 17) {
				e->FillRectangle(Brushes::Yellow, Rectangle(50 + j * (size)+1, 50 + i * (size)+1, size - 1, size - 1));
			}
			if (map[i, j] == 18) {
				e->FillRectangle(Brushes::Cyan, Rectangle(50 + j * (size)+1, 50 + i * (size)+1, size - 1, size - 1));
			}
			if (map[i, j] == 19) {
				e->FillRectangle(Brushes::Yellow, Rectangle(50 + j * (size)+1, 50 + i * (size)+1, size - 1, size - 1));
			}
			if (map[i, j] == 20) {
				e->FillRectangle(Brushes::Cyan, Rectangle(50 + j * (size)+1, 50 + i * (size)+1, size - 1, size - 1));
			}
			if (map[i, j] == 21) {
				e->FillRectangle(Brushes::Yellow, Rectangle(50 + j * (size)+1, 50 + i * (size)+1, size - 1, size - 1));
			}
			if (map[i, j] == 22) {
				e->FillRectangle(Brushes::Cyan, Rectangle(50 + j * (size)+1, 50 + i * (size)+1, size - 1, size - 1));
			}
			if (map[i, j] == 23) {
				e->FillRectangle(Brushes::Yellow, Rectangle(50 + j * (size)+1, 50 + i * (size)+1, size - 1, size - 1));
			}
		}
	}
}

void Tetris1::Tetris::ResetArea() {
	for (int i = currentShape->y; i < currentShape->y + currentShape->sizeMatrix; i++) {
		for (int j = currentShape->x; j < currentShape->x + currentShape->sizeMatrix; j++) {
			if (i >= 0 && j >= 0 && i < 20 && j < 10) {
				if (currentShape->matrix[i - currentShape->y, j - currentShape->x] != 0) {
					map[i, j] = 0;
				}
			}
		}
	}
}

bool Tetris1::Tetris::Collide() {
	for (int i = currentShape->y + currentShape->sizeMatrix - 1; i >= currentShape->y; i--) {
		for (int j = currentShape->x; j < currentShape->x + currentShape->sizeMatrix; j++) {
			if (currentShape->matrix[i - currentShape->y, j - currentShape->x] != 0) {
				if (i + 1 == 20) {
					return true;
				}
				if (map[i + 1, j] != 0) {
					return true;
				}
			}
		}
	}
	return false;
}

bool Tetris1::Tetris::CollideHor(int dir) {
	for (int i = currentShape->y; i < currentShape->y + currentShape->sizeMatrix; i++) {
		for (int j = currentShape->x; j < currentShape->x + currentShape->sizeMatrix; j++) {
			if (currentShape->matrix[i - currentShape->y, j - currentShape->x] != 0) {
				if (j + 1 * dir > 9 || j + 1 * dir < 0) {
					return true;
				}
				if (map[i, j + 1 * dir] != 0) {
					if (j - currentShape->x + 1 * dir >= currentShape->sizeMatrix || j - currentShape->x + 1 * dir < 0) {
						return true;
					}
					if (currentShape->matrix[i - currentShape->y, j - currentShape->x + 1 * dir] == 0) {
						return true;
					}
				}
			}
		}
	}
	return false;
}

void Tetris1::Tetris::SliceMap() {
	int count = 0;
	int curRemovedLines = 0;
	for (int i = 0; i < 20; i++) {
		count = 0;
		for (int j = 0; j < 10; j++) {
			if (map[i, j] != 0)
				count++;
		}
		if (count == 10) {
			curRemovedLines++;
			for (int k = i; k >= 1; k--) {
				for (int o = 0; o < 10; o++) {
					map[k, o] = map[k - 1, o];
				}
			}
		}
	}


	if (curRemovedLines == 1) {
		score += 100;
	}
	else if (curRemovedLines == 2) {
		score += 300;
	}
	else if (curRemovedLines == 3) {
		score += 700;
	}
	else if (curRemovedLines == 4) {
		score += 1500;
	}
	else {
		score += 0;
	}

	linesRemoved += curRemovedLines;

	if (Interval > 100) {
		if (curRemovedLines == 1) {
			Interval -= 100;
		}
		else if (curRemovedLines == 2) {
			Interval -= 150;
		}
		else if (curRemovedLines == 3) {
			Interval -= 200;
		}
		else if (curRemovedLines == 4) {
			Interval -= 250;
		}
	}

	label1->Text = "Score: " + score;
	label2->Text = "Lines: " + linesRemoved;
}

void Tetris1::Tetris::ShowNextShapeFirstLevel(Graphics^ g) {
	for (int i = 0; i < currentShape->sizeNextMatrix; i++) {
		for (int j = 0; j < currentShape->sizeNextMatrix; j++) {
			if (currentShape->nextMatrix[i, j] == 1) {
				g->FillRectangle(Brushes::Blue, Rectangle(400 + j * (size)+1, 200 + i * (size)+1, size - 1, size - 1));
			}
			if (currentShape->nextMatrix[i, j] == 2) {
				g->FillRectangle(Brushes::Red, Rectangle(400 + j * (size)+1, 200 + i * (size)+1, size - 1, size - 1));
			}
			if (currentShape->nextMatrix[i, j] == 3) {
				g->FillRectangle(Brushes::Purple, Rectangle(400 + j * (size)+1, 200 + i * (size)+1, size - 1, size - 1));
			}
			if (currentShape->nextMatrix[i, j] == 4) {
				g->FillRectangle(Brushes::Cyan, Rectangle(400 + j * (size)+1, 200 + i * (size)+1, size - 1, size - 1));
			}
			if (currentShape->nextMatrix[i, j] == 5) {
				g->FillRectangle(Brushes::Yellow, Rectangle(400 + j * (size)+1, 200 + i * (size)+1, size - 1, size - 1));
			}
		}
	}
}

void Tetris1::Tetris::ShowNextShapeSecondLevel(Graphics^ g) {
	for (int i = 0; i < currentShape->sizeNextMatrix; i++) {
		for (int j = 0; j < currentShape->sizeNextMatrix; j++) {
			if (currentShape->nextMatrix[i, j] == 6) {
				g->FillRectangle(Brushes::Blue, Rectangle(400 + j * (size)+1, 200 + i * (size)+1, size - 1, size - 1));
			}
			if (currentShape->nextMatrix[i, j] == 7) {
				g->FillRectangle(Brushes::Red, Rectangle(400 + j * (size)+1, 200 + i * (size)+1, size - 1, size - 1));
			}
			if (currentShape->nextMatrix[i, j] == 8) {
				g->FillRectangle(Brushes::Purple, Rectangle(400 + j * (size)+1, 200 + i * (size)+1, size - 1, size - 1));
			}
			if (currentShape->nextMatrix[i, j] == 9) {
				g->FillRectangle(Brushes::Cyan, Rectangle(400 + j * (size)+1, 200 + i * (size)+1, size - 1, size - 1));
			}
			if (currentShape->nextMatrix[i, j] == 10) {
				g->FillRectangle(Brushes::Yellow, Rectangle(400 + j * (size)+1, 200 + i * (size)+1, size - 1, size - 1));
			}
			if (currentShape->nextMatrix[i, j] == 11) {
				g->FillRectangle(Brushes::Blue, Rectangle(400 + j * (size)+1, 200 + i * (size)+1, size - 1, size - 1));
			}
			if (currentShape->nextMatrix[i, j] == 12) {
				g->FillRectangle(Brushes::Red, Rectangle(400 + j * (size)+1, 200 + i * (size)+1, size - 1, size - 1));
			}
			if (currentShape->nextMatrix[i, j] == 13) {
				g->FillRectangle(Brushes::Purple, Rectangle(400 + j * (size)+1, 200 + i * (size)+1, size - 1, size - 1));
			}
			if (currentShape->nextMatrix[i, j] == 14) {
				g->FillRectangle(Brushes::Cyan, Rectangle(400 + j * (size)+1, 200 + i * (size)+1, size - 1, size - 1));
			}
			if (currentShape->nextMatrix[i, j] == 15) {
				g->FillRectangle(Brushes::Yellow, Rectangle(400 + j * (size)+1, 200 + i * (size)+1, size - 1, size - 1));
			}
			if (currentShape->nextMatrix[i, j] == 16) {
				g->FillRectangle(Brushes::Cyan, Rectangle(400 + j * (size)+1, 200 + i * (size)+1, size - 1, size - 1));
			}
			if (currentShape->nextMatrix[i, j] == 17) {
				g->FillRectangle(Brushes::Yellow, Rectangle(400 + j * (size)+1, 200 + i * (size)+1, size - 1, size - 1));
			}
			if (currentShape->nextMatrix[i, j] == 18) {
				g->FillRectangle(Brushes::Cyan, Rectangle(400 + j * (size)+1, 200 + i * (size)+1, size - 1, size - 1));
			}
			if (currentShape->nextMatrix[i, j] == 19) {
				g->FillRectangle(Brushes::Yellow, Rectangle(400 + j * (size)+1, 200 + i * (size)+1, size - 1, size - 1));
			}
			if (currentShape->nextMatrix[i, j] == 20) {
				g->FillRectangle(Brushes::Cyan, Rectangle(400 + j * (size)+1, 200 + i * (size)+1, size - 1, size - 1));
			}
			if (currentShape->nextMatrix[i, j] == 21) {
				g->FillRectangle(Brushes::Yellow, Rectangle(400 + j * (size)+1, 200 + i * (size)+1, size - 1, size - 1));
			}
			if (currentShape->nextMatrix[i, j] == 22) {
				g->FillRectangle(Brushes::Cyan, Rectangle(400 + j * (size)+1, 200 + i * (size)+1, size - 1, size - 1));
			}
			if (currentShape->nextMatrix[i, j] == 23) {
				g->FillRectangle(Brushes::Yellow, Rectangle(400 + j * (size)+1, 200 + i * (size)+1, size - 1, size - 1));
			}
		}
	}
}

Tetris1::Tetris::~Tetris() {
	if (components) {
		delete components;
	}
	if (currentShape) {
		delete currentShape;
	}
}