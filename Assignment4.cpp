#include <iostream>
#include <string>
#include "Student.h"
#include "Window.h"
#include "DLQueue.h"


using namespace std;

int main(int argc,char** argv)
{
    Student *stud1 = new Student(0,1);
    Student *stud2 = new Student(1,1);
    Student *stud3 = new Student(2,1);
    Student *stud4 = new Student(3,2);
    //must initialize with pointers since we are going to be storing pointers essentially
    DLQueue<Student*> *studentQueue = new DLQueue<Student*>();
    studentQueue -> enqueue(stud1);
    studentQueue -> enqueue(stud2);
    studentQueue -> enqueue(stud3);
    studentQueue -> enqueue(stud4);



    ///5 is arbitrary
    int winSize = 5;
    Window *win1 = new Window();
    Window *windows[5];


    ///main functionality for registrat simulation
    int time = 0;
    while(true)
    {
        while(time <= studentQueue -> peek()-> getArrivalTime())
        {
            //need to figure out how to use full to make sure we break if the windows are full
            bool full = true;
            for(int i =0; i < winSize;i++)
            {
                if(!windows[i] -> isOccupied())
                {
                    windows[i] -> makeOccupied(studentQueue -> dequeue() -> getArrivalTime());
                    full = false;
                    break;
                }

            }
            if(full)
                break;
            
        }
        for(int i =0;i<winSize;++i)
        {
            if(!windows[i] -> isOccupied())
                windows[i] ->addIdleTick();
            else 
                windows[i] -> oneTickElapsed();
        }
        time ++;
    }
    
    delete studentQueue;
    return 0;
}