/*
Name: Noah Estrada-Rand
Student ID#: 2272490
Chapman email: estra146@mail.chapman.edu
Course Number and Section: CPSC-350-01
Assignment: Assignment 4 Registrar Simulation
*/
#ifndef METRICSHELPER_H
#define METRTICSHELPER_H

/*This class is to be used to store an array of numbers and calculate various statistics therein
*/
class MetricsHelper
{
    public:
    //basic constructors
        MetricsHelper();
        MetricsHelper(int array[],int arraySize);
        //destructors
        ~MetricsHelper();
        //updates the data to get all the following metrics from an array and its size
        void setNewDataset(int array[],int arraySize);
        //returns the summary statistics for the data stored as an array in this instance
        //returns mean
        float getMean();
        //returns median
        float getMedian();
        //returns the maximum
        int getMax();
        //print the array for debugging purposes
        void printArray();
        //returns all numbers greater than the parameter
        int getNumberOver(int i );
    private:
        //used to sort the data in ascending order
        void sort();
        //points to the array being stored for analysis
        int *baseDataSet;
        //stores the size of the array
        int sizeOfArray;
};
#endif