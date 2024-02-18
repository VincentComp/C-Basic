#include "CipherUtility.h"

// TODO #5
// Implement the static member function isKeyValid
bool CipherUtility :: isKeyValid(const Cipher* cipher)
{
    for(int i = 0; i < cipher->key.length(); i++)
    {
        if(!(isalpha(cipher->key[i])))
            return false;
    }
    return true;
}

// TODO #6
// Implement the static member function removeNonAlphaCharsHelper

string CipherUtility :: removeNonAlphaCharsHelper(string str)
{
    static string temp = "";

    if(str == "")
        return "";
    
    if(isalpha(str[0]))
    {
        temp.push_back(str[0]);
        removeNonAlphaCharsHelper(str.erase(0,1));
    }
    else
        removeNonAlphaCharsHelper(str.erase(0,1));

    return temp;    

}