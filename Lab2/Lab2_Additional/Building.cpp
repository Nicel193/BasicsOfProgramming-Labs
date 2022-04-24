#include "../Header/Building.h"

Building::Building(string location)
{
    this->location = location;
}

EducationalBuilding::EducationalBuilding(string location, int numberOfCabinets) : Building(location)
{
    this->numberOfCabinets = numberOfCabinets;
}

void Building::GetDescription()
{
    cout << "Location: " << this->location << endl;
}

void EducationalBuilding::GetDescription()
{
    Building::GetDescription();
    cout << "NumberOfCabinets: " << this->numberOfCabinets << endl;
}