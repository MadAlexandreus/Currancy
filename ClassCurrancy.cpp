#include "ClassCurrancy.h"

using namespace std;
using namespace std::filesystem;

void Currancy::AddPurchase(string Modifier)
{
	
	if (Modifier == "OLD")
	{
		if (Amount.size() == 0 && Exchange.size() == 0)
		{
			system("cls");
			cout << "Ó âàñ íåò áîëåå ñòàðûõ ïîêóïîê, âîéäèòå áåç ìîäèôèêàòîðà" << endl << endl;
			return;
		}
		if (Amount.size() >= 2)
		{
			double Exch = 0;

			do
			{
				system("cls");
				cout << "Ó âàñ åñòü íåñêîëüêî ïîêóïîê ñ ðàçíûìè êóðñàìè, ïîæàëóéñòà, ââäåäèòå æåëàåìûé êóðñ\n";
				 
				getDouble(Exch);
			} while (Exch < 0);


			system("cls");

			cout << "Ñïàñèáî" << endl << endl;

			for (int i = 0; i < Exchange.size(); i++)
			{
				if (Exch == Exchange[i])
				{
					double temp = 0;
					do
					{
						system("cls");
						cout << "Ââåäèòå êîëè÷åñâî" << endl;

						getDouble(temp);
					} while (temp < 0);

					TotalAmount += temp;
					Amount[i] += temp;
					system("cls");
					break;
				}
			}
		}
		else
		{
			double temp = 0;
			do
			{
				system("cls");
				cout << "Ââåäèòå êîëè÷åñâî" << endl;

				getDouble(temp);
			} while (temp < 0);

			TotalAmount += temp;
			Amount[0] += temp;
			system("cls");
		}

	}
	else if (Modifier == "NEW")
	{
		double temp;
		do
		{
			system("cls");
			cout << "Ââåäèòå êîëè÷åñâî" << endl;

			getDouble(temp);
		} while (temp < 0);
		Amount.push_back(temp);
		temp = 0;

		TotalAmount += Amount[Amount.size() - 1];

		do
		{
			system("cls");
			cout << "Ââåäèòå êóðñ âàëþòû" << endl;

			getDouble(temp);
		} while (temp < 0);
		Exchange.push_back(temp);

		system("cls");
	}
	else
	{
		cout << "Òàêîãî ìîäèôèêàòîðà íåò" << endl;
		return;
	}
}

double Currancy::CalcRecExchange(int index)
{
	return (Exchange[index] * 1.05);
}

double Currancy::CalcTotalRecExchange()
{
	return  (*(max_element(begin(Exchange), end(Exchange))) * 1.05);
}

void Currancy::TotalReset(Currancy& object)
{
	if (std::filesystem::exists(object.getDirectoryPath()))
	{
		if (!object.getDirectoryPath().empty()) {
			remove(object.getAmountPath());
			remove(object.getExchangePath());
			remove(object.getTotalAmountPath());
		}
	}
	Exchange.clear();
	Amount.clear();
	TotalAmount = 0;
}

void Currancy::Reset(int index)
{
	if (Amount.size() == 1 && Exchange.size() == 1)
	{
		Amount.clear();
		Exchange.clear();
		TotalAmount = 0;

		return;
	}
	TotalAmount -= Amount[index];
	Exchange[index] = 0;
	Amount[index] = 0;
}


bool getInt(int& value)
{
	int tempValue = 0;

	bool result = false;

	cin >> tempValue;

	if (cin.fail())
	{
		system("cls");

		cin.clear();

		cin.ignore(32767, '\n');
	}
	else
	{
		value = tempValue;

		cin.ignore(32767, '\n');

		result = true;
	}

	return result;
}
bool getChar(char& value)
{

	char tempValue = 0;

	bool result = false;

	cin >> tempValue;

	if (cin.fail())
	{
		system("cls");

		cin.clear();

		cin.ignore(32767, '\n');
	}
	else
	{
		value = tempValue;

		cin.ignore(32767, '\n');

		result = true;
	}

	return result;
}
bool getDouble(double& value)
{
	double tempValue = 0;

	bool result = false;

	cin >> tempValue;

	if (cin.fail())
	{
		system("cls");

		cin.clear();

		cin.ignore(32767, '\n');
	}
	else
	{
		value = tempValue;

		cin.ignore(32767, '\n');

		result = true;
	}

	return result;
}
