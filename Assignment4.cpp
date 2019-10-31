/*
Name: Noah Estrada-Rand
Student ID#: 2272490
Chapman email: estra146@mail.chapman.edu
Course Number and Section: CPSC-350-01
Assignment: Assignment 4 Registrar Simulation
*/
#include <iostream>
#include <string>
#include <cstddef>
#include <fstream>
//load in the custom classes
#include "Student.h"
#include "Window.h"
#include "DLQueue.h"
#include "GenStack.h"
#include "MetricsHelper.h"



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
    //concatenate to get file path
    string totalFileName = string(argv[1]) + "/"+ string(argv[2]);
    ifstream inputStream;
    inputStream.open(totalFileName);//open the file using filestream
    if(!inputStream)
    {
        cout << "Error in opening specified file"<<endl;
        exit(1);
    }
    DLQueue<Student*> *studentQueue = new DLQueue<Student*>();//used to store the students
    //integers to be used to keep track of things
    int input,windowCount,timeArrive,numStudents,timeNeeded,studentCount = 0,index = 0;

    //to keep reading until there is nothing in the file
    while(inputStream >>input)
    {
        if(index == 0)//take the first number as the number of windows
            windowCount = input;
        else 
        {
            timeArrive = input;//gets the specified arrival time
            inputStream >> numStudents;//gets how many students to iterate through
            for(int i = 0; i<numStudents;++i)
            {
                //stores new students with the time they require at the window
                inputStream >> timeNeeded;
                studentQueue -> enqueue(new Student(timeArrive,timeNeeded));
                studentCount ++;
            }
        }
        index ++;
    }

    ///set up the windows
    Window **windows;//need an array of pointers to pointers to store the custom class
    windows =  new Window*[windowCount];
    //create the new indows for each spot in the array
    for(int i =0; i < windowCount;++i)
        windows[i] = new Window();    
    
    //close the file stream
    inputStream.close();
    cout <<"File successfully read from" <<endl;
    //this will be used to store the students for metric calculations
    GenStack<Student*> *studStack = new GenStack<Student*>(10);

    ///main functionality for registrar simulation
    //values to keep track of time and whether or not to keep the loop going
    int time = 0;
    bool end = false;
    while(!end)
    {
        if(!studentQueue -> isEmpty())//so long as the student queue has students waiting in line
        {
            Student *nextStudentUp = studentQueue -> peek();//peek at the student in front
            while(time >= nextStudentUp-> getArrivalTime())//while it is past the students' arrival time
            {
                //reset to true everytime so that if a student is not served at a window, we break the loop
                bool full = true;
                for(int i =0; i < windowCount;i++)//go through all windows
                {
                    if(!windows[i] -> isOccupied())//if a given window is not occupied
                    {
                        //make a window occupied 
                        windows[i] -> makeOccupied(nextStudentUp -> getTimeAtWindow());
                        //sets the student's time spent waiting
                        int timeWaiting = time - nextStudentUp ->getArrivalTime();
                        //references the student to be saved to the stack for later calculations
                        Student *studentToSave = studentQueue ->dequeue();
                        studentToSave-> updateTimeWaiting(timeWaiting);//updates that student's time spent waiting
                        studStack -> push(studentToSave);
                        full = false;
                        break;//used to move onto the next student
                    }
                    else 
                        continue;
                }
                if(full)//if there are no open windows
                    break;
                //if a student was served at a window, we check the next student to see if they have "arrived" yet
                if(studentQueue -> isEmpty())
                    break;
                else //if there are still students in line, check the next one's info
                {
                    nextStudentUp = studentQueue -> peek();
                }
            
            }
        }
        //while the time that the student arrived has passed
                
        time ++;//increment time

        //manages how time elapses for idle time and how long a window is occupied
        for(int i =0;i<windowCount;++i)
        {
            if(!windows[i] -> isOccupied())//if window is not occupied, add to its idle time
                windows[i] ->addIdleTick();
            else 
            {
                windows[i] -> oneTickElapsed();//otherwise decrement the time of the student at that window
            }
        }
        //case for stopping the simulation
        if(studentQueue -> isEmpty())//if the line of students is empty
        {
            bool stop = true;
            //check to see if any windows are still occupied, if so, continue the simulation
            for(int i =0; i <windowCount;++i)
                if(windows[i] ->isOccupied())
                    stop = false;//if any window is still in use, dont stop
            if(stop)//if windows not in use and student queue is empty, stop the simulation
                end = true;                    
        }
        
    }

    ///metrics calculations
    int *studentWaitTimes = new int[studentCount];//to store all student idle times
    for(int i =0;i <studentCount;++i)//get all student idle times
    {
        studentWaitTimes[i] = studStack->peek() ->getTimeWaiting();
        delete studStack -> pop();
    }
    //used to find the desired metrics
    MetricsHelper *metric = new MetricsHelper(studentWaitTimes, studentCount);
    cout << "Mean student wait time: " << metric -> getMean()<<endl;
    cout << "Median student wait time: " << metric->getMedian() << endl;
    cout << "Longest student wait time: " << metric->getMax() << endl;
    cout << "Number of students waiting over ten minutes: " << metric -> getNumberOver(10)<<endl;

    int *windowIdleTimes = new int[windowCount]; //to store window metrics (idleTimes)
    for (int i = 0; i < windowCount; ++i)
    {
        windowIdleTimes[i] = windows[i]->getIdleTime();
        delete windows[i];
    }
    //update the data being evaluated for
    metric ->setNewDataset(windowIdleTimes,windowCount);
    cout << "Mean window idle time: " << metric->getMean() << endl;
    cout << "Longest window idle time: " << metric->getMax() << endl;
    cout << "Number of windows idle for over five minutes: " << metric->getNumberOver(5) << endl;


    delete[] windows;
    delete metric;
    delete[] studentWaitTimes;
    delete [] windowIdleTimes;
    delete studStack;
    delete studentQueue;
    return 0;
}