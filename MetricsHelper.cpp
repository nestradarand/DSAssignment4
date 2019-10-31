/*
Name: Noah Estrada-Rand
Student ID#: 2272490
Chapman email: estra146@mail.chapman.edu
Course Number and Section: CPSC-350-01
Assignment: Assignment 4 Registrar Simulation
*/
#include "MetricsHelper.h"
#include <iostream>

using namespace std;

MetricsHelper::MetricsHelper()
{

}
//takes in an array by value to avoid pointer problems and array size
MetricsHelper::MetricsHelper(int array[],int arraySize)
{
    baseDataSet = array;
    sizeOfArray = arraySize;
    sort();//sorts the data in ascending order
}
//deletes the stored away
MetricsHelper::~MetricsHelper()
{
    delete [] baseDataSet;
}
//takes in an array by value and its size
void MetricsHelper::setNewDataset(int array[], int arraySize)
{
    baseDataSet = array;
    sizeOfArray = arraySize;
    sort();//sorts the data in ascending order
}
//returns the mean of the data
float MetricsHelper::getMean()
{
    int sum = 0;
    for(int i =0; i <sizeOfArray;++i)
    {
        sum = sum + baseDataSet[i];
    }
    //finds the sum of all the numbers then divides by the number of numbers
    return (float(sum)/float(sizeOfArray));
}
//returns the median of the data set
float MetricsHelper::getMedian()
{
    //definition of median position
    int medianPosition = (sizeOfArray + 1) / 2;
    //if the length of the dataset is not even
    if(sizeOfArray %2 != 0)        
        return baseDataSet[medianPosition - 1]; //use minus one to account for base zero
    // if the length of the dataset is even, add the midpoint of the distance from the median point to the next one
    else
        return(float(baseDataSet[medianPosition-1]) +
        float(float(baseDataSet[medianPosition])-float(baseDataSet[medianPosition-1]))/2);    
}
//returns the maximum value of the dataset
int MetricsHelper::getMax()
{
    return baseDataSet[sizeOfArray-1];
}
//sort sthe data in ascending order
void MetricsHelper::sort()//puts stored array of values in ascending order
{
    for(int i = 0; i < sizeOfArray; ++i)//for all numbers in the array
    {
        for(int j = (i + 1); j < sizeOfArray; ++j)//looks at the next value in line
        {
            if(baseDataSet[i] > baseDataSet[j])
            {
                //have both values switch spots if next value in line is less than the current position
                int a = baseDataSet[i];
                baseDataSet[i] = baseDataSet[j];
                baseDataSet[j] = a;
            }
        }
    }
}
//used for debugging purposes to ensure the array was sorted correctly
void MetricsHelper::printArray()
{
    for(int i =0; i <sizeOfArray;++i)
        cout << baseDataSet[i] <<endl;
}
//returns the number of numbers greater than the specified value
int MetricsHelper::getNumberOver(int bound)
{
    int sum = 0;
    for(int i = 0; i<sizeOfArray;++i)
        if(baseDataSet[i] >bound)
            sum ++;
    return sum;
}