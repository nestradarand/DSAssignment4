/*
Name: Noah Estrada-Rand
Student ID#: 2272490
Chapman email: estra146@mail.chapman.edu
Course Number and Section: CPSC-350-01
Assignment: Assignment 4 Registrar Simulation
*/
#include "Window.h"
#include <iostream>

using namespace std;

//default constructor
Window::Window()
{
    occupied = false;
    timeLeft = 0;
    timeSpentIdle = 0;
}
//destructor
Window::~Window()
{

}
//adds a tick for a minute spent idle
void Window::addIdleTick()
{
    timeSpentIdle ++;
}
//makes the window occupied for the time in the parameter
void Window::makeOccupied(int time)
{
    if(time < 0)
        throw std::runtime_error("Invalid wait time entered");
    timeLeft = time;
    occupied = true;
}
//decrements the tiem for one tick elapsed
void Window::oneTickElapsed()
{
    timeLeft --;
    if(timeLeft == 0)
        occupied = false;
}
//makes the window unoccupied
void Window::makeUnoccupied()
{
    occupied = false;
}
//checks to see if the window is occupied
bool Window::isOccupied()
{
    return occupied;
}
//returns the time spent idle
int Window::getIdleTime()
{
    return timeSpentIdle;
}
//returns the time left 
int Window::getTimeLeft()
{
    return timeLeft;
}