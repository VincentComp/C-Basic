#include "VigenereCipher.h"
#include "Utility.h"
#include <string>
// TODO #1
// Initialize the static data member alphabetSize here
const int VigenereCipher :: alphabetSize = 26;

// TODO #2
// Implement the encrypt member function according to the given algoirthm.
string VigenereCipher :: encrypt(string plaintextMsg) const
{
    string encrypted = "";
    int index = 0;

    for(int i = 0; i < plaintextMsg.length(); i++)
    {
        plaintextMsg[i] = tolower(plaintextMsg[i]);

        if(isalpha(plaintextMsg[i]))
        {
            encrypted.push_back( char(( (plaintextMsg[i]-'a') + (key[index++%key.length()] - 'a')) % alphabetSize + 'a'));
        }
        else
        {
            encrypted.push_back(plaintextMsg[i]);
            index = (index+1) % key.length();
        }
    }
    

    return encrypted;
}

// TODO #3
// Implement the decrypt member function according to the given algoirthm.
string VigenereCipher :: decrypt(string ciphertexMsg) const
{
    string encrypted = "";
    int index = 0;

    for(int i = 0; i < ciphertexMsg.length(); i++)
    {
        ciphertexMsg[i] = tolower(ciphertexMsg[i]);

        if(isalpha(ciphertexMsg[i]))
        {
            encrypted.push_back( char((( (ciphertexMsg[i]-'a') - (key[index++%key.length()] - 'a')) + alphabetSize)% alphabetSize + 'a'));
        }
        else
        {
            encrypted.push_back(ciphertexMsg[i]);
            index = (index+1) % key.length();
        }
    }
    

    return encrypted;
}


// TODO #4
// Implement the static member function generateRandomKey
// according to the given algorithm.
string VigenereCipher :: generateRandomKey(int length)
{
    string temp = "";
    for(int i = 0; i < length; i++)
    {
        temp.push_back((_rand()%alphabetSize)+'a');
    }

    return temp;
}