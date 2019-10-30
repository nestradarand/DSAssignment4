#include "Student.h"
#include <iostream>
#include <cstddef>

using namespace std;

Student::Student()
{
    timeSpentWaiting = 0;
}
Student::Student(int arrive, int window)
{
    if(arrive < 0 || window <0)
        throw new std::runtime_error("Invalid values passed to student constructor");
    timeArrive = arrive;
    timeAtWindow = window;
    timeSpentWaiting = 0;
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
void Student::updateTimeWaiting(int i)
{
    if(i <0)
        throw std::runtime_error("Time entered is negative for wait time");
    timeSpentWaiting = i;
}
int Student::getTimeWaiting()
{
    return timeSpentWaiting;
}