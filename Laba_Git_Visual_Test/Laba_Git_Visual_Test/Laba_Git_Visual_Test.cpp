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
