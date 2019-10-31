/*
Name: Noah Estrada-Rand
Student ID#: 2272490
Chapman email: estra146@mail.chapman.edu
Course Number and Section: CPSC-350-01
Assignment: Assignment 4 Registrar Simulation
*/
#include "Student.h"
#include <iostream>
#include <cstddef>

using namespace std;

//default constructor
Student::Student()
{
    timeSpentWaiting = 0;
}
//arrival time and window time constructor
Student::Student(int arrive, int window)
{
    if(arrive < 0 || window <0)
        throw new std::runtime_error("Invalid values passed to student constructor");
    timeArrive = arrive;
    timeAtWindow = window;
    timeSpentWaiting = 0;
}
//destructor
Student::~Student()
{
    
}
//return the arrival time
int Student::getArrivalTime()
{
    return timeArrive;
}
//return the arrival time of the student
int Student::getTimeAtWindow()
{
    return timeAtWindow;
}
//set the time spent waiting
void Student::updateTimeWaiting(int i)
{
    if(i <0)
        throw std::runtime_error("Time entered is negative for wait time");
    timeSpentWaiting = i;
}
//returns the time waiting
int Student::getTimeWaiting()
{
    return timeSpentWaiting;
}