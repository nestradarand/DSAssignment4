#include <iostream>
#include <string>
#include "Student.h"
#include "Window.h"
#include "DLQueue.h"
#include "GenStack.h"
#include <cstddef>


using namespace std;

int main(int argc,char** argv)
{
    Student *stud1 = new Student(0,1);
    Student *stud2 = new Student(1,10);
    Student *stud3 = new Student(11,1);
    // Student *stud4 = new Student(3,2);
    DLQueue<Student*> *studentQueue = new DLQueue<Student*>();
    //stack to store the stuedents once they are served
    GenStack<Student*> *studStack = new GenStack<Student*>(10);
    studentQueue -> enqueue(stud1);
    studentQueue -> enqueue(stud2);
    studentQueue -> enqueue(stud3);
    // studentQueue -> enqueue(stud4);

    

    ///MUST HAVE THE NUMBER OF WINDOWS FOR THIS TO WORK
    const int winSize = 2;
    Window *win1 = new Window();
    Window *win2 = new Window();
    Window *windows[winSize];
    windows[0] = win1;
    windows[1] = win2;




    ///main functionality for registrat simulation
    int time = 0;
    bool end = false;
    while(!end)
    {
        if(!studentQueue -> isEmpty())
        {
            Student *nextStudentUp = studentQueue -> peek();
            while(time >= nextStudentUp-> getArrivalTime())
            {
                //reset to true everytime so that if a student is not served at a window, we break the loop
                bool full = true;
                for(int i =0; i < winSize;i++)//go through all windows
                {
                    if(!windows[i] -> isOccupied())
                    {
                        cout << "Student served at a time :" << time << " on window " << i<< endl;
                        cout << "time needed : " << nextStudentUp -> getTimeAtWindow()<<endl;
                        windows[i] -> makeOccupied(nextStudentUp -> getTimeAtWindow());
                        //sets the student's time spent waiting
                        int timeWaiting = time - nextStudentUp ->getArrivalTime();
                        //references the student to be saved to the stack for later calculations
                        Student *studentToSave = studentQueue ->dequeue();
                        studentToSave-> updateTimeWaiting(timeWaiting);//updates that student's time spent waiting
                        studStack -> push(studentToSave);
                        full = false;
                        break;
                    }
                    else 
                        cout << "Window " << i<< " is Occupied"<<endl;
                }
                if(full)
                    break;
                //if a student was served at a window, we check the next student to see if they have "arrived" yet
                if(studentQueue -> isEmpty())
                    break;
                else 
                {
                    nextStudentUp = studentQueue -> peek();
                }
            
            }
        }
        //while the time that the student arrived has passed
                
        time ++;//increment time

        //manages how time elapses for idle time and how long a window is occupied
        //works
        for(int i =0;i<winSize;++i)
        {
            if(!windows[i] -> isOccupied())
                windows[i] ->addIdleTick();
            else 
            {
                windows[i] -> oneTickElapsed();
                //used for debugging
                // cout << "At time " << time << " window " << i << " has: " << windows[i] ->getTimeLeft() << " left" <<endl;
            }
        }
        //case for stopping the simulation
        if(studentQueue -> isEmpty())
        {
            bool stop = true;
            for(int i =0; i <winSize;++i)
                if(windows[i] ->isOccupied())
                    stop = false;//if any window is still in use, dont stop
            if(stop)//if windows not in use and student queue is empty, stop the simulation
                end = true;                    
        }
        
    }
    //DEBUGGING to check if time spent idle works and it does
    for(int i =0;i<winSize;++i)
        cout << "Time spent Idle: " << windows[i] ->getIdleTime() <<endl;
    //DEBUGGING to see if time waiting works and it does
    while(!studStack ->isEmpty())
    {
        cout <<"Time spent waiting: "<< studStack -> peek() -> getTimeWaiting() <<endl;
        delete studStack -> pop();
    }
    delete win1;
    delete win2;

    delete studStack;
    delete studentQueue;
    return 0;
}