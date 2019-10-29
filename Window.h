#ifndef WINDOW_H
#define WINDOW_H

class Window
{
    public:
        Window();
        ~Window();
        void addOneTickIdle();
        void makeOccupied();
        void makeUnoccupied();
        bool isOccupied();
        int getIdleTime();
        int timeSpentIdle = 0;
        bool occupied = false;


};
#endif