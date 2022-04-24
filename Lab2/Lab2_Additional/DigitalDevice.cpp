#include "../Header/DigitalDevice.h"

DigitalDevice::DigitalDevice(string nameDevice)
{
    this->nameDevice = nameDevice;
}

Cellphone::Cellphone(string nameDevice, int memorySize, float screenDiagonal) : DigitalDevice(nameDevice)
{
    this->memorySize = memorySize;
    this->screenDiagonal = screenDiagonal;
}

void DigitalDevice::GetDescription()
{
    cout << "NameDevice: " << this->nameDevice << endl;
}

void Cellphone::GetDescription()
{
    DigitalDevice::GetDescription();
    cout << "MemorySize: " << this->memorySize << endl;
    cout << "ScreenDiagonal: " << this->screenDiagonal << endl;
}
