#include "hashtable.h"
BoardOptimalMove BoardHashTable :: getHashedMove(const unsigned long long id, const int depth)
{
    if(table[id%TABLE_SIZE]==nullptr)
        return BoardOptimalMove();

    BoardHashNode* p = table[id%TABLE_SIZE];
    for(;p != nullptr; p=p->next)
    {
        if((p->id == id) && (depth <= (p->depth)))
            return p->optimalMove;
    }
    
    return BoardOptimalMove();
}

void BoardHashTable :: updateTable(const unsigned long long id, const int depth, const BoardOptimalMove& optimalMove)
{
    if(table[id%TABLE_SIZE]==nullptr)
        table[id%TABLE_SIZE] = new BoardHashNode(id,depth,optimalMove);
    
    BoardHashNode* p = table[id%TABLE_SIZE];
    for(;p->next != nullptr; p=p->next)
    {
        if(p->id == id)
        {
            if(depth <= (p->depth))
                return;
            else
            {
                p->optimalMove = optimalMove;
                p->depth = depth;
            }
        }
        
    }

    p->next = new BoardHashNode(id,depth,optimalMove);


}

void BoardHashTable :: clearTable()
{
    for(int i = 0; i < TABLE_SIZE ; i++)
    {

        BoardHashNode * cur = table[i];
        BoardHashNode * after = nullptr;

        while(cur != nullptr)
        {
            after = cur->next;
            delete cur;
            cur = after;
        }
        table[i] = nullptr;

        delete table[i];
    }
}