/*
Name: Noah Estrada-Rand
Student ID#: 2272490
Chapman email: estra146@mail.chapman.edu
Course Number and Section: CPSC-350-01
Assignment: Assignment 4 Registrar Simulation
*/
#ifndef WINDOW_H
#define WINDOW_H

//Window class to store idle times and to simulate students being served in the registrar
class Window
{
    public:
        //construtor destructor
        Window();
        ~Window();
        //adds to the count of time spent idle 
        void addIdleTick();
        //makes the window occupied for the specified amount of time passed as a parameter
        void makeOccupied(int time);
        //decrement the time left for the window
        void oneTickElapsed();
        //makes the window unoccupied (boolean value change)
        void makeUnoccupied();
        //returns if the window is occupied or not
        bool isOccupied();
        //returns the time spent idle for a window
        int getIdleTime();
        //stores the time spent idle, the time left for the current student, and whether the window is occupied
        int timeSpentIdle;
        int timeLeft;
        bool occupied;

        //return the time left for a student being served
        int getTimeLeft();


};
#endif