#include <iostream>
#include <string>
#include "Student.h"
#include "Window.h"
#include "DLQueue.h"
#include "GenStack.h"
#include <cstddef>
#include <fstream>


using namespace std;

int main(int argc,char** argv)
{
    //if no file path entered, program exits
    if(!argv[1])
    {
        cout << "No file path entered. Program aborted..."<<endl;
        exit(1);
    } 
  // if no file name entered, prgram exits
    if(!argv[2])
    {
        cout << "No file name entered. Program aborted..."<<endl;
        exit(1);
    }
    string totalFileName = string(argv[1]) + "/"+ string(argv[2]);
    ifstream inputStream;
    inputStream.open(totalFileName);
    if(!inputStream)
    {
        cout << "Error in opening specified file"<<endl;
        exit(1);
    }
    cout << "File successfully opened" << endl;
    DLQueue<Student*> *studentQueue = new DLQueue<Student*>();
    int input,windowCount,timeArrive,numStudents,timeNeeded;
    int index = 0;

    while(inputStream >>input)
    {
        if(index == 0)
            windowCount = input;
        else 
        {
            timeArrive = input;//gets the specified arrival time
            inputStream >> numStudents;//gets how many students to iterate through
            for(int i = 0; i<numStudents;++i)
            {
                inputStream >> timeNeeded;
                studentQueue -> enqueue(new Student(timeArrive,timeNeeded));
            }
        }
        index ++;
    }

    ///set up the windows
    Window **windows;//need an array of pointers to pointers to store the custom class
    windows =  new Window*[windowCount];//works
    for(int i =0; i < windowCount;++i)
        windows[i] = new Window();    
    //to delete the array of windows
    for(int i =0; i <windowCount;++i)
        delete windows[i];
    delete [] windows;
    inputStream.close();
    cout <<"File successfully read from" <<endl;
    GenStack<Student*> *studStack = new GenStack<Student*>(10);


    //DEBUGGING
    // while(!studentQueue -> isEmpty())
    // {
    //     cout <<"Time needed at windows: "<< studentQueue->dequeue()->getArrivalTime() << endl;
    // }


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
                for(int i =0; i < windowCount;i++)//go through all windows
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
        for(int i =0;i<windowCount;++i)
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
            for(int i =0; i <windowCount;++i)
                if(windows[i] ->isOccupied())
                    stop = false;//if any window is still in use, dont stop
            if(stop)//if windows not in use and student queue is empty, stop the simulation
                end = true;                    
        }
        
    }
    //DEBUGGING to check if time spent idle works and it does
    for(int i =0;i<windowCount;++i)
        cout << "Time spent Idle: " << windows[i] ->getIdleTime() <<endl;
    //DEBUGGING to see if time waiting works and it does
    while(!studStack ->isEmpty())
    {
        cout <<"Time spent waiting: "<< studStack -> peek() -> getTimeWaiting() <<endl;
        delete studStack -> pop();
    }


    delete studStack;
    delete studentQueue;
    return 0;
}