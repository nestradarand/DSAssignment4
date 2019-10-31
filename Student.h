/*
Name: Noah Estrada-Rand
Student ID#: 2272490
Chapman email: estra146@mail.chapman.edu
Course Number and Section: CPSC-350-01
Assignment: Assignment 4 Registrar Simulation
*/
#ifndef STUDENT_H
#define STUDENT_H

//Class representing a student to store arrival time, time at the window and waiting time
class Student
{
    public:
        //default constructor
        Student();
        //takes in two integers as the arrival time and time needed at window
        Student(int arrive,int atWindow);
        //returns the arrival time of the student
        int getArrivalTime();
        //returns how much time the student needs at the window
        int getTimeAtWindow();
        //sets the time waiting for the student
        void updateTimeWaiting(int i );
        //returns the waiting time for the student
        int getTimeWaiting();
        //destructor
        ~Student();
    private:
        //stores arrival time, time at window, and time spent waiting
        int timeArrive;
        int timeAtWindow;
        int timeSpentWaiting;
};
#endif