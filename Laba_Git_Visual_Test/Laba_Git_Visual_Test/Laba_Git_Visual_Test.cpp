#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

enum Color_Card
{
	KIER,
	PIK,
	KARO,
	TREFL,
};

class Card
{
public:
	Card(int Value, Color_Card Color)
	{
		m_Value = Value;
		m_Color = Color;
	}
	Card()
	{

	}
	int GetValue() const
	{
		return m_Value;
	}
	Color_Card GetColor() const
	{
		return m_Color;
	}
	string GetColorName() const
	{
		switch (m_Color)
		{
		case KIER:
			return "KIER";
		case PIK:
			return "PIK";
		case KARO:
			return "KARO";
		case TREFL:
			return "TREFL";
		default:
			return  "Kolor nie znany";
		}
	}
	string GetValueName() const
	{
		switch (m_Value)
		{
		case 11:
			return "WALET";
		case 12:
			return "DAMA";
		case 13:
			return "KROL";
		case 14:
			return "AS";
		default:
			return to_string(m_Value);
		}
	}
private:
	int m_Value = 0;
	Color_Card m_Color = KIER;
};
class Deck
{
public:
	Deck()
	{
		int Meter = 0;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 2; j < 15; j++)
			{
				Card New_Card(j, static_cast<Color_Card>(i));
				m_Card[Meter] = New_Card;
				Meter++;
			}
		}
	}
	void Show_Cards()
	{
		for (int i = 0; i < 52; i++)
		{
			cout << m_Card[i].GetValueName() << " " << m_Card[i].GetColorName() << endl;
		}
	}
	void Shuffle()
	{
		for (int i = 51; i > 0; i--)
		{
			int RandomIndex = rand() % (i + 1);
			{
				Card CARD = m_Card[i];
				m_Card[i] = m_Card[RandomIndex];
				m_Card[RandomIndex] = CARD;
			}
		}
	}
private:
	Card m_Card[52] = {};
};

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));
	Deck MyDeck;
	MyDeck.Shuffle();
	MyDeck.Show_Cards();



	return 0;
}