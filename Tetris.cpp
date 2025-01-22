#include <iostream>
#include <windows.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include <conio.h>

using namespace std;


const int BUCKHEIGHT = 24;
const int BUCKWIDTH = 14;

char bucket[BUCKHEIGHT][BUCKWIDTH];
int newShapeTopLeftX, newShapeTopLeftY;

enum { UP_ARROW = 72, DOWN_ARROW = 80, LEFT_ARROW = 75, RIGHT_ARROW = 77 };

class TetrisShape {
public:
	char shapeArray[4][4];
	int shapeTopLeftX;
	int shapeTopLeftY;
	int shapeHeight;

	TetrisShape() {
		shapeTopLeftX = 6;
		shapeTopLeftY = 0;

	}




	void populateShapeArray(int shapeType) {

		shapeTopLeftX = 6;
		shapeTopLeftY = 0;

		switch (shapeType)
		{
		case 0: // J shape
			shapeArray[0][0] = ' '; shapeArray[0][1] = ' '; shapeArray[0][2] = ' '; shapeArray[0][3] = ' ';
			shapeArray[1][0] = 'X'; shapeArray[1][1] = 'X'; shapeArray[1][2] = 'X'; shapeArray[1][3] = ' ';
			shapeArray[2][0] = ' '; shapeArray[2][1] = ' '; shapeArray[2][2] = 'X'; shapeArray[2][3] = ' ';
			shapeArray[3][0] = ' '; shapeArray[3][1] = ' '; shapeArray[3][2] = ' '; shapeArray[3][3] = ' ';
			shapeHeight = 3;

			break;

		case 1: // I shape
			shapeArray[0][0] = ' '; shapeArray[0][1] = ' '; shapeArray[0][2] = ' '; shapeArray[0][3] = ' ';
			shapeArray[1][0] = 'X'; shapeArray[1][1] = 'X'; shapeArray[1][2] = 'X'; shapeArray[1][3] = 'X';
			shapeArray[2][0] = ' '; shapeArray[2][1] = ' '; shapeArray[2][2] = ' '; shapeArray[2][3] = ' ';
			shapeArray[3][0] = ' '; shapeArray[3][1] = ' '; shapeArray[3][2] = ' '; shapeArray[3][3] = ' ';
			shapeHeight = 2;
			break;

		case 2: // L shape
			shapeArray[0][0] = ' '; shapeArray[0][1] = ' '; shapeArray[0][2] = ' '; shapeArray[0][3] = ' ';
			shapeArray[1][0] = 'X'; shapeArray[1][1] = 'X'; shapeArray[1][2] = 'X'; shapeArray[1][3] = ' ';
			shapeArray[2][0] = 'X'; shapeArray[2][1] = ' '; shapeArray[2][2] = ' '; shapeArray[2][3] = ' ';
			shapeArray[3][0] = ' '; shapeArray[3][1] = ' '; shapeArray[3][2] = ' '; shapeArray[3][3] = ' ';
			shapeHeight = 3;
			break;

		case 3: // o shape
			shapeArray[0][0] = ' '; shapeArray[0][1] = ' '; shapeArray[0][2] = ' '; shapeArray[0][3] = ' ';
			shapeArray[1][0] = ' '; shapeArray[1][1] = 'X'; shapeArray[1][2] = 'X'; shapeArray[1][3] = ' ';
			shapeArray[2][0] = ' '; shapeArray[2][1] = 'X'; shapeArray[2][2] = 'X'; shapeArray[2][3] = ' ';
			shapeArray[3][0] = ' '; shapeArray[3][1] = ' '; shapeArray[3][2] = ' '; shapeArray[3][3] = ' ';
			shapeHeight = 3;
			break;

		case 4: // S shape
			shapeArray[0][0] = ' '; shapeArray[0][1] = ' '; shapeArray[0][2] = ' '; shapeArray[0][3] = ' ';
			shapeArray[1][0] = ' '; shapeArray[1][1] = 'X'; shapeArray[1][2] = 'X'; shapeArray[1][3] = ' ';
			shapeArray[2][0] = 'X'; shapeArray[2][1] = 'X'; shapeArray[2][2] = ' '; shapeArray[2][3] = ' ';
			shapeArray[3][0] = ' '; shapeArray[3][1] = ' '; shapeArray[3][2] = ' '; shapeArray[3][3] = ' ';
			shapeHeight = 3;
			break;

		case 5: // T shape
			shapeArray[0][0] = ' '; shapeArray[0][1] = ' '; shapeArray[0][2] = ' '; shapeArray[0][3] = ' ';
			shapeArray[1][0] = 'X'; shapeArray[1][1] = 'X'; shapeArray[1][2] = 'X'; shapeArray[1][3] = ' ';
			shapeArray[2][0] = ' '; shapeArray[2][1] = 'X'; shapeArray[2][2] = ' '; shapeArray[2][3] = ' ';
			shapeArray[3][0] = ' '; shapeArray[3][1] = ' '; shapeArray[3][2] = ' '; shapeArray[3][3] = ' ';
			shapeHeight = 3;
			break;

		case 6: // Z shape
			shapeArray[0][0] = ' '; shapeArray[0][1] = ' '; shapeArray[0][2] = ' '; shapeArray[0][3] = ' ';
			shapeArray[1][0] = 'X'; shapeArray[1][1] = 'X'; shapeArray[1][2] = ' '; shapeArray[1][3] = ' ';
			shapeArray[2][0] = ' '; shapeArray[2][1] = 'X'; shapeArray[2][2] = 'X'; shapeArray[2][3] = ' ';
			shapeArray[3][0] = ' '; shapeArray[3][1] = ' '; shapeArray[3][2] = ' '; shapeArray[3][3] = ' ';
			shapeHeight = 3;
			break;

		}
	}
};



