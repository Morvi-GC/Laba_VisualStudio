#include <iostream>

using namespace std;

const int BOARD_SIZE = 30;

const char LIFE = 'O';
const char DEAD = 'X';

void Initialize(char World[][BOARD_SIZE])
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			World[i][j] = 'X';
		}
	}
}

void Render(char World[][BOARD_SIZE])
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			cout << World[i][j] << " ";
		}
		cout << endl;
	}
}

void UpdateGame()
{
	
}


int main()
{
	char World[BOARD_SIZE][BOARD_SIZE] = {'X'};

	Initialize(World);
	bool exitGame = 1;
	while (exitGame)
	{
		Render(World);

		cout << "Kliknij 1 jesli grasz dalej" << endl;
		cout << "Kliknij 0 jesli chcesz wyjsc" << endl;
		int GameLoop = 0;
		cin >> GameLoop;
		if (GameLoop == 0)
		{
			exitGame = 0;
		}

	}


	return 0;
}
