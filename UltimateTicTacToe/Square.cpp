
// ******************************* Erik Bylund ********************************//

#include "Square.h"

Square::Square(double xIn, double yIn, double sizeIn)
: mStartX(xIn), mStartY(yIn), mSize(sizeIn)
{
    
}


void Square::draw() const
{
//    GL_QUADS
    glBegin(GL_LINE_LOOP);
    glVertex2d(mStartX, mStartY);
    glVertex2d(mStartX + mSize, mStartY);
    glVertex2d(mStartX + mSize, mStartY + mSize);
    glVertex2d(mStartX, mStartY + mSize);
    glEnd();
}

bool Square::contains(double x, double y) const
{
    return (x >= mStartX && x <= mStartX + mSize) && (y >= mStartY && y <= mStartY + mSize);
}

void Square::adjust(double dxIn, double dyIn, double dsizeIn)
{
    mStartX += dxIn;
    mStartY += dyIn;
    mSize += dsizeIn;
}

void Square::destroy(std::vector<Square *> squaresIn) const
{
    std::vector<Square *>::iterator it;
    for(it = squaresIn.begin(); it != squaresIn.end(); ++it)
    {
        delete *it;
    }
}
double Square::getX() const
{
    return this->mStartX;
}

double Square::getY() const
{
    return this->mStartY;
}

double Square::getSize() const
{
    return this->mSize;
}