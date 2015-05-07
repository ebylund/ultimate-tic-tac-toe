
// ******************************* Erik Bylund ********************************//

#include "Game.h"

Game::Game(double xIn, double yIn, double sizeIn)
: Grid(xIn, yIn, sizeIn), mActive(true), mCurrentPlayer(0)
{
    std::vector<Square *> locations = Game::getLocations();
    Board * boardPtr;
    std::vector<Square *>::iterator it;
    for(it = locations.begin(); it != locations.end(); ++it)
    {
        boardPtr = new Board(**it);
        boardPtr->adjust(1, 1, -2);
        mBoards.push_back(boardPtr);
    }
    Square::destroy(locations);
}

Game::Game(Square squareIn)
: Game(squareIn.getX(), squareIn.getY(), squareIn.getSize())
{
}

Game::~Game()
{
    // Delete board pointers
    std::vector<Board *>::iterator it;
    for(it = mBoards.begin(); it != mBoards.end(); ++it)
    {
        delete *it;
    }
}


void Game::draw() const
{
    if (mActive)
    {
        std::string title = "Player ";
        title+= mCurrentPlayer == 0 ? 'O': 'X';
        title+= "'s turn";
        glutSetWindowTitle(title.c_str());
    }
    else if(mCurrentPlayer >= 0)
    {
        std::string title = "Player ";
        title+= mCurrentPlayer == 0 ? 'O': 'X';
        title+= " Won!";
        glutSetWindowTitle(title.c_str());
    }
    else{
        glutSetWindowTitle("Tie Game");
    }
    
    glColor3d(0,0,0); // forground color
    Grid::draw();
    std::vector<Board *>::const_iterator it;
    for(it = mBoards.begin(); it != mBoards.end(); ++it)
    {
        (*it)->draw(!mActive);
    }
}

bool Game::click(double xIn, double yIn)
{
    if (mActive && Square::contains(xIn, yIn))
    {
        std::vector<Board *>::iterator it;
        for(it = mBoards.begin(); it != mBoards.end(); ++it)
        {
           if((*it)->click(xIn, yIn, mCurrentPlayer))
           {
               int index = (*it)->getLatestTile();
               setPlayableBoard(index);
               mCurrentPlayer = ++mCurrentPlayer % 2;
               checkWin();
               return true;
           }
        }
    }
    return false;
}

void Game::setPlayableBoard(int indexIn)
{
    Board * currentBoard = mBoards.at(indexIn);
    bool allBoardsPlayable = currentBoard->isFull();
    std::vector<Board *>::iterator it;
    for(it = mBoards.begin(); it != mBoards.end(); ++it)
    {
        (*it)->setPlayable(allBoardsPlayable);
    }
    currentBoard->setPlayable(true);
}

void Game::checkWin()
{
    if (mActive)
    {
        int i;
        Board * board1Ptr, * board2Ptr, * board3Ptr;
        
        for (i = 0; i < 8; i++)
        {
            board1Ptr = mBoards.at(mWinningCombos[i][0]);
            board2Ptr = mBoards.at(mWinningCombos[i][1]);
            board3Ptr = mBoards.at(mWinningCombos[i][2]);
            
            if (board1Ptr->getOccupied() >= 0 && board1Ptr->getOccupied() == board2Ptr->getOccupied() &&  board2Ptr->getOccupied() == board3Ptr->getOccupied())
            {
                mActive = false;
                mCurrentPlayer = board1Ptr->getOccupied();
                return;
            }
        }
        std::vector<Board *>::iterator it;
        for(it = mBoards.begin(); it != mBoards.end(); ++it)
        {
            if( !(*it)->isFull() )
            {
                return;
            }
            
        }
        mActive = false;
        mCurrentPlayer = -1;
    }
}