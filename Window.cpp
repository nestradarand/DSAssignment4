#include "Window.h"
#include <iostream>

using namespace std;

Window::Window()
{

}
Window::~Window()
{

}
void Window::addOneTickIdle()
{
    timeSpentIdle ++;
}
void Window::makeOccupied()
{
    occupied = true;
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