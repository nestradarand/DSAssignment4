#include "MetricsHelper.h"
#include <iostream>

using namespace std;

MetricsHelper::MetricsHelper()
{

}
//takes in an array by value to avoid pointer problems
MetricsHelper::MetricsHelper(int array[],int arraySize)
{
    baseDataSet = array;
    sizeOfArray = arraySize;
    sort();
}
MetricsHelper::~MetricsHelper()
{
    delete [] baseDataSet;
}
//takes in an array by value and its size
void MetricsHelper::setNewDataset(int array[], int arraySize)
{
    baseDataSet = array;
    sizeOfArray = arraySize;
    sort();
}
float MetricsHelper::getMean()
{
    int sum = 0;
    for(int i =0; i <sizeOfArray;++i)
    {
        sum = sum + baseDataSet[i];
    }
    return (float(sum)/float(sizeOfArray));
}
float MetricsHelper::getMedian()
{
    int medianPosition = (sizeOfArray + 1) / 2;
    if(sizeOfArray %2 != 0)        
        return baseDataSet[medianPosition - 1]; //use minus one to account for base zero
    else
        return(float(baseDataSet[medianPosition-1]) +
        float(float(baseDataSet[medianPosition])-float(baseDataSet[medianPosition-1]))/2);
    
    
    
}
int MetricsHelper::getMax()
{
    return baseDataSet[sizeOfArray-1];
}
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
void MetricsHelper::printArray()
{
    for(int i =0; i <sizeOfArray;++i)
        cout << baseDataSet[i] <<endl;
}
int MetricsHelper::getNumberOver(int bound)
{
    int sum = 0;
    for(int i = 0; i<sizeOfArray;++i)
        if(baseDataSet[i] >bound)
            sum ++;
    return sum;
}