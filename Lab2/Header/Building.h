#ifndef HOUSE_H
#define HOUSE_H

#include <iostream>
using namespace std;

#pragma once

class Building
{
public:
    Building(string location);

    virtual void GetDescription();

protected:
    string location;
};

class EducationalBuilding : public Building
{
public:
    EducationalBuilding(string location, int numberOfCabinets);

    void GetDescription() override;

private:
    int numberOfCabinets;
};

#endif