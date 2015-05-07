
// ******************************* Erik Bylund ********************************//

#ifndef __UltimateTicTacToe__Square__
#define __UltimateTicTacToe__Square__

#include <vector>
#include <iostream>

#ifdef _WIN32
    #include "glut.h"
#else
    #ifdef __APPLE__
        #include <GLUT/glut.h>
    #else
        #include <GL/glut.h>
    #endif
#endif

class Square
{
protected:
    double mStartX;
    double mStartY;
    double mSize;
    
public:
    Square(double xIn, double yIn, double sizeIn);
    void draw() const;
    bool contains(double x, double y) const;
    
    void adjust(double dxIn, double dyIn, double dsizeIn);
    
    double getX() const;
    double getY() const;
    double getSize() const;
    void destroy(std::vector<Square *> squaresIn) const;
    
//    virtual void click(double xIn, double yIn);
};

#endif /* defined(__UltimateTicTacToe__Square__) */
