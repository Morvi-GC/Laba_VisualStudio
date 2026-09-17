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
	Complex_Number operator+ (const Complex_Number& Right_P) const // dodawanie do lewej strony prawą stronę równania i tworzymy wartości nowego obiektu
	{
		double Sum_Real_P = Real_Number + Right_P.Real_Number; // zapisanie sumy pierwszych pól obu stron
		double Sum_Imaginary_P = Imaginary_Number + Right_P.Imaginary_Number;

		Complex_Number Result_Sum(Sum_Real_P, Sum_Imaginary_P); // tworzenie nowego obiektu z dwiema warotściamy (suma v1 i v2)


		return Result_Sum; // Zwrócenie wyniku do miejsca, które wywołało dodawanie
	}
	Complex_Number operator- (const Complex_Number& Right_M) const // operator odejmowania
	{
		double Sub_Real_M = Real_Number - Right_M.Real_Number;
		double Sub_Imaginary_M = Imaginary_Number - Right_M.Imaginary_Number;

		Complex_Number Result_Sub (Sub_Real_M, Sub_Imaginary_M);

		return Result_Sub;
	}
	Complex_Number operator* (const Complex_Number& Right_Multi) const // operator mnożenia | na krzyż 
	{
		double Multi_Real = (Real_Number * Right_Multi.Real_Number) - (Imaginary_Number * Right_Multi.Imaginary_Number);
		double Multi_Imaginary = (Real_Number * Right_Multi.Imaginary_Number) + (Imaginary_Number * Right_Multi.Real_Number);

		Complex_Number Result_Multi(Multi_Real, Multi_Imaginary);

		return Result_Multi;
	}
	Complex_Number operator/ (const Complex_Number& Right_Divide) const // operator dzielenia | dzielenie przez wspólny mianownik — sumę kwadratów pól prawej strony
	{
		double Denominator = (Right_Divide.Real_Number * Right_Divide.Real_Number ) + (Right_Divide.Imaginary_Number * Right_Divide.Imaginary_Number);


			if (Denominator == 0) // wiem że nie można dzielić przez zero 
		{
			cout << "Nie mozna dzielic przez zero, wynik zwroce jako 0" << endl;
			Complex_Number Zero_Result(0, 0);

			return Zero_Result;

		}

		double Divide_Real = ((Real_Number * Right_Divide.Real_Number) + (Imaginary_Number * Right_Divide.Imaginary_Number)) / Denominator;
		double Divide_Imaginary = ((Right_Divide.Real_Number * Imaginary_Number) - (Real_Number * Right_Divide.Imaginary_Number)) / Denominator;
			

		Complex_Number Result_Divide(Divide_Real, Divide_Imaginary);

		return Result_Divide;

	}




};


int main()
{
	Complex_Number LiczbaZesV1(5, -3); // obiekt o klasie Complex_Number z danymi w nawiasach
	cout << "Nasza podstawowa liczba zespolona to" << endl;

	Complex_Number LiczbaZesV2(LiczbaZesV1); // utworzenie nowego obiektu ze wskazanem kopiowanego obiektu
	Complex_Number Sum = LiczbaZesV1 + LiczbaZesV2; // wywołanie operatora dodawania dla V1 i V2 oraz utworzenie obiektu Sum z wyniku

	Complex_Number LiczbaZesV3(2, 4);
	Complex_Number Sub = LiczbaZesV2 - LiczbaZesV3;

	Complex_Number LiczbaZesV4(- 6, 4.2);
	Complex_Number Multi = LiczbaZesV3 * LiczbaZesV4;

	Complex_Number LiczbaZesV5(LiczbaZesV1);
	Complex_Number Devide = LiczbaZesV3 / LiczbaZesV5;
	Complex_Number LiczbaZesV6(0, 0);
	Complex_Number Devide_Zero = LiczbaZesV5 / LiczbaZesV6;



	return 0;
}