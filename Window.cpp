#include "Window.h"
#include <iostream>

using namespace std;

Window::Window()
{

}
Window::~Window()
{

}
void Window::addIdleTick()
{
    timeSpentIdle ++;
}
void Window::makeOccupied(int time)
{
    if(time < 0)
        throw std::runtime_error("Invalid wait time entered");
    timeLeft = time;
    occupied = true;
}
void Window::oneTickElapsed()
{
    if(timeLeft <=0)
        throw std::runtime_error("time attempting to be decremented past zero");
    timeLeft --;
}
void Window::makeUnoccupied()
{
    occupied = false;
}
bool Window::isOccupied()
{
    return occupied;
}
int Window::getIdleTime()
{
    return timeSpentIdle;
}
int Window::getTimeLeft()
{
    return timeLeft;
}