#include "board.h"

Board :: Board(const int score[][BOARD_SIZE])
{
    for(int i = 0; i < BOARD_SIZE; i++)
    {
        for(int j = 0; j < BOARD_SIZE; j++)
        {
            cells[i][j] = EMPTY;
            this->score[i][j] = score[i][j];
        }
    }

    this->curPlayer = X;

    this->id = 0;
}

bool Board :: isFull() const
{
    
    for(int i = 0; i < BOARD_SIZE; i++)
    {
        for(int j = 0; j < BOARD_SIZE; j++)
        {
            if(cells[i][j] == EMPTY)
            {
                return false;
            }   
        }
    }

    return true;
}


bool Board :: isFinished() const
{
    if(isFull())
        return true;
   
    int gbs = getBoardScore();

    if( (gbs == WIN_SCORE) || (gbs== -WIN_SCORE))
        return true;
    
    return false;


    
}



int Board :: getBoardScore() const
{
    //Horizontal
    for(int i = 0; i < BOARD_SIZE; i++)
    {
        bool finish = true; 

        if(cells[i][0] == EMPTY)
        {   
            continue;
        }
        
        for(int j = 0; j < BOARD_SIZE; j++)
        {
            if(cells[i][0] != cells[i][j])
            {   
                finish = false;
                break;
            }
        }

        if(finish) 
        {
            if(curPlayer == O)
                return WIN_SCORE;
            else
                return -WIN_SCORE;
        }
    }



    

    //vertical
    for(int i = 0; i < BOARD_SIZE; i++)
    {
        bool finish = true; 

        if(cells[0][i] == EMPTY)
        {   
            continue;
        }
        
        for(int j = 0; j < BOARD_SIZE; j++)
        {
            if(cells[0][i] != cells[j][i])
            {   
                finish = false;
                break;
            }
        }

        if(finish) 
        {
            if(curPlayer == O)
                return WIN_SCORE;
            else
                return -WIN_SCORE;
        }
    }

    //from L to R
    for(int i = 0; i < BOARD_SIZE; i++)
    {
        bool finish = true; 

        if(cells[0][0] == EMPTY)
        {   
            break;
        }

        for(int i = 0, j = 0; i < BOARD_SIZE; i++, j++)
        {
            if(cells[0][0] != cells [i][j])
            {
                finish = false;
                break;
            }
        }
        

        if(finish) 
        {
            if(curPlayer == O)
                return WIN_SCORE;
            else
                return -WIN_SCORE;
        }
    }


    //from R to L
    for(int i = 0; i < BOARD_SIZE; i++)
    {
        bool finish = true; 

        if(cells[0][BOARD_SIZE-1] == EMPTY)
        {   
            break;
        }

        for(int i = 0, j = 0; i < BOARD_SIZE; i++, j++)
        {
            if(cells[0][BOARD_SIZE-1] != cells [i][BOARD_SIZE-1-j])
            {
                finish = false;
                break;
            }
        }
        

        if(finish) 
        {
            if(curPlayer == O)
                return WIN_SCORE;
            else
                return -WIN_SCORE;
        }
    }




    //Note: O_num = num of X 
    int X_num = (BOARD_SIZE*BOARD_SIZE)/2 ,  
        O_num =  (BOARD_SIZE*BOARD_SIZE)-X_num,  
        X_sum = 0,
        O_sum = 0;
    

    for(int i = 0; i < BOARD_SIZE; i++)
    {
        for(int j = 0; j < BOARD_SIZE; j++)
        {
            if(cells[i][j] == X)
                X_sum+= score[i][j];
            else if(cells[i][j] == O)
                O_sum+= score[i][j];
        }
    }

    return X_num*X_sum - O_num*O_sum;


    


}


bool Board :: play(const BoardCoordinate& coords)
{
    
    if(!coords.isValid())
        return false;



    if(cells[coords.row][coords.col] != EMPTY)
        return false;


    if(curPlayer == X)
    {
        cells[coords.row][coords.col] = X;
        curPlayer = O;
    }

    else
    {
        cells[coords.row][coords.col] = O;
        curPlayer = X;
    }



   
    if(cells[coords.row][coords.col] == O)
        this-> id += pow(3,(coords.row*BOARD_SIZE+coords.col))* 2;
    else if(cells[coords.row][coords.col] == X)
        this-> id += pow(3,(coords.row*BOARD_SIZE+coords.col));
    

    return true;
}