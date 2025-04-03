#pragma once
#include "ClassCurrancy.h"
#include <string>
#include <filesystem>
#include <iomanip>
#include <iostream>

using namespace std;
using namespace std::filesystem;

class RusRuble : public Currancy
{
public:
	RusRuble()
	{
		this->setName("RusRuble");
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
	path DirectoryPath = "RusRuble";
	path ExchangePath = DirectoryPath / "Exchange_RusRuble.bin";
	path AmountPath = DirectoryPath / "Amount_RusRuble.bin";
	path TotalAmountPath = DirectoryPath / "TotalAmount_RusRuble.bin";
};

void RusRubleInteractionFunction();
