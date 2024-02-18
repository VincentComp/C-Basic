#include "handler.h"

void HandlerModule :: trainData(const string &question, const string &answer)
{
    data.insert(question,answer);
}

string HandlerModule :: answer(const string &question) const
{
    string result = question;

    if(languageFilter != nullptr)
    {
        if(languageFilter->translatePreData(result) != "")
            {
                result = languageFilter->translatePreData(result);
            }
    }

    if(toneFilter != nullptr)
    {
        if(toneFilter->translatePreData(result) != "")
            {
                result = toneFilter->translatePreData(result);
            }
    }

    string answer = inneranswer(result);

    if(answer == "")
        return "Sorry, I don't know";

    if(toneFilter != nullptr)
    {
        if(toneFilter->translatePostData(answer) != "")
            {
                answer = toneFilter->translatePostData(answer);
            }
    }

    if(languageFilter != nullptr)
    {
        if(languageFilter->translatePostData(answer) != "")
            {
                answer = languageFilter->translatePostData(answer);
            }
    }

    return answer;

    

}

string HandlerModule :: inneranswer(const string &question) const
{
    return data.find(question);
}




HandlerMap :: HandlerMap() : arraySize(0), names(nullptr), handlerModules(nullptr){};
HandlerMap :: ~HandlerMap(){clear();}


void HandlerMap :: insert(string key, HandlerModule *value)
{
    if(arraySize == 0)
    {
        arraySize = 1;
        names = new string[1];
        handlerModules = new HandlerModule* [1];

        names[0] = key;
        handlerModules[0] = value;

        return;
    }

    arraySize++;

    string* names_temp = new string[arraySize];
    HandlerModule** handleModules_temp = new HandlerModule*[arraySize];

    for(int i =0 ; i < arraySize-1; i++)
    {
        names_temp[i] = names[i];
        handleModules_temp[i] = handlerModules[i];
    }

    names_temp[arraySize-1]  = key;
    handleModules_temp[arraySize-1] = value;

    if(names != nullptr)
        delete [] names;
    names = nullptr;

    if(handlerModules != nullptr)
        delete [] handlerModules; //$$$
    handlerModules = nullptr;

    names = names_temp;
    handlerModules = handleModules_temp;

    return;

}



HandlerModule * HandlerMap ::find(const string &key) const
{
    for(int i = 0; i < arraySize; i++)
    {
        if(names[i] == key)
        {
            return handlerModules[i];
        }
    }

    return nullptr;
}


string  HandlerMap :: getNames(int index) const
{
    if(index >= arraySize || index <0)
        return "";
    return names[index];
}


void HandlerMap :: clear()
{
    if(arraySize != 0)
    {
        arraySize = 0;
        if(names != nullptr)
            delete [] names;
        names = nullptr;

        if(handlerModules != nullptr)
            delete [] handlerModules;
        handlerModules = nullptr;
    }
}