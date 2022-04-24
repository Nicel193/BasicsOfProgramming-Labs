#include <iostream>
#include "../Header/Human.h"

using namespace std;

int main()
{

    const int n = 4;

    Human *groop[n] = {new Human,
                       new Student,
                       new Citizen,
                       new Employee};

    for (int i = 0; i < n; i++)
    {
        groop[i]->GetDescription();
    }
    for (int i = 0; i < n; i++)
    {
        delete groop[i];
    }

    system("pause");
}