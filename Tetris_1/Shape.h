#pragma once

using namespace System;

ref class Shape {
private:
	int lastShapeIndex = -1;  
	int lastShapeIndexNextMatrix = -1;

	array<int, 2>^ tetr1;
	array<int, 2>^ tetr2;
	array<int, 2>^ tetr3;
	array<int, 2>^ tetr4;
	array<int, 2>^ tetr5;

	array<int, 2>^ tetr1_l2;
	array<int, 2>^ tetr2_l2;
	array<int, 2>^ tetr3_l2;
	array<int, 2>^ tetr4_l2;
	array<int, 2>^ tetr5_l2;
	array<int, 2>^ tetr6_l2;
	array<int, 2>^ tetr7_l2;
	array<int, 2>^ tetr8_l2;
	array<int, 2>^ tetr9_l2;
	array<int, 2>^ tetr10_l2;
	array<int, 2>^ tetr11_l2;
	array<int, 2>^ tetr12_l2;
	array<int, 2>^ tetr13_l2;
	array<int, 2>^ tetr14_l2;
	array<int, 2>^ tetr15_l2;
	array<int, 2>^ tetr16_l2;
	array<int, 2>^ tetr17_l2;
	array<int, 2>^ tetr18_l2;
public:
	int x;
	int y;
	int sizeMatrix;
	int sizeNextMatrix;

	array<int, 2>^ matrix;
	array<int, 2>^ nextMatrix;

	Shape(int _x, int _y, int choice);

	void ResetShape(int _x, int _y);
	
	void ResetShapeNextLevel(int _x, int _y);

	void RotateShape();

	array<int, 2>^ GenerateMatrix();

	array<int, 2>^ GenerateMatrixNextLevel();

	void MoveDown();

	void MoveRight();

	void MoveLeft();
};
