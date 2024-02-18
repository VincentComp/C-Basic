#include "filter.h"

void FilterModule :: trainPreData(const string &source, const string &target)
{
    preData.insert(source,target);
}

void FilterModule :: trainPostData(const string &source, const string &target)
{
    postData.insert(source,target);
}

string FilterModule :: translatePreData(string question) const
{
    return preData.find(question);
}

string FilterModule :: translatePostData(string question) const
{
    return postData.find(question);
}





void FilterArray :: insert(FilterModule *input)
{
    if(arraySize ==0)
    {
        arraySize = 1;
        array = new FilterModule * [1];
        array[0] = input;
        return;
    }

    arraySize++;

    FilterModule** array_temp = new FilterModule*[arraySize];
    for(int i = 0; i < arraySize -1 ; i++)
    {
        array_temp[i] = array[i];
    }

    array_temp[arraySize -1 ] = input;
    if(array !=nullptr)
        delete [] array;
    array = nullptr;

    array = array_temp;

    return;

}


FilterModule * FilterArray :: get(int index) const
{
    if(index >= arraySize || index < 0)
        return nullptr;
    return array[index];
}