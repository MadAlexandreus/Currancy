#pragma once
#include "ClassCurrancy.h"
#include <string>
#include <filesystem>
#include <iomanip>
#include <iostream>

using namespace std;
using namespace std::filesystem;

class Euro : public Currancy
{
public:
	Euro()
	{
		this->setName("Euro");
	}

	path getExchangePath() override
	{
		return ExchangePath;
	}
	path getAmountPath() override
	{
		return AmountPath;
	}
	path getTotalAmountPath() override
	{
		return TotalAmountPath;
	}
	path getDirectoryPath() override
	{
		return DirectoryPath;
	}

private:
	path DirectoryPath = "Euro";
	path ExchangePath = DirectoryPath / "Exchange_Euro.bin";
	path AmountPath = DirectoryPath / "Amount_Euro.bin";
	path TotalAmountPath = DirectoryPath / "TotalAmount_Euro.bin";
};

void EuroInteractionFunction();