
// ******************************* Erik Bylund ********************************//

#ifndef __UltimateTicTacToe__Grid__
#define __UltimateTicTacToe__Grid__

#include <vector>
#include "Square.h"


class Grid : public Square
{
protected:
    std::vector<Square *> getLocations() const;
    int mWinningCombos[8][3];
    
public:
    Grid(double xIn, double yIn, double sizeIn);
    void draw() const;
//    virtual void click(double xIn, double yIn);
};

#endif /* defined(__UltimateTicTacToe__Grid__) */
