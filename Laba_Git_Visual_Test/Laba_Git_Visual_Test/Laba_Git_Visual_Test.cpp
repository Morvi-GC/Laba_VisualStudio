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
	int EvaluateHand()
	{
		int ValueCounts[15] = {};
		for (int i = 0; i < 5; i++)
		{
			int Value = m_HAND[i].GetValue();
			ValueCounts[Value]++;
		}
		int PairCount = 0;
		bool HasThree = false;
		bool HasFour = false;
		for (int i = 2; i < 15; i++)
		{
			if (ValueCounts[i] == 2)
			{
				PairCount++;
			}
			else if (ValueCounts[i] == 3)
			{
				HasThree = true;
			}
			else if (ValueCounts[i] == 4)
			{
				HasFour = true;
			}
		}
		bool HasFlush = true;
		for (int i = 1; i < 5; i++)
		{
			if (m_HAND[i].GetColor() != m_HAND[0].GetColor())
			{
				HasFlush = false;
			}
		}
		bool HasStraight = false;
		int ConsecutiveCount = 0;
		for (int i = 2; i < 15; i++)
		{
			if (ValueCounts[i] == 1)
			{
				ConsecutiveCount++;
			}
			else
			{
				ConsecutiveCount = 0;
			}
			if (ConsecutiveCount == 5)
			{
				HasStraight = true;
			}
		}
		if (ValueCounts[14] == 1 && ValueCounts[2] == 1 && ValueCounts[3] == 1 && ValueCounts[4] == 1 && ValueCounts[5] == 1)
		{
			HasStraight = true;
		}
		if (HasStraight == true && HasFlush == true)
		{
			cout << "POKER" << endl;
			return 8;
		}
		else if (HasFour == true)
		{
			cout << "KARETA" << endl;
			return 7;
		}
		else if (HasThree == true && PairCount == 1)
		{
			cout << "FULL" << endl;
			return 6;
		}
		else if (HasFlush == true)
		{
			cout << "KOLOR" << endl;
			return 5;
		}
		else if (HasStraight == true)
		{
			cout << "STRIT" << endl;
			return 4;
		}
		else if (HasThree == true)
		{
			cout << "TROJKA" << endl;
			return 3;
		}
		else if (PairCount == 2)
		{
			cout << "DWIE PARY" << endl;
			return 2;
		}
		else if (PairCount == 1)
		{
			cout << "PARA" << endl;
			return 1;
		}
		else
		{
			cout << "WYSOKA KARTA" << endl;
			return 0;
		}

	}
	int GetCardValue(int Index)
	{
		return m_HAND[Index].GetValue();
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
void GetInput(bool &Endgame, int &CardIndex, bool & ExchangeFinished)
{
	cout << "MENU GRY" << endl;
	cout << "1. Kliknij - q - jesli chcesz zakonczyc gre." << endl;
	CardIndex = -1;
	cout << "2. Wymiana - 1 do 5 - podaj numer karty ktora chcesz wymienic." << endl;
	cout << "3. Kliknij inny symbol np - x - jesli nie chcesz wymienic zadnej karty i przejsc dalej." << endl;
	cout << "4. Kliknij - k - zakoncz wymiane i przejdz do porownania rak" << endl;
	char EndSymbol;
	cin >> EndSymbol;
	if (EndSymbol == 'q')
	{
		Endgame = true;
	}
	else if (EndSymbol >= '1' && EndSymbol <= '5' && ExchangeFinished == false)
	{
		CardIndex = EndSymbol - '1';
	}
	else if (EndSymbol == 'k')
	{
		ExchangeFinished = true;
	}
}
void UpdateGame(Deck& deck, Player& player, int CardIndex)
{
	player.ExchangeCard(deck, CardIndex);
}
void CompareHands(Player& MyHand, Player& Opponent)
{
	int PlayerRank = MyHand.EvaluateHand();
	int OpponentRank = Opponent.EvaluateHand();
	if (PlayerRank > OpponentRank)
	{
		cout << "WYGRALES !!!" << endl;
	}
	else if (OpponentRank > PlayerRank)
	{
		cout << "PRZEGRALES :/ " << endl;
	}
	else
	{
		cout << "Ten sam rodzaj ukladu — potrzebne porownanie kart" << endl;
		int PlayerCounts[15] = {};
		int OpponentCounts[15] = {};
		for (int i = 0; i < 5; i++)
		{
			int PlayerValue = MyHand.GetCardValue(i);
			PlayerCounts[PlayerValue]++;
			int OpponentValue = Opponent.GetCardValue(i);
			OpponentCounts[OpponentValue]++;
		}
		if (PlayerRank == 1)
		{
			int PlayerPair = 0;
			int OpponentPair = 0;
			for (int i = 2; i < 15; i++)
			{
				if (PlayerCounts[i] == 2)
				{
					PlayerPair = i;
				}
				if (OpponentCounts[i] == 2)
				{
					OpponentPair = i;
				}
			}
		}
	}

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
	bool ExchangeFinished = false;
	bool HandsCompared = false;
	while (!EndGame)
	{
		Render(MyHand);
		GetInput(EndGame, CardIndex, ExchangeFinished);
		UpdateGame(MyDeck, MyHand, CardIndex);
		if (ExchangeFinished == true && HandsCompared == false)
		{
			CompareHands(MyHand, Opponent);
			HandsCompared = true;
		}

	}


	return 0;
}