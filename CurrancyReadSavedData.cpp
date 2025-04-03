#include "CurrancyReadSavedData.h"

using namespace std;
using namespace std::filesystem;

void ReadSavedData(Currancy& object)
{
	if (!exists(object.getDirectoryPath()))
	{
		return;
	}

	ifstream inAmount(object.getAmountPath());
	if (!inAmount.is_open())
	{
		cout << "Ошибка открытия сохранённых данных" << endl;
	}
	else if (inAmount.peek() == EOF)
	{
		cout << "У вас нет сохранённых данных" << endl << endl;
		inAmount.close();
		return;
	}
	else
	{
		double temp = 0;
		while (inAmount >> temp)
		{
			object.setNewAmountVal(temp);
		}
	}
	inAmount.close();

	ifstream inExchange(object.getExchangePath());
	if (!inExchange.is_open())
	{
		cout << "Ошибка открытия сохранённых данных" << endl;
	}
	else if (inExchange.peek() == EOF)
	{
		cout << "У вас нет сохранённых данных" << endl << endl;
		inExchange.close();
		return;
	}
	else
	{
		double temp = 0;
		while (inExchange >> temp)
		{
			object.setNewExchangeVal(temp);
		}
	}
	inExchange.close();

	ifstream inTotalAmount(object.getTotalAmountPath());
	if (!inTotalAmount.is_open())
	{
		cout << "Ошибка открытия сохранённых данных" << endl;
	}
	else if (inTotalAmount.peek() == EOF)
	{
		cout << "У вас нет сохранённых данных" << endl << endl;
		inTotalAmount.close();
		return;
	}
	else
	{
		double temp;
		inTotalAmount >> temp;
		object.setTotalAmount(temp);
	}
	inTotalAmount.close();
}