#include "CurrancySave.h"

using namespace std;
using namespace std::filesystem;

void Save(Currancy& object)
{
	if (object.getAmount_size() == 0 && object.getExchange_size() == 0)
	{
		return;
	}

	if (!exists(object.getDirectoryPath()))
	{
		create_directory(object.getDirectoryPath());
	}

	ofstream outAmount(object.getAmountPath());
	if (!outAmount.is_open()) {
		cout << "Ошибка" << endl;
	}
	else
	{
		for (int i = 0; i < object.getAmount_size(); i++)
		{
			if (object.getAmount(i) == 0)
			{
				continue;
			}
			outAmount << object.getAmount(i) << " ";
		}
	}
	outAmount.close();

	ofstream outExchange(object.getExchangePath());
	if (!outExchange.is_open()) {
		cout << "Ошибка" << endl;
	}
	else
	{
		for (int i = 0; i < object.getExchange_size(); i++)
		{
			if (object.getExchange(i) == 0)
			{
				continue;
			}
			outExchange << object.getExchange(i) << " ";
		}
	}
	outExchange.close();

	ofstream outTotalAmount(object.getTotalAmountPath());
	if (!outTotalAmount.is_open())
	{
		cout << "Ошибка" << endl;
	}
	else
	{
		outTotalAmount << object.getTotalAmount();
	}
	outTotalAmount.close();

	cout << "Сохранено" << endl;
}