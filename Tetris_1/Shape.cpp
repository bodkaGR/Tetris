#include "Shape.h"

Shape::Shape(int _x, int _y, int choice) : x(_x), y(_y) {
	tetr1 = gcnew array<int, 2>(4, 4) {
		{0, 0, 1, 0},
		{ 0, 0, 1, 0 },
		{ 0, 0, 1, 0 },
		{ 0, 0, 1, 0 }
	};

	tetr2 = gcnew array<int, 2>(3, 3) {
		{0, 2, 0},
		{ 0, 2, 2 },
		{ 0, 0, 2 }
	};

	tetr3 = gcnew array<int, 2>(3, 3) {
		{0, 0, 0},
		{ 3, 3, 3 },
		{ 0, 3, 0 }
	};

	tetr4 = gcnew array<int, 2>(3, 3) {
		{0, 4, 0},
		{ 0, 4, 0 },
		{ 0, 4, 4 }
	};

	tetr5 = gcnew array<int, 2>(2, 2) {
		{5, 5},
		{ 5, 5 },
	};

	tetr1_l2 = gcnew array<int, 2>(5, 5) {
		{0, 0, 6, 0, 0},
		{ 0, 0, 6, 0, 0 },
		{ 0, 0, 6, 0, 0 },
		{ 0, 0, 6, 0, 0 },
		{ 0, 0, 6, 0, 0 },
	};

	tetr2_l2 = gcnew array<int, 2>(3, 3) {
		{0, 7, 7},
		{ 7, 7, 0 },
		{ 0, 7, 0 },
	};

	tetr3_l2 = gcnew array<int, 2>(3, 3) {
		{8, 8, 0},
		{ 0, 8, 8 },
		{ 0, 8, 0 },
	};

	tetr4_l2 = gcnew array<int, 2>(4, 4) {
		{0, 0, 9, 0},
		{ 0, 0, 9, 0 },
		{ 0, 0, 9, 0 },
		{ 0, 9, 9, 0 },
	};

	tetr5_l2 = gcnew array<int, 2>(4, 4) {
		{0, 0, 10, 0},
		{ 0, 0, 10, 0 },
		{ 0, 0, 10, 0 },
		{ 0, 0, 10, 10 },
	};

	tetr6_l2 = gcnew array<int, 2>(3, 3) {
		{11, 11, 0},
		{ 11, 11, 0 },
		{ 0, 11, 0 },
	};

	tetr7_l2 = gcnew array<int, 2>(3, 3) {
		{0, 12, 12},
		{ 0,12, 12 },
		{ 0,12, 0 },
	};

	tetr8_l2 = gcnew array<int, 2>(4, 4) {
		{0, 13, 0, 0},
		{ 0, 13, 0, 0 },
		{ 13, 13, 0, 0 },
		{ 13, 0, 0, 0 },
	};

	tetr9_l2 = gcnew array<int, 2>(4, 4) {
		{0, 14, 0, 0},
		{ 0, 14, 0, 0 },
		{ 0, 14, 14, 0 },
		{ 0, 0, 14, 0 },
	};

	tetr10_l2 = gcnew array<int, 2>(3, 3) {
		{15, 15, 15},
		{ 0, 15, 0 },
		{ 0, 15, 0 },
	};

	tetr11_l2 = gcnew array<int, 2>(3, 3) {
		{0, 0, 0},
		{ 16, 0, 16 },
		{ 16, 16, 16 },
	};

	tetr12_l2 = gcnew array<int, 2>(3, 3) {
		{0, 0, 17},
		{ 0, 0, 17 },
		{ 17, 17, 17 },
	};

	tetr13_l2 = gcnew array<int, 2>(3, 3) {
		{0, 0, 18},
		{ 0, 18, 18 },
		{ 18, 18, 0 },
	};

	tetr14_l2 = gcnew array<int, 2>(3, 3) {
		{0, 19, 0},
		{ 19, 19, 19 },
		{ 0, 19, 0 },
	};

	tetr15_l2 = gcnew array<int, 2>(4, 4) {
		{0, 0, 20, 0},
		{ 0, 20, 20, 0 },
		{ 0, 0, 20, 0 },
		{ 0, 0, 20, 0 },
	};

	tetr16_l2 = gcnew array<int, 2>(4, 4) {
		{0, 0, 21, 0},
		{ 0, 0, 21, 21 },
		{ 0, 0, 21, 0 },
		{ 0, 0, 21, 0 },
	};

	tetr17_l2 = gcnew array<int, 2>(3, 3) {
		{0, 22, 22},
		{ 0, 22, 0 },
		{ 22, 22, 0 },
	};

	tetr18_l2 = gcnew array<int, 2>(3, 3) {
		{23, 23, 0},
		{ 0, 23, 0 },
		{ 0, 23, 23 },
	};

	if (choice == 1) {
		matrix = GenerateMatrix();
		sizeMatrix = System::Convert::ToInt32(Math::Sqrt(matrix->Length));
		nextMatrix = GenerateMatrix();
		sizeNextMatrix = System::Convert::ToInt32(Math::Sqrt(nextMatrix->Length));
	}
	else if (choice == 2) {
		matrix = GenerateMatrixNextLevel();
		sizeMatrix = System::Convert::ToInt32(Math::Sqrt(matrix->Length));
		nextMatrix = GenerateMatrixNextLevel();
		sizeNextMatrix = System::Convert::ToInt32(Math::Sqrt(nextMatrix->Length));
	}
}

