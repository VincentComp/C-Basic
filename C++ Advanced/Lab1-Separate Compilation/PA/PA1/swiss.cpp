
#include "player.h"
#include "swiss.h"
#include "match.h"

Swiss :: Swiss(const int numRounds, const PlayerList& list) :list(list)
{
    this->curRound = 0;
    this->numRounds = numRounds;
    this->list.sort();
};
Swiss :: ~Swiss()
{return;};

void Swiss :: play()
{   
    curRound++;
    for(; curRound <= numRounds; curRound++)
    {
        PlayerList * all_list = new PlayerList[2*curRound-1];
        
        for(int score = 0; score < 2*curRound-1; score++)
        {
            for(int index = 0; index < list.getNumPlayers(); index ++)
            {
                if(list.getPlayer(index)->getScore() == score)
                    all_list[score].addPlayer(list.getPlayer(index));
            } 

            all_list[score].sort();
            
        }   

        //list.sort();

        
        for(int score = 2*curRound-2; score>= 0; score--)
        {
            
        
                if(all_list[score].getNumPlayers()%2 == 1)
                    {
                        

                        if(score == 0)
                            all_list[score].getPlayer(all_list[score].getNumPlayers()-1)->addScore(2);

                        else
                        {
                        
                            all_list[score-1].addPlayer(all_list[score].getPlayer(all_list[score].getNumPlayers()-1));
                            all_list[score-1].sort();
                           
                        }
                    }
             
                    
                    

                for(int head = 0, middle = all_list[score].getNumPlayers()/2; head < all_list[score].getNumPlayers()/2 ;head++,middle++)
                {
                    Match temp(all_list[score].getPlayer(head),all_list[score].getPlayer(middle));
                    temp.play();
                    
                }
            
                
               
            
            
        }   
        

        list.sort();

        printLeaderboard();
        

        delete [] all_list;
    }
};

