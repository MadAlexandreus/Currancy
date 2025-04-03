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

			cout << std::setw(92) << std::left << "Выберите, что вы хотите сделать:" << endl << endl;
			cout << std::setw(92) << std::left << "Получить полное количество валюты" << "1" << endl << endl;
			cout << std::setw(92) << std::left << "Получить разбиение валюты по разым курсам" << "2" << endl << endl;
			cout << std::setw(92) << std::left << "Рассчитать рекомендованный обменный курс для конкретной покупки (Желательно знать индекс)" << "3" << endl << endl;
			cout << std::setw(92) << std::left << "Рассчитать рекомендованный обменный курс для всей суммы" << "4" << endl << endl;
			cout << std::setw(92) << std::left << "Добавить новую покупку" << "5" << endl << endl;
			cout << std::setw(92) << std::left << "Удалить покупку по конкретному индексу" << "6" << endl << endl;
			cout << std::setw(92) << std::left << "Очистить все данные" << "7" << endl << endl;

			getInt(switchValue);
		} while (switchValue != 1 && switchValue != 2 && switchValue != 3 && switchValue != 4 && switchValue != 5 && switchValue != 6 && switchValue != 7);


		system("cls");

		if (switchValue == 1)
		{
			cout << "Полное количество валюты:" << endl << object.getTotalAmount() << endl << endl;

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
				cout << "Нет данных" << endl;
				return;
			}

			do
			{
				system("cls");
				cout << "Введите индекс" << endl;

				getInt(index);

				cout << endl << endl;
			} while ((index >= object.getSIZE()));

			if (std::filesystem::exists(object.getDirectoryPath()))
			{
				if (object.getDirectoryPath().empty()) {
					cout << "Нет данных" << endl;
					return;
				}
			}
			else
			{
				cout << "Нет данных" << endl;
				return;
			}

			cout << "Рекомендованный обменный курс для конкретной покупки:" << endl << object.CalcRecExchange(index) << endl << endl;
		}
		else if (switchValue == 4)
		{
			if (std::filesystem::exists(object.getDirectoryPath()))
			{
				if (object.getDirectoryPath().empty()) {
					cout << "Нет данных" << endl;
					return;
				}
			}
			else
			{
				cout << "Нет данных" << endl;
				return;
			}

			cout << "Рекомендованный обменный курс для всей суммы" << endl << object.CalcTotalRecExchange() << endl << endl;
		}
		else if (switchValue == 5)
		{
			cout << "Если вы хотите внести новую сумму по старому курсу ввдедите <Old>, для новой суммы -- <New>" << endl;

			string Modifier;
			cin >> Modifier;				//пока хз как лучше переписать и переписывать ли

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
				cout << "Нет данных" << endl;
				return;
			}
			do
			{
				system("cls");
				cout << "Введите индекс" << endl;

				getInt(index);

				cout << endl << endl;
			} while ((index >= object.getSIZE()));

			object.Reset(index);
		}
		else if (switchValue == 7)
		{
			object.TotalReset(object);
			cout << "Все данные очищены" << endl << endl;
		}

		do
		{
			cout << "Хотите продолжить?\nДля продолжения введите Y, для завершения программы введите N" << endl << endl;

			getChar(Continuevalue);
		} while (Continuevalue != 'n' && Continuevalue != 'N' && Continuevalue != 'y' && Continuevalue != 'Y');

	} while (Continuevalue != 'n' && Continuevalue != 'N');

	system("cls");
	Save(object);
}