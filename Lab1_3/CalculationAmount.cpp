#include "../Header/CalculationAmount.h"

int CalculationAmount::sumData = 0;

CalculationAmount::CalculationAmount(int data)
{
    this->data = data;
    this->sumData += data;
}

int CalculationAmount::GetData()
{
    return this->data;
}

int CalculationAmount::GetSumData()
{
    return sumData;
}

