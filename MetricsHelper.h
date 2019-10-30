#ifndef METRICSHELPER_H
#define METRTICSHELPER_H

class MetricsHelper
{
    public:
        MetricsHelper();
        MetricsHelper(int array[],int arraySize);
        ~MetricsHelper();
        //updates the data to get all the following metrics from
        void setNewDataset(int array[],int arraySize);
        //returns the summary statistics for the data stored as an array in this instance
        float getMean();
        float getMedian();
        int getMax();
        void printArray();
        int getNumberOver(int i );
    private:
        void sort();
        int *baseDataSet;
        int sizeOfArray;
};
#endif