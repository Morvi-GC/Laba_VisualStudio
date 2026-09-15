#include <iostream>

using namespace std;

class Complex_Number //klasa liczba zespolona
{
	double Real_Number = 0; // liczba rzeczywista
	double Imaginary_Number = 0; // liczba urojona 

	public: // dostęp do danych po za klasą | u góry jest private

	Complex_Number(double Real, double Imaginary) // konstruktor przyjmuje wartości i zapisuje je w polach tworzonego obiektu
	{
		Real_Number = Real; // przypisanie podanej liczby przez konstruktora do klasy 
		Imaginary_Number = Imaginary;

	}

	Complex_Number(const Complex_Number &Prime) // konstruktor kopiujący - tworzenike obiektu o takich samych warotsiach | const aby nie zmieniał wartości | pod ziemniną nazwą Prime | & daje dostęp do istniejącego obiektu
	{
		Real_Number = Prime.Real_Number; // (lewa) miejsce na dane nowego obiektu = (prawa) dane starego obiektu 
		Imaginary_Number = Prime.Imaginary_Number;
	}
	Complex_Number operator+ (const Complex_Number& Right) const // dodawanie do lewej strony prawą stronę równania i tworzymy wartości nowego obiektu
	{
		double Sum_Real = Real_Number + Right.Real_Number; // zapisanie sumy pierwszych pól obu stron
		double Sum_Imaginary = Imaginary_Number + Right.Imaginary_Number;

		Complex_Number Result(Sum_Real, Sum_Imaginary); // tworzenie nowego obiektu z dwiema warotściamy (suma v1 i v2)


		return Result; // Zwrócenie wyniku do miejsca, które wywołało dodawanie
	}


};


int main()
{
	Complex_Number LiczbaZesV1(5, -3); // obiekt o klasie Complex_Number z danymi w nawiasach

	Complex_Number LiczbaZesV2(LiczbaZesV1); // utworzenie nowego obiektu ze wskazanem kopiowanego obiektu
	Complex_Number Sum = LiczbaZesV1 + LiczbaZesV2; // wywołanie operatora dodawania dla V1 i V2 oraz utworzenie obiektu Sum z wyniku



	return 0;
}