#pragma once
#include "ClassCurrancy.h"
#include <string>
#include <filesystem>
#include <iomanip>
#include <iostream>

using namespace std;
using namespace std::filesystem;

class Dollar : public Currancy
{
public:
	Dollar()
	{
		this->setName("Dollar");
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
	path DirectoryPath = "Dollar";
	path ExchangePath = DirectoryPath / "Exchange_Dollar.bin";
	path AmountPath = DirectoryPath / "Amount_Dollar.bin";
	path TotalAmountPath = DirectoryPath / "TotalAmount_Dollar.bin";
};

void DollarInteractionFunction();
