#include <iostream>
#include <string>
#include "Student.h"
#include "Window.h"
#include "DLQueue.h"


using namespace std;

int main(int argc,char** argv)
{
    // Student *stud1 = new Student(0,1);
    // Student *stud2 = new Student(1,1);
    // Student *stud3 = new Student(2,1);
    // Student *stud4 = new Student(3,2);
    // Student *holder[4];
    // holder[0] = stud1;
    // holder[1] = stud2;
    // holder[2] = stud3;
    // holder[3] = stud4;
    DLQueue<int> *queue = new DLQueue<int>();
    for(int i =0; i <200; ++i)
        queue -> enqueue(i);
    while(!queue -> isEmpty())
        cout << queue -> dequeue() <<endl;
    delete queue;
    



    return 0;
}