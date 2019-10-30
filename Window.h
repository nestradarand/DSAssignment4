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
        int timeSpentIdle;
        int timeLeft;
        bool occupied;

        //
        int getTimeLeft();


};
#endif