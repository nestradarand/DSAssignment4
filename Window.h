#ifndef WINDOW_H
#define WINDOW_H

class Window
{
    public:
        Window();
        ~Window();
        void addIdleTick();
        void makeOccupied(int time);
        void oneTickElapsed();
        void makeUnoccupied();
        bool isOccupied();
        int getIdleTime();
        int timeSpentIdle = 0;
        int timeLeft = 0;
        bool occupied = false;

        //
        int getTimeLeft();


};
#endif