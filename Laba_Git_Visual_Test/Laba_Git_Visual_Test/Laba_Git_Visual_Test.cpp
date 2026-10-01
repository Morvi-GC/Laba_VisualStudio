#include <iostream>
#include <string>

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
			cout << m_Card[i].GetValue() << " " << m_Card[i].GetColor() << endl;
		}
	}
private:
	Card m_Card[52] = {};
};

int main()
{
	Deck MyDeck;
	MyDeck.Show_Cards();



	return 0;
}