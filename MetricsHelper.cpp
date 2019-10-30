#include "MetricsHelper.h"
#include <iostream>

using namespace std;

MetricsHelper::MetricsHelper()
{

}
MetricsHelper::MetricsHelper(int *array[],int arraySize)
{
    baseDataSet = array;
    sizeOfArray = arraySize;
    sort(baseDataSet,sizeOfArray);
}
MetricsHelper::~MetricsHelper()
{
    delete [] baseDataSet;
}
void MetricsHelper::setNewDataset(int *array[], int arraySize)
{
    baseDataSet = array;
    sizeOfArray = arraySize;
    sort(baseDataSet,sizeOfArray);
}
float MetricsHelper::getMean()
{
    
}
float MetricsHelper::getMedian()
{

}
int MetricsHelper::getMax()
{

}
void MetricsHelper::sort(int *array[],int arraySize)
{

}