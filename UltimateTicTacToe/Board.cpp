
// ******************************* Erik Bylund ********************************//

#include "Board.h"

Board::Board(double xIn, double yIn, double sizeIn)
: Grid(xIn, yIn, sizeIn), mOccupied(0), mPlayable(true), mLatestTile(-1), mClaimedBy(-1)
{
    std::vector<Square *> locations = Board::getLocations();
    Tile * tilePtr;
    std::vector<Square *>::iterator it;
    for(it = locations.begin(); it != locations.end(); ++it)
    {
        tilePtr = new Tile(**it);
        mTiles.push_back(tilePtr);
    }
    Square::destroy(locations);
}

Board::Board(Square squareIn)
: Board(squareIn.getX(), squareIn.getY(), squareIn.getSize())
{
    
}

Board::~Board()
{
    std::vector<Tile *>::iterator it;
    for(it = mTiles.begin(); it != mTiles.end(); ++it)
    {
        delete *it;
    }
}


void Board::draw(bool colorsToSkip) const
{
    if (mPlayable || colorsToSkip)
    {
        switch (mClaimedBy) {
            case 0:
            case 1:
                glColor3d(0,mClaimedBy,!mClaimedBy); // forground color
//                glClearColor(.5, .5, .5, 0); // background color

                
                break;
            default:
                glColor3d(1,colorsToSkip,1); // forground color
                break;
        }
    }
    else if(!colorsToSkip)
    {
        glColor3d(0,0,0); // forground color
        
    }
    Grid::draw();
    std::vector<Tile *>::const_iterator it;
    for(it = mTiles.begin(); it != mTiles.end(); ++it)
    {
        (*it)->draw(mClaimedBy);
    }
}

bool Board::click(double xIn, double yIn, int currentPlayer)
{
    if (mPlayable && mOccupied < 9 && Square::contains(xIn, yIn))
    {
        std::vector<Tile *>::iterator it;
        for (it = mTiles.begin(); it != mTiles.end(); it++)
        {
            if((*it)->click(xIn, yIn, currentPlayer))
            {
                mOccupied++;
                mPlayable = mOccupied < 9;
                mLatestTile = (int)(it - mTiles.begin());
                checkWin();
                return true;
            }
        }
    }
    mLatestTile = -1;
    return false;
}

int Board::getLatestTile()
{
    return this->mLatestTile;
}

void Board::setPlayable(bool value)
{
    this->mPlayable = value && mOccupied < 9;
}

bool Board::isFull()
{
    return mOccupied >= 9;
}

void Board::checkWin()
{
    if (mClaimedBy < 0)
    {
        int i;
        Tile * tile1Ptr, * tile2Ptr, * tile3Ptr;
        
        for (i = 0; i < 8; i++)
        {
            tile1Ptr = mTiles.at(mWinningCombos[i][0]);
            tile2Ptr = mTiles.at(mWinningCombos[i][1]);
            tile3Ptr = mTiles.at(mWinningCombos[i][2]);
            
            if (tile1Ptr->getOccupiedBy() >= 0 && tile1Ptr->getOccupiedBy() == tile2Ptr->getOccupiedBy() &&  tile2Ptr->getOccupiedBy() == tile3Ptr->getOccupiedBy())
            {
                mClaimedBy = tile1Ptr->getOccupiedBy();
                return;
            }
        }
    }
}
int Board::getOccupied()
{
    return this->mClaimedBy;
}