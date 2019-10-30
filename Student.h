#ifndef STUDENT_H
#define STUDENT_H

class Student
{
    public:
        Student();
        Student(int arrive,int atWindow);
        int getArrivalTime();
        int getTimeAtWindow();
        void updateTimeWaiting(int i );
        int getTimeWaiting();
        ~Student();
    private:
        int timeArrive;
        int timeAtWindow;
        int timeSpentWaiting;
};
#endif