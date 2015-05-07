
// ******************************* Erik Bylund ********************************//

#include "Tile.h"


Tile::Tile(double xIn, double yIn, double sizeIn)
: Square(xIn, yIn, sizeIn), mOccupiedBy(-1)
{
    
}

Tile::Tile(Square squareIn)
: Tile(squareIn.getX(), squareIn.getY(), squareIn.getSize())
{
    
}


void Tile::draw(int claimPlayerIn)
{
    
    if (mOccupiedBy >= 0)
    {
        
        char letter = mOccupiedBy == 0 ? 'O': 'X';
        void *font = GLUT_BITMAP_HELVETICA_18;
        if (claimPlayerIn < 0)
        {
            glColor3d(0,mOccupiedBy,!mOccupiedBy);
        }
        else
        {
            glColor3d(0,claimPlayerIn,!claimPlayerIn);
        }
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glEnable(GL_BLEND);
        
        int offset = (mSize -12) / 2;
        glRasterPos2d(mStartX + offset, mStartY + offset);

        glutBitmapCharacter(font, letter);
        
        glDisable(GL_BLEND);
    }
    
}

bool Tile::click(double xIn, double yIn, int currentPlayer)
{
    if (mOccupiedBy < 0 && Square::contains(xIn, yIn))
    {
        std::cout << "X: " << xIn << std::endl;
        std::cout << "Y: " << yIn << std::endl;
        
        mOccupiedBy = currentPlayer;
        return true;
    }
    return false;
}

int Tile::getOccupiedBy() const
{
    return this->mOccupiedBy;
}