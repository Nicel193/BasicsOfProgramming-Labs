#ifndef DIGITALDEVICE_H
#define DIGITALDEVICE_H

#include <iostream>
using namespace std;

#pragma once

class DigitalDevice
{
public:
    DigitalDevice(string nameDevice);

    virtual void GetDescription();

protected:
    string nameDevice;
};

class Cellphone : public DigitalDevice
{
public:
    Cellphone(string nameDevice, int memorySize, float screenDiagonal);

    void GetDescription() override;

private:
    int memorySize;
    float screenDiagonal;
};

#endif