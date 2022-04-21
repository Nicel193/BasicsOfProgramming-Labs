#ifndef CALCULATIONAMOUNT_H
#define CALCULATIONAMOUNT_H

#pragma once

class CalculationAmount
{
public:
    CalculationAmount(int data);

    int GetData();
    static int GetSumData();

private:
    int data;
    static int sumData;
};

#endif

