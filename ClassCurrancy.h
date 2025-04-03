#pragma once
#include <string>
#include <vector>
#include <filesystem>
#include <iostream>

using namespace std;
using namespace std::filesystem;

class Currancy
{
public:
	Currancy()
	{
		TotalAmount = 0;
	}
	Currancy(double p_LastExchange, double p_Amount)
	{
		Exchange[0] = p_LastExchange;

		Amount[0] = p_Amount;

		TotalAmount += p_Amount;
	}

	void getName() const { cout << "Name:\t" << Name << endl; }
	double getTotalAmount() const { return TotalAmount; }
	double getAmount(int IndexOfAmount) const { return Amount[IndexOfAmount]; }
	double getExchange(int IndexOfExchange) const { return Exchange[IndexOfExchange]; }

	size_t getSIZE() const { return Amount.size(); }
	size_t getAmount_size() const { return Amount.size(); }
	size_t getExchange_size() const { return Exchange.size(); }


	void setTotalAmount(double value) { this->TotalAmount = value; }
	void setNewAmountVal(double value) { Amount.push_back(value); }
	void setNewExchangeVal(double value) { Exchange.push_back(value); }

	void addPurchase(string Modifier);

	double CalcRecExchange(int index);

	double CalcTotalRecExchange();

	void TotalReset(Currancy& object);

	void Reset(int index);

	virtual path getExchangePath() = 0;
	virtual path getAmountPath() = 0;
	virtual path getTotalAmountPath() = 0;
	virtual path getDirectoryPath() = 0;

private:
	string Name;

	double TotalAmount = 0;

	vector<double> Amount;
	vector<double> Exchange;

protected:
	void setName(string _Name)
	{
		Name = _Name;
	}
};

bool getInt(int& value);
bool getChar(char& value);
bool getDouble(double& value);