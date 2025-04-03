#include "ClassEuro.h"
#include "CurrancyReadSavedData.h"
#include "CurrancySave.h"

using namespace std;
using namespace std::filesystem;

void EuroInteractionFunction()
{
	Euro object;

	system("cls");

	object.getName();

	std::cout << endl << endl;

	ReadSavedData(object);

	char Continuevalue;
	do
	{
		int switchValue = 0;

		do
		{
			system("cls");

			cout << std::setw(92) << std::left << "Âûáåðèòå, ÷òî âû õîòèòå ñäåëàòü:" << endl << endl;
			cout << std::setw(92) << std::left << "Ïîëó÷èòü ïîëíîå êîëè÷åñòâî âàëþòû" << "1" << endl << endl;
			cout << std::setw(92) << std::left << "Ïîëó÷èòü ðàçáèåíèå âàëþòû ïî ðàçûì êóðñàì" << "2" << endl << endl;
			cout << std::setw(92) << std::left << "Ðàññ÷èòàòü ðåêîìåíäîâàííûé îáìåííûé êóðñ äëÿ êîíêðåòíîé ïîêóïêè (Æåëàòåëüíî çíàòü èíäåêñ)" << "3" << endl << endl;
			cout << std::setw(92) << std::left << "Ðàññ÷èòàòü ðåêîìåíäîâàííûé îáìåííûé êóðñ äëÿ âñåé ñóììû" << "4" << endl << endl;
			cout << std::setw(92) << std::left << "Äîáàâèòü íîâóþ ïîêóïêó" << "5" << endl << endl;
			cout << std::setw(92) << std::left << "Óäàëèòü ïîêóïêó ïî êîíêðåòíîìó èíäåêñó" << "6" << endl << endl;
			cout << std::setw(92) << std::left << "Î÷èñòèòü âñå äàííûå" << "7" << endl << endl;

			getInt(switchValue);
		} while (switchValue != 1 && switchValue != 2 && switchValue != 3 && switchValue != 4 && switchValue != 5 && switchValue != 6 && switchValue != 7);

		system("cls");

		if (switchValue == 1)
		{
			cout << "Ïîëíîå êîëè÷åñòâî âàëþòû:" << endl << object.getTotalAmount() << endl << endl;

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
				cout << "Íåò äàííûõ" << endl;
				return;
			}

			do
			{
				system("cls");
				cout << "Ââåäèòå èíäåêñ" << endl;

				getInt(index);

				cout << endl << endl;
			} while ((index >= object.getSIZE()));

			if (std::filesystem::exists(object.getDirectoryPath()))
			{
				if (object.getDirectoryPath().empty()) {
					cout << "Íåò äàííûõ" << endl;
					return;
				}
			}
			else
			{
				cout << "Íåò äàííûõ" << endl;
				return;
			}

			cout << "Ðåêîìåíäîâàííûé îáìåííûé êóðñ äëÿ êîíêðåòíîé ïîêóïêè:" << endl << object.CalcRecExchange(index) << endl << endl;
		}
		else if (switchValue == 4)
		{
			if (std::filesystem::exists(object.getDirectoryPath()))
			{
				if (object.getDirectoryPath().empty()) {
					cout << "Íåò äàííûõ" << endl;
					return;
				}
			}
			else
			{
				cout << "Íåò äàííûõ" << endl;
				return;
			}

			cout << "Ðåêîìåíäîâàííûé îáìåííûé êóðñ äëÿ âñåé ñóììû" << endl << object.CalcTotalRecExchange() << endl << endl;
		}
		else if (switchValue == 5)
		{
			cout << "Åñëè âû õîòèòå âíåñòè íîâóþ ñóììó ïî ñòàðîìó êóðñó ââäåäèòå <Old>, äëÿ íîâîé ñóììû-- <New>" << endl;
			string Modifier;
			cin >> Modifier;			//òîæå

			for (size_t i = 0; i < Modifier.size(); i++)
			{
				Modifier[i] = toupper(Modifier.c_str()[i]);
			}

			system("cls");
			object.AddPurchase(Modifier);
		}
		else if (switchValue == 6)
		{
			int index;
			if (object.getSIZE() == 0)
			{
				cout << "Íåò äàííûõ" << endl;
				return;
			}

			do
			{
				system("cls");
				cout << "Ââåäèòå èíäåêñ" << endl;

				getInt(index);

				cout << endl << endl;
			} while ((index >= object.getSIZE()));

			object.Reset(index);
		}
		else if (switchValue == 7)
		{
			object.TotalReset(object);
			cout << "Âñå äàííûå î÷èùåíû" << endl << endl;
		}

		do
		{
			cout << "Õîòèòå ïðîäîëæèòü?\nÄëÿ ïðîäîëæåíèÿ ââåäèòå Y, äëÿ çàâåðøåíèÿ ïðîãðàììû ââåäèòå N" << endl << endl;

			getChar(Continuevalue);
		} while (Continuevalue != 'n' && Continuevalue != 'N' && Continuevalue != 'y' && Continuevalue != 'Y');

	} while (Continuevalue != 'n' && Continuevalue != 'N');

	Save(object);
	system("cls");
}