void Shape::ResetShape(int _x, int _y) {
	x = _x;
	y = _y;
	matrix = nextMatrix;
	sizeMatrix = System::Convert::ToInt32(Math::Sqrt(matrix->Length));
	nextMatrix = GenerateMatrix();
	sizeNextMatrix = System::Convert::ToInt32(Math::Sqrt(nextMatrix->Length));
}

void Shape::ResetShapeNextLevel(int _x, int _y) {
	x = _x;
	y = _y;
	matrix = nextMatrix;
	sizeMatrix = System::Convert::ToInt32(Math::Sqrt(matrix->Length));
	nextMatrix = GenerateMatrixNextLevel();
	sizeNextMatrix = System::Convert::ToInt32(Math::Sqrt(nextMatrix->Length));
}

void Shape::RotateShape() {
	array<int, 2>^ tempMatrix = gcnew array<int, 2>(sizeMatrix, sizeMatrix);
	for (int i = 0; i < sizeMatrix; i++) {
		for (int j = 0; j < sizeMatrix; j++) {
			tempMatrix[i, j] = matrix[j, (sizeMatrix - 1) - i];
		}
	}
	matrix = tempMatrix;
	int offset1 = (10 - (x + sizeMatrix));
	if (offset1 < 0) {
		for (int i = 0; i < Math::Abs(offset1); i++)
			MoveLeft();
	}
	if (x < 0) {
		for (int i = 0; i < Math::Abs(x) + 1; i++)
			MoveRight();
	}
}

array<int, 2>^ Shape::GenerateMatrix() {
	array<int, 2>^ _matrix;
	Random^ r = gcnew Random();

	int shapeIndex;
	do {
		shapeIndex = r->Next(1, 6);
	} while (shapeIndex == lastShapeIndex);

	lastShapeIndex = shapeIndex;

	switch (shapeIndex) {
	case 1:
		_matrix = gcnew array<int, 2>(4, 4);
		Array::Copy(tetr1, _matrix, tetr1->Length);
		break;
	case 2:
		_matrix = gcnew array<int, 2>(3, 3);
		Array::Copy(tetr2, _matrix, tetr2->Length);
		break;
	case 3:
		_matrix = gcnew array<int, 2>(3, 3);
		Array::Copy(tetr3, _matrix, tetr3->Length);
		break;
	case 4:
		_matrix = gcnew array<int, 2>(3, 3);
		Array::Copy(tetr4, _matrix, tetr4->Length);
		break;
	case 5:
		_matrix = gcnew array<int, 2>(2, 2);
		Array::Copy(tetr5, _matrix, tetr5->Length);
		break;
	}
	return _matrix;
}

