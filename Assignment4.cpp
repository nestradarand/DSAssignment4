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
    Student *stud1 = new Student(1,3);
    Student *stud2 = new Student(2,6);
    Student *stud3 = new Student(5,1);
    // Student *stud4 = new Student(3,2);
    DLQueue<Student*> *studentQueue = new DLQueue<Student*>();
    //stack to store the stuedents once they are served
    GenStack<Student*> *studStack = new GenStack<Student*>(10);
    studentQueue -> enqueue(stud1);
    studentQueue -> enqueue(stud2);
    studentQueue -> enqueue(stud3);
    // studentQueue -> enqueue(stud4);

    

    ///5 is arbitrary
    const int winSize = 1;
    Window *win1 = new Window();
    // Window *win2 = new Window();
    Window *windows[winSize];
    windows[0] = win1;
    // windows[1] = win2;

    // windows[0] -> makeOccupied(studentQueue -> peek() ->getTimeAtWindow());
    // while(windows[0] -> isOccupied())
    // {
    //     cout << "Is occupied? :" <<windows[0] -> isOccupied()<<endl;
    //     cout << windows[0] -> getTimeLeft() <<endl;
    //     windows[0]->oneTickElapsed();
    // }
    // cout << "Is occupied? :" <<windows[0] -> isOccupied()<<endl;



    ///main functionality for registrat simulation
    int time = 0;
    while(true)
    {
        Student *nextStudentUp = studentQueue -> peek();
        //while the time that the student arrived has passed
        while(time >= nextStudentUp-> getArrivalTime())
        {
            //need to figure out how to use full to make sure we break if the windows are full
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
            try 
            {
                nextStudentUp = studentQueue -> peek();
            }
            catch(std::runtime_error e1)
            {
                break;
            }
            
        }
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
                break;                    
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
    // delete win2;

    delete studStack;
    delete studentQueue;
    return 0;
}