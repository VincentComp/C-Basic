#include "array.h"

DataMap :: DataMap() : arraySize(0), keys(nullptr), values(nullptr) {};

DataMap :: ~DataMap()
{
    clear();
}

void DataMap :: insert(const string &key, const string &value)
{
    if(arraySize ==0)
    {
        arraySize = 1;
        keys = new string[1];
        values = new string [1];

        keys[0] = key;
        values[0] = value;

        return;
    }

    arraySize++;

    string* keys_temp = new string [arraySize]; 
    string* values_temp = new string [arraySize];

    for(int i = 0; i < arraySize-1; i++)
    {
        keys_temp[i] = keys[i];
        values_temp[i] = values[i];
    }

    keys_temp[arraySize-1] = key;
    values_temp[arraySize-1] = value;

    if(keys != nullptr)
        delete [] keys;
    if(values != nullptr)
        delete [] values;
    
    keys = keys_temp;
    values = values_temp;

}

string DataMap :: find(const string& key) const
{

    for(int i = 0; i< arraySize; i++)
    {
        if(keys[i] == key)
        {
            return values[i];
        }
    }

    return "";
}

void DataMap :: clear()
{
    if(arraySize !=0)
    {
        arraySize = 0;
        
        if(keys != nullptr)
            delete [] keys;
        keys = nullptr;
        
        if(values != nullptr)
            delete [] values;
        values = nullptr;
        
    }
}