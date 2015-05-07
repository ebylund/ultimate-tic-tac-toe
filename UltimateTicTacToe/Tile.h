
// ******************************* Erik Bylund ********************************//

#ifndef __UltimateTicTacToe__Tile__
#define __UltimateTicTacToe__Tile__

#include "Square.h"

class Tile : public Square
{
    int mOccupiedBy;
    
public:
    Tile(double xIn, double yIn, double sizeIn);
    Tile(Square squareIn);
    void draw(int claimPlayerIn);
    bool click(double xIn, double yIn, int currentPlayer);
    int getOccupiedBy() const;
};

#endif /* defined(__UltimateTicTacToe__Tile__) */
