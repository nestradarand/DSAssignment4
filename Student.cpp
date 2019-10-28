#include "Student.h"
#include <iostream>
#include <cstddef>

using namespace std;

Student::Student()
{
    
}
Student::Student(int arrive, int window)
{
    if(arrive < 0 || window <0)
        throw new std::runtime_error("Invalid values passed to student constructor");
    timeArrive = arrive;
    timeAtWindow = window;
}
Student::~Student()
{
    
}
int Student::getArrivalTime()
{
    return timeArrive;
}
int Student::getTimeAtWindow()
{
    return timeAtWindow;
}