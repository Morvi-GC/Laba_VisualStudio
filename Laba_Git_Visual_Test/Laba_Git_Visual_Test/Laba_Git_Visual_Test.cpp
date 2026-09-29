#include <iostream>

using namespace std;

class Card
{
public:
	Card(int Value, const string& Color)
	{
		m_Value = Value;
		m_Color = Color;
	}
	int m_Value = 0;
	string m_Color;
	string GetString() const
	{
		return m_Color;
	}
};

int main()
{
	Card Two(2, "PIK");
	Card King(13, "KIER");
	cout << Two.Card();



	return 0;
}