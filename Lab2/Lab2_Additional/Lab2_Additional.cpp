#include <iostream>
#include "../Header/Building.h"
#include "../Header/DigitalDevice.h"
#include "Pair.cpp"

using namespace std;

void Task1();
void Task2();
void Task3();
void Task4();

template <typename T1>
void TaskArrayRange(T1 *array, T1 min, T1 max, int arraySize);
template <typename T1>
bool inRange(T1 min, T1 max, T1 x);

int main()
{
    cout << "Task 1:" << endl;
    Task1();
    cout << "Task 2:" << endl;
    Task2();
    cout << "Task 3:" << endl;
    Task3();
    cout << "Task 4:" << endl;
    Task4();

    system("pause");
}

void Task1()
{
    const int n = 3;

    Building *buildings[n] = {new Building("Kyiv"),
                              new EducationalBuilding("Kyiv", 45),
                              new EducationalBuilding("Poltava", 24)};

    for (int i = 0; i < n; i++)
    {
        buildings[i]->GetDescription();
        cout << endl;
    }
}

void Task2()
{
    const int n = 2;

    DigitalDevice *digitalDevices[n] = {new Cellphone("Xiaomi", 8, 5.5),
                                        new Cellphone("Apple", 16, 6)};

    for (int i = 0; i < n; i++)
    {
        digitalDevices[i]->GetDescription();
        cout << endl;
    }
}

void Task3()
{
    const int n = 6;

    cout << "Int:" << endl;
    int a[n] = {3, 7, 4, 9, -4, 8};

    TaskArrayRange(a, 4, 8, n);

    cout << endl;

    cout << "Double:" << endl;
    double b[n] = {3.6, 7, 2.1, .005, -8, 9.5};

    TaskArrayRange(b, 2.5, 7.5, n);

    cout << endl;
}

void Task4()
{
    cout << "Int, Double: " << endl;
    Pair<int, double> a(5, 6.5);

    cout << "FirstValue: " << a.GetFirstValue() << endl
         << "SecondValue: " << a.GetSecondValue() << endl;

    cout << endl;

    cout << "Char, Bool: " << endl;
    Pair<char, bool> b('t', true);

    cout << "FirstValue: " << b.GetFirstValue() << endl
         << "SecondValue: " << b.GetSecondValue() << endl;
}

template <typename T1>
void TaskArrayRange(T1 *array, T1 min, T1 max, int arraySize)
{
    cout << "In range: ";

    for (int i = 0; i < arraySize; i++)
    {
        if (inRange(min, max, array[i]))
        {
            cout << array[i] << " ";
        }
    }

    cout << endl;
}

template <typename T1>
bool inRange(T1 min, T1 max, T1 x)
{
    return (min <= x && x <= max);
}