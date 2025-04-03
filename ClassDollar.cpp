#include "ClassDollar.h"
#include "CurrancyReadSavedData.h"
#include "CurrancySave.h"

using namespace std;
using namespace std::filesystem;

void DollarInteractionFunction()
{
	Dollar object;

	system("cls");

	object.getName();

	cout << endl << endl;

	ReadSavedData(object);		

	char Continuevalue;
	do
	{
		int switchValue = 0;

		do
		{
			system("cls");

			cout << std::setw(92) << std::left << "��������, ��� �� ������ �������:" << endl << endl;
			cout << std::setw(92) << std::left << "�������� ������ ���������� ������" << "1" << endl << endl;
			cout << std::setw(92) << std::left << "�������� ��������� ������ �� ����� ������" << "2" << endl << endl;
			cout << std::setw(92) << std::left << "���������� ��������������� �������� ���� ��� ���������� ������� (���������� ����� ������)" << "3" << endl << endl;
			cout << std::setw(92) << std::left << "���������� ��������������� �������� ���� ��� ���� �����" << "4" << endl << endl;
			cout << std::setw(92) << std::left << "�������� ����� �������" << "5" << endl << endl;
			cout << std::setw(92) << std::left << "������� ������� �� ����������� �������" << "6" << endl << endl;
			cout << std::setw(92) << std::left << "�������� ��� ������" << "7" << endl << endl;

			getInt(switchValue);
		} while (switchValue != 1 && switchValue != 2 && switchValue != 3 && switchValue != 4 && switchValue != 5 && switchValue != 6 && switchValue != 7);


		system("cls");

		if (switchValue == 1)
		{
			cout << "������ ���������� ������:" << endl << object.getTotalAmount() << endl << endl;

		}
		else if (switchValue == 2)
		{
			cout << std::setw(20) << std::left << "Exchange rate" << std::setw(7) << "Amount" << std::setw(7) << "Index" << endl << endl;

			for (int i = 0; i < object.getSIZE(); i++)
			{
				cout << std::setw(20) << object.getExchange(i) << std::setw(7) << object.getAmount(i) << std::setw(7) << i << endl << endl;
			}
		}
		else if (switchValue == 3)
		{
			int index = 0;
			if (object.getSIZE() == 0)
			{
				cout << "��� ������" << endl;
				return;
			}

			do
			{
				system("cls");
				cout << "������� ������" << endl;

				getInt(index);

				cout << endl << endl;
			} while ((index >= object.getSIZE()));

			if (std::filesystem::exists(object.getDirectoryPath()))
			{
				if (object.getDirectoryPath().empty()) {
					cout << "��� ������" << endl;
					return;
				}
			}
			else
			{
				cout << "��� ������" << endl;
				return;
			}

			cout << "��������������� �������� ���� ��� ���������� �������:" << endl << object.CalcRecExchange(index) << endl << endl;
		}
		else if (switchValue == 4)
		{
			if (std::filesystem::exists(object.getDirectoryPath()))
			{
				if (object.getDirectoryPath().empty()) {
					cout << "��� ������" << endl;
					return;
				}
			}
			else
			{
				cout << "��� ������" << endl;
				return;
			}

			cout << "��������������� �������� ���� ��� ���� �����" << endl << object.CalcTotalRecExchange() << endl << endl;
		}
		else if (switchValue == 5)
		{
			cout << "���� �� ������ ������ ����� ����� �� ������� ����� �������� <Old>, ��� ����� ����� -- <New>" << endl;

			string Modifier;
			cin >> Modifier;				//���� �� ��� ����� ���������� � ������������ ��

			for (size_t i = 0; i < Modifier.size(); i++)
			{
				Modifier[i] = toupper(Modifier.c_str()[i]);
			}

			system("cls");
			object.addPurchase(Modifier);
		}
		else if (switchValue == 6)
		{
			int index;
			if (object.getSIZE() == 0)
			{
				cout << "��� ������" << endl;
				return;
			}
			do
			{
				system("cls");
				cout << "������� ������" << endl;

				getInt(index);

				cout << endl << endl;
			} while ((index >= object.getSIZE()));

			object.Reset(index);
		}
		else if (switchValue == 7)
		{
			object.TotalReset(object);
			cout << "��� ������ �������" << endl << endl;
		}

		do
		{
			cout << "������ ����������?\n��� ����������� ������� Y, ��� ���������� ��������� ������� N" << endl << endl;

			getChar(Continuevalue);
		} while (Continuevalue != 'n' && Continuevalue != 'N' && Continuevalue != 'y' && Continuevalue != 'Y');

	} while (Continuevalue != 'n' && Continuevalue != 'N');

	system("cls");
	Save(object);
}