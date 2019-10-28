#include <iostream>
#include <string>
#include "Student.h"

using namespace std;

int main(int argc,char** argv)
{
    Student *stud1 = new Student(0,1);
    Student *stud2 = new Student(1,1);
    Student *stud3 = new Student(2,1);
    Student *stud4 = new Student(3,2);
    Student *holder[4];
    holder[0] = stud1;
    holder[1] = stud2;
    holder[2] = stud3;
    holder[3] = stud4;
    

    
  
    return 0;
}