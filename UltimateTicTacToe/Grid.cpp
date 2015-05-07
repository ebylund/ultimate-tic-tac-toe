
// ******************************* Erik Bylund ********************************//

#include "Grid.h"

Grid::Grid(double xIn, double yIn, double sizeIn)
: Square(xIn, yIn, sizeIn)
{
    mWinningCombos[0][0] = 0;
    mWinningCombos[0][1] = 1;
    mWinningCombos[0][2] = 2;
    
    mWinningCombos[1][0] = 3;
    mWinningCombos[1][1] = 4;
    mWinningCombos[1][2] = 5;
                    
    mWinningCombos[2][0] = 6;
    mWinningCombos[2][1] = 7;
    mWinningCombos[2][2] = 8;
                    
    mWinningCombos[3][0] = 0;
    mWinningCombos[3][1] = 3;
    mWinningCombos[3][2] = 6;
                    
    mWinningCombos[4][0] = 1;
    mWinningCombos[4][1] = 4;
    mWinningCombos[4][2] = 7;
                    
    mWinningCombos[5][0] = 2;
    mWinningCombos[5][1] = 5;
    mWinningCombos[5][2] = 8;
                    
    mWinningCombos[6][0] = 0;
    mWinningCombos[6][1] = 4;
    mWinningCombos[6][2] = 8;
                    
    mWinningCombos[7][0] = 2;
    mWinningCombos[7][1] = 4;
    mWinningCombos[7][2] = 6;
}


std::vector<Square *> Grid::getLocations() const
{
    std::vector<Square *> squares;
    
    double size = mSize / 3;
    
    Square * sq;
    int i, xOffset, yOffset;
    double x, y;
    for(i = 0; i < 9; i++)
    {
        xOffset = i % 3;
        yOffset = i / 3;
        
        x = mStartX + xOffset * size;
        y = mStartY + yOffset * size;
        
        sq = new Square(x, y, size);
        squares.push_back(sq);
    }
    
    return squares;
}

void Grid::draw() const
{
    std::vector<Square *> squares = this->getLocations();
    
    std::vector<Square *>::iterator it;
    for(it = squares.begin(); it != squares.end(); it++)
    {
        (*it)->draw();
    }
}