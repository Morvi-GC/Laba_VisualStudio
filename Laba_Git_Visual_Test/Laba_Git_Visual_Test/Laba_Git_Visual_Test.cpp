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
	Color_Card m_Color;
};
class Deck
{
public:
	Deck()
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 2; j < 15; j++)
			{

			}
		}
	}
};

int main()
{
	Card Two_Pik(2, PIK);
	Card King_Kier(13, KIER);
	cout << Two_Pik.GetValue() << " " << Two_Pik.GetColor();




	return 0;
}