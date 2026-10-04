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
	Card DrawCard()
	{
		if (m_NextCard >= 52)
		{
			Card EmptyCard;
			cout << "Brak kart" << endl;
			return EmptyCard;
		}
		Card DrawnCard = m_Card[m_NextCard];
		m_NextCard++;
		return DrawnCard;
	}
private:
	Card m_Card[52] = {};
	int m_NextCard = 0;
};
class Player
{
public:
	void TakeCards(Deck& deck)
	{
		for (int i = 0; i < 5; i++)
		{
			Card TakenCard = deck.DrawCard();
			if (TakenCard.GetValue() == 0)
			{
				return;
			}
			m_HAND[i] = TakenCard;
		}
	}
	void ShowHand()
	{
		for (int i = 0; i < 5; i++)
		{
			cout << i +1 << ". " << m_HAND[i].GetValueName() << " " << m_HAND[i].GetColorName() << endl;
		}
	}
	void ExchangeCard(Deck& deck, int CardIndex)
	{
		if (CardIndex < 0 || CardIndex > 4)
		{
			return;
		}
		Card UpdataCard = deck.DrawCard();
		if (UpdataCard.GetValue() == 0)
		{
			return;
		}
		m_HAND[CardIndex] = UpdataCard;
	}

private:
	Card m_HAND[5] = {};
};

void Initialize(Deck& MyDeck, Player& MyHand, Player& Opponent)
{
	MyDeck.Shuffle();
	MyHand.TakeCards(MyDeck);
	Opponent.TakeCards(MyDeck);
}
void Render(Player& MyHand)
{
	MyHand.ShowHand();
}
void GetInput(bool &Endgame, int &CardIndex)
{
	cout << "Jesli chcesz zakonczyc gre kliknij - q," << endl;
	CardIndex = -1;
	cout << "lub podaj numer karty od 1 do 5 ktora wymienisz." << endl;
	cout << "Jesli nie chcesz wymienic zadnej karty i przejsc dalej kliknij - x" << endl;
	char EndSymbol;
	cin >> EndSymbol;
	if (EndSymbol == 'q')
	{
		Endgame = true;
	}
	else if (EndSymbol >= '1' && EndSymbol <= '5')
	{
		CardIndex = EndSymbol - '1';
	}
}
void UpdateGame(Deck& deck, Player& player, int CardIndex)
{
	player.ExchangeCard(deck, CardIndex);
}


int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	bool EndGame = false;
	Deck MyDeck;
	Player MyHand;
	Player Opponent;

	Initialize(MyDeck, MyHand, Opponent);
	int CardIndex = -1;
	while (!EndGame)
	{
		Render(MyHand);
		GetInput(EndGame, CardIndex);
		UpdateGame(MyDeck, MyHand, CardIndex);


	}


	return 0;
}