#include <iostream>
using namespace std;

#ifndef HUMAN_H
#define HUMAN_H

#pragma once

class Human
{
public:
    virtual void GetDescription();
};

class Citizen : public Human
{
public:
    virtual void GetDescription() override;
};

class Student : public Citizen
{
public:
    virtual void GetDescription() override;
};

class Employee : public Citizen
{
public:
    virtual void GetDescription() override;
};

#endif