#include "boardtree.h"

BoardTree :: BoardTree(const Board& board)
{
    root = new BoardNode(board);
}


BoardTree :: ~BoardTree()
{
    delete root;
}

BoardTree* BoardTree :: getSubTree(const BoardCoordinate& coords)
{
    
    if(isEmpty())
        return nullptr;


    Board temp = root->board;
    if(temp.play(coords)==false)
        {   
            return &(root->subTree[coords.row][coords.col]);
        }
    else if(root->subTree[coords.row][coords.col].isEmpty())
        root->subTree[coords.row][coords.col].root = new BoardNode(temp);


    return &(root->subTree[coords.row][coords.col]);
    
    
}


BoardOptimalMove BoardTree :: getOptimalMove(const unsigned int depth)
{
    
    if(isEmpty())
        return BoardOptimalMove();
    

    if(depth == 0 || root->board.isFinished())
        return BoardOptimalMove(root->board.getBoardScore(),BoardCoordinate(-1,-1));
    
    if(BoardHashTable::getInstance().getHashedMove(root->board.getID(),depth).score != ILLEGAL)
        return BoardHashTable::getInstance().getHashedMove(root->board.getID(),depth);


    int estimatedScore;
    estimatedScore = ((root->board.getCurPlayer() == X)? (-WIN_SCORE*2): (WIN_SCORE*2));



    BoardOptimalMove bestMove;
    for(int i = 0; i< BOARD_SIZE; i++)
    {
        for(int j = 0; j < BOARD_SIZE; j++)
        {
            if(root->subTree[i][j].isEmpty())
            {
                getSubTree(BoardCoordinate(i,j));

            }

            BoardOptimalMove childMove =  root->subTree[i][j].getOptimalMove(depth-1);
            

            if(childMove.score == ILLEGAL)
                continue;

            if(((childMove.score > estimatedScore)&&(root->board.getCurPlayer() == X)) || ((childMove.score < estimatedScore)&&(root->board.getCurPlayer() == O)))
            {

                estimatedScore = childMove.score;
                bestMove = BoardOptimalMove(estimatedScore, BoardCoordinate(i,j));

            }



            
        }
    }

    BoardHashTable::getInstance().updateTable(root->board.getID(), depth, bestMove);
    return bestMove;

}




BoardOptimalMove BoardTree :: getOptimalMoveAlphaBeta(const unsigned int depth, int alpha, int beta)
{
    if(isEmpty())
        return BoardOptimalMove();
    

    if(depth == 0 || root->board.isFinished())
        return BoardOptimalMove(root->board.getBoardScore(),BoardCoordinate(-1,-1));
    

    int estimatedScore;
    estimatedScore = ((root->board.getCurPlayer() == X)? (-WIN_SCORE*2): (WIN_SCORE*2));



    BoardOptimalMove bestMove;
    for(int i = 0; i< BOARD_SIZE; i++)
    {
        for(int j = 0; j < BOARD_SIZE; j++)
        {
            if(root->subTree[i][j].isEmpty())
            {
                getSubTree(BoardCoordinate(i,j));

            }

            BoardOptimalMove childMove =  root->subTree[i][j].getOptimalMoveAlphaBeta(depth-1,alpha,beta);
            

            if(childMove.score == ILLEGAL)
                continue;



            if(((childMove.score > estimatedScore)&&(root->board.getCurPlayer() == X)) || ((childMove.score < estimatedScore)&&(root->board.getCurPlayer() == O)))
            {

                estimatedScore = childMove.score;
                bestMove = BoardOptimalMove(estimatedScore, BoardCoordinate(i,j));

            }


            if(root->board.getCurPlayer() ==X)
            {
                if(estimatedScore > beta)
                    {i = 10;
                        break;
                    }
                alpha = std ::max(alpha,estimatedScore);
            }

            else
            {
                if(estimatedScore < alpha)
                    {   i = 10;
                        break;
                    }
                beta = std :: min (beta,estimatedScore);
            }
            
        }
    }

    
    return bestMove;

}