#include <iostream>

using namespace std;

const int BOARD_SIZE = 30;

const char LIFE = 'O';
const char DEAD = 'X';

void Initialize(char World[][BOARD_SIZE])
{
	cout << "Wybierz ile chcesz zywych komorek na start gry - od 0 do 900" << endl;
	int StartLife = 0;
	cin >> StartLife;
	while (StartLife < 0 || StartLife > 900)

	{
		cout << "Bledna liczba wychodzaca po za zakres - wybierz jeszcze raz" << endl;
		cin >> StartLife;
	}
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			World[i][j] = 'X';
		}
	}
	int Meter = 0;
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (Meter < StartLife)
			{
				World[i][j] = LIFE;
				Meter++;
			}
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

int GetInput()
{
		cout << "Kliknij 1 jesli grasz dalej" << endl;
		cout << "Kliknij 0 jesli chcesz wyjsc" << endl;
		int Choice = 0;
		cin >> Choice;

		return Choice;
}

void UpdateGame(char World[][BOARD_SIZE])
{
	char NextWorld[BOARD_SIZE][BOARD_SIZE] = {};
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			int Neighbors = 0;
			if (i > 0)
			{
				if (World[i - 1][j] == LIFE)
				{
					Neighbors++;
				}
			}
			if (i < BOARD_SIZE - 1)
			{
				if (World[i + 1][j] == LIFE)
				{
					Neighbors++;
				}
			}
			if (j > 0)
			{
				if (World[i][j - 1] == LIFE)
				{
					Neighbors++;
				}
			}
			if (j < BOARD_SIZE - 1)
			{
				if (World[i][j + 1] == LIFE)
				{
					Neighbors++;
				}
			}

			if (i > 0 && j > 0)
			{
				if (World[i - 1][j - 1] == LIFE)
				{
					Neighbors++;
				}
			}
			if (i > 0 && j < (BOARD_SIZE - 1))
			{
				if (World[i - 1][j + 1] == LIFE)
				{
					Neighbors++;
				}
			}
			if (i < (BOARD_SIZE - 1) && j > 0)
			{
				if (World[i + 1][j - 1] == LIFE)
				{
					Neighbors++;
				}
			}
			if (i < (BOARD_SIZE - 1) && j < (BOARD_SIZE - 1))
			{
				if (World[i + 1][j + 1] == LIFE)
				{
					Neighbors++;
				}
			}
		}
	}
}


int main()
{
	char World[BOARD_SIZE][BOARD_SIZE] = {'X'};

	Initialize(World);


	bool exitGame = 1;
	while (exitGame)
	{
		Render(World);
		int Choice = GetInput();
		if (Choice == 0)
		{
			exitGame = 0;
		}
		else if (Choice != 1)
		{
			cout << "Nie prawidlowy wybor, wybierz jeszcze raz" << endl;

		}


	}


	return 0;
}
