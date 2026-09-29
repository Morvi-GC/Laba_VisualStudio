#include <iostream>
#include <cstdlib>

using namespace std;

const int BOARD_SIZE = 30;

const char LIFE = 'O';
const char DEAD = '_';

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
			World[i][j] = '_';
		}
	}
	int Meter = 0;
	cout << "Teraz podaj miejsce powstania komorek:" << endl;
	cout << "1 - gora" << endl;
	cout << "2 - dol" << endl;
	cout << "3 - prawo" << endl;
	cout << "4 - lewo" << endl;
	int Direction = 0;
	cin >> Direction;
	while (Direction < 1 || Direction > 4)
	{
		cout << "Zly wybor - sprobuj jeszcze raz" << endl;
		cin >> Direction;
	}
	if (Direction == 1)
	{
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
	if (Direction == 2)
	{
		for (int i = BOARD_SIZE - 1; i >= 0; i--)
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
	if (Direction == 3)
	{
		for (int j = BOARD_SIZE - 1; j >= 0; j--)
		{
			for (int i = 0; i < BOARD_SIZE; i++)
			{
				if (Meter < StartLife)
				{
					World[i][j] = LIFE;
					Meter++;
				}
			}
		}
	}
	if (Direction == 4)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			for (int i = 0; i < BOARD_SIZE; i++)
			{
				if (Meter < StartLife)
				{
					World[i][j] = LIFE;
					Meter++;
				}
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
			if (World[i][j] == LIFE)
			{
				if (!(Neighbors == 2 || Neighbors == 3))
				{
					NextWorld[i][j] = DEAD;
				}
				else
				{
					NextWorld[i][j] = LIFE;
				}
			}
			if (World[i][j] == DEAD)
			{
				if (Neighbors == 3)
				{
					NextWorld[i][j] = LIFE;
				}
				else
				{
					NextWorld[i][j] = DEAD;
				}
			}
		}
	}
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			World[i][j] = NextWorld[i][j];
		}
	}
}
void Shutdown()
{
	cout << "Koniec gry" << endl;
}


int main()
{
	char World[BOARD_SIZE][BOARD_SIZE] = {'X'};

	Initialize(World);


	bool exitGame = 1;
	while (exitGame)
	{
		system("cls");
		Render(World);
		int Choice = GetInput();
		if (Choice == 0)
		{
			exitGame = 0;
		}
		else if (Choice != 1)
		{
			cout << "Nie prawidlowy wybor, wybierz jeszcze raz" << endl;
			system("pause");

		}
		else
		{
			UpdateGame(World);
		}

	}
	Shutdown();


	return 0;
}
