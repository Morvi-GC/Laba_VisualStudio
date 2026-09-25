#include <iostream>

using namespace std;

const int BOARD_SIZE = 30;

void Render(int BOARD, int World[][BOARD_SIZE])
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			cout << World[i][j] << "_";
		}
		cout << endl;
	}
}


int main()
{
	int World[BOARD_SIZE][BOARD_SIZE] = {};

	Render(BOARD_SIZE, World);

	bool Life = 1;
	bool Dead = 0;

	return 0;
}