void setCursorTo(int x, int y)
{

	HANDLE handle;
	COORD position;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	position.X = x;
	position.Y = y;
	SetConsoleCursorPosition(handle, position);

}


void initBucket() {

	for (int i = 0; i < BUCKHEIGHT; i++) {

		for (int j = 0; j < BUCKWIDTH; j++) {

			if (i == BUCKHEIGHT - 1 || j == 0 || j == BUCKWIDTH - 1) {

				bucket[i][j] = '#';
			}
			else {
				bucket[i][j] = ' ';
			}
		}
	}
}

void dispBucket() {

	setCursorTo(0, 0);

	for (int i = 0; i < BUCKHEIGHT; i++) {

		for (int j = 0; j < BUCKWIDTH; j++) {

			cout << bucket[i][j];
		}
		cout << endl;
	}
}



    void updateBucket(TetrisShape localTetrisShape, int shapeTopLeftX, int shapeTopLeftY) {

        for (int i = 0; i < localTetrisShape.shapeHeight; i++) {

            for (int j = 0; j < 4; j++) {

                bucket[i + shapeTopLeftY][j + shapeTopLeftX] = localTetrisShape.shapeArray[i][j];

		}
	}



}




bool isStuck(TetrisShape localTetrisShape)
{

	for (int j = 0; j < 4; j++)
	{

		int i = localTetrisShape.shapeHeight - 1;

		if (bucket[localTetrisShape.shapeTopLeftY + i][localTetrisShape.shapeTopLeftX + (j - 1)] == 'X') {
			return true;

		}
	}


	if (localTetrisShape.shapeTopLeftY + localTetrisShape.shapeHeight >= BUCKHEIGHT)
	{
		return true;
	}

	else
	{
		return false;
	}

}


void dropRow(TetrisShape tetShape) {

	for (int j = 1; j <= BUCKWIDTH - 1; j++) {

		if (bucket[24][j] == 'X') {

			bucket[24][j] == ' ';

			for (int i = 1; i < BUCKHEIGHT - 2; i++) {

				for (int k = 1; k < BUCKWIDTH; k++) {

					bucket[i++][k++];

				}
			}
		}

	}



}