array<int, 2>^ Shape::GenerateMatrixNextLevel() {
	array<int, 2>^ _matrix;
	Random^ r = gcnew Random();

	int shapeIndex;
	do {
		shapeIndex = r->Next(1, 6);
	} while (shapeIndex == lastShapeIndexNextMatrix);

	lastShapeIndexNextMatrix = shapeIndex;

	switch (shapeIndex) {
	case 1:
		_matrix = gcnew array<int, 2>(5, 5);
		Array::Copy(tetr1_l2, _matrix, tetr1_l2->Length);
		break;
	case 2:
		_matrix = gcnew array<int, 2>(3, 3);
		Array::Copy(tetr2_l2, _matrix, tetr2_l2->Length);
		break;
	case 3:
		_matrix = gcnew array<int, 2>(3, 3);
		Array::Copy(tetr3_l2, _matrix, tetr3_l2->Length);
		break;
	case 4:
		_matrix = gcnew array<int, 2>(4, 4);
		Array::Copy(tetr4_l2, _matrix, tetr4_l2->Length);
		break;
	case 5:
		_matrix = gcnew array<int, 2>(4, 4);
		Array::Copy(tetr5_l2, _matrix, tetr5_l2->Length);
		break;
	case 6:
		_matrix = gcnew array<int, 2>(3, 3);
		Array::Copy(tetr6_l2, _matrix, tetr6_l2->Length);
		break;
	case 7:
		_matrix = gcnew array<int, 2>(3, 3);
		Array::Copy(tetr7_l2, _matrix, tetr7_l2->Length);
		break;
	case 8:
		_matrix = gcnew array<int, 2>(4, 4);
		Array::Copy(tetr8_l2, _matrix, tetr8_l2->Length);
		break;
	case 9:
		_matrix = gcnew array<int, 2>(4, 4);
		Array::Copy(tetr9_l2, _matrix, tetr9_l2->Length);
		break;
	case 10:
		_matrix = gcnew array<int, 2>(3, 3);
		Array::Copy(tetr10_l2, _matrix, tetr10_l2->Length);
		break;
	case 11:
		_matrix = gcnew array<int, 2>(3, 3);
		Array::Copy(tetr11_l2, _matrix, tetr11_l2->Length);
		break;
	case 12:
		_matrix = gcnew array<int, 2>(3, 3);
		Array::Copy(tetr12_l2, _matrix, tetr12_l2->Length);
		break;
	case 13:
		_matrix = gcnew array<int, 2>(3, 3);
		Array::Copy(tetr13_l2, _matrix, tetr13_l2->Length);
		break;
	case 14:
		_matrix = gcnew array<int, 2>(3, 3);
		Array::Copy(tetr14_l2, _matrix, tetr14_l2->Length);
		break;
	case 15:
		_matrix = gcnew array<int, 2>(4, 4);
		Array::Copy(tetr15_l2, _matrix, tetr15_l2->Length);
		break;
	case 16:
		_matrix = gcnew array<int, 2>(4, 4);
		Array::Copy(tetr16_l2, _matrix, tetr16_l2->Length);
		break;
	case 17:
		_matrix = gcnew array<int, 2>(3, 3);
		Array::Copy(tetr17_l2, _matrix, tetr17_l2->Length);
		break;
	case 18:
		_matrix = gcnew array<int, 2>(3, 3);
		Array::Copy(tetr18_l2, _matrix, tetr18_l2->Length);
		break;
	}
	return _matrix;
}



void Shape::MoveDown() {
	y++;
}

void Shape::MoveRight() {
	x++;
}

void Shape::MoveLeft() {
	x--;
}