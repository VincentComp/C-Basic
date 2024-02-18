#include <iostream>
#include <cstring>
#include "player.h"

Player :: Player(const char* const name, const int elo)
{
    this->name = new char[strlen(name)+1];
    strcpy(this->name,name);
    this -> elo = elo;
    score = 0;
    
};


Player :: ~Player()
{
    
    delete [] name;
    
};




        
PlayerList :: PlayerList()
{
    numPlayers = 0;
    players = nullptr;
};

PlayerList :: PlayerList(const PlayerList& list)
{
    numPlayers = list.numPlayers;
    players = new Player* [list.numPlayers];
    for(int i = 0; i < list.numPlayers; i++)
        players[i] = list.players[i];
    
};


PlayerList :: ~PlayerList()
{
    
    delete [] players;
    
   
};

void PlayerList :: addPlayer(Player* const player)
{
    Player ** temp = players;
    players = new Player* [numPlayers+1];
    for(int i = 0; i < numPlayers; i++)
        players[i] = temp[i];
    players[numPlayers] = player; 
    numPlayers ++;
    delete [] temp;

};





void PlayerList :: sort()
{

    
    for(int j = 1; j < numPlayers; j++)
    {
        Player* key = players[j];
        int i = j-1;
        
        while(i>=0 && (players[i]->getELO() < key->getELO()))
        {
            players[i+1] = players[i];
            i = i - 1;
        }

        players[i+1] = key;
    }


    for(int j = 1; j<numPlayers; j++)
    {
        Player* key = players[j];
        int i = j-1;
        
        while(i>=0 && (players[i]->getScore() < key->getScore()))
        {
            players[i+1] = players[i];
            i = i - 1;
        }

        players[i+1] = key;
    }
    


};



PlayerList* PlayerList :: splice(const int startIndex, const int endIndex) const
{
    
    PlayerList* new_list = new PlayerList;
    if((startIndex <0) || (endIndex > numPlayers) || (startIndex >= endIndex))
    {
        return new_list;
    }

    
    new_list->players = new Player*[endIndex-startIndex];
    for(int i = startIndex; i < endIndex; i++)
    {
        new_list->numPlayers = endIndex-startIndex;
        new_list->players[i] = players[i]; 
    }
    return new_list;
     
   

   
   
};



