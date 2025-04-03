#include "ClassEuro.h"
#include "ClassRusRuble.h"
#include "ClassDollar.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	int switchValue;
	char Continuevalue;

	do
	{
		do
		{
			system("cls");

			cout << "�������� ������" << endl << endl;
			cout << std::setw(17) << std::left << "Dollar" << 1 << endl << endl;
			cout << std::setw(17) << std::left << "Russian Ruble" << 2 << endl << endl;
			cout << std::setw(17) << std::left << "Euro" << 3 << endl << endl;

			getInt(switchValue);
		} while (switchValue != 1 && switchValue != 2 && switchValue != 3);

		if (switchValue == 1)
		{
			DollarInteractionFunction();
		}
		else if (switchValue == 2)
		{
			RusRubleInteractionFunction();
		}
		else if (switchValue == 3)
		{
			EuroInteractionFunction();
		}

		do
		{
			cout << "��� ������ ����� ������ ������� Y" << endl;
			cout << "������ ����������?\n��� ����������� ������� Y, ��� ���������� ��������� ������� N" << endl << endl;

			getChar(Continuevalue);
		} while (Continuevalue != 'n' && Continuevalue != 'N' && Continuevalue != 'y' && Continuevalue != 'Y');

	} while (Continuevalue != 'n' && Continuevalue != 'N');

	return 0;
}