void rotateShape(TetrisShape& currentShape) {

	char tempCellVal = currentShape.shapeArray[0][0];
	currentShape.shapeArray[0][0] = currentShape.shapeArray[0][3];
	currentShape.shapeArray[0][3] = currentShape.shapeArray[3][3];
	currentShape.shapeArray[3][3] = currentShape.shapeArray[3][0];
	currentShape.shapeArray[3][0] = tempCellVal;

	tempCellVal = currentShape.shapeArray[0][1];
	currentShape.shapeArray[0][1] = currentShape.shapeArray[1][3];
	currentShape.shapeArray[1][3] = currentShape.shapeArray[3][2];
	currentShape.shapeArray[3][2] = currentShape.shapeArray[2][0];
	currentShape.shapeArray[2][0] = tempCellVal;

	tempCellVal = currentShape.shapeArray[0][2];
	currentShape.shapeArray[0][2] = currentShape.shapeArray[2][3];
	currentShape.shapeArray[2][3] = currentShape.shapeArray[3][1];
	currentShape.shapeArray[3][1] = currentShape.shapeArray[1][0];
	currentShape.shapeArray[1][0] = tempCellVal;

	tempCellVal = currentShape.shapeArray[1][1];
	currentShape.shapeArray[1][1] = currentShape.shapeArray[1][2];
	currentShape.shapeArray[1][2] = currentShape.shapeArray[2][2];
	currentShape.shapeArray[2][2] = currentShape.shapeArray[2][1];
	currentShape.shapeArray[2][1] = tempCellVal;
}


void newShapeSpot(TetrisShape shape, int xAxis, int yAxis) {

	if (RIGHT_ARROW) {

		xAxis++;

		newShapeTopLeftX = xAxis - 1;
	}

	if (LEFT_ARROW) {

		xAxis--;
		newShapeTopLeftX = xAxis - 1;

	}
	if (DOWN_ARROW) {

		yAxis++;
		newShapeTopLeftY = yAxis - 1;

	}
	else {

		yAxis++;

	}
}


int main() {

	TetrisShape shape;
	bool hitBottom = false;
	bool gameOver = false;
	initBucket();
	//srand(time(0));
	int random = rand() % 7;
	shape.populateShapeArray(random);
	int input = 0;
	int score = 0;
	int newShapeTopLeftY;

	while (gameOver == false) {

		updateBucket(shape, shape.shapeTopLeftX, shape.shapeTopLeftY);

		shape.shapeTopLeftY++;

		score += 5;

		if (_kbhit())
		{
			input = _getch();

			switch (input) {

			case UP_ARROW:
				rotateShape(shape);


				break;

			case DOWN_ARROW:
				shape.shapeTopLeftY++;
				newShapeTopLeftX = shape.shapeTopLeftX;
				newShapeTopLeftY = shape.shapeTopLeftY - 1;
				newShapeSpot(shape, newShapeTopLeftX, newShapeTopLeftY);
				break;

			case LEFT_ARROW:
				shape.shapeTopLeftX--;
				newShapeTopLeftX = shape.shapeTopLeftX - 1;
				newShapeTopLeftY = shape.shapeTopLeftY;
				newShapeSpot(shape, newShapeTopLeftX, newShapeTopLeftY);

				break;

			case RIGHT_ARROW:
				shape.shapeTopLeftX++;
				newShapeTopLeftX = shape.shapeTopLeftX;
				newShapeTopLeftY = shape.shapeTopLeftY;
				newShapeSpot(shape, newShapeTopLeftX, newShapeTopLeftY);

				break;

			}



		}

		dropRow(shape);
		hitBottom = isStuck(shape);

		if (hitBottom == true) {
			score += 20;
			random = rand() % 7;
			shape.populateShapeArray(random);
			hitBottom = false;
		}


		dispBucket();


		Sleep(300);

	}

	return 0;
}

