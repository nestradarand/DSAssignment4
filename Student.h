#ifndef STUDENT_H
#define STUDENT_H

class Student
{
    public:
        Student();
        Student(int arrive,int atWindow);
        int getArrivalTime();
        int getTimeAtWindow();
        ~Student();
    private:
        int timeArrive;
        int timeAtWindow;
};
#endif