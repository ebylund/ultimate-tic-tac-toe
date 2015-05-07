
// ******************************* Erik Bylund ********************************//

#ifndef __UltimateTicTacToe__Board__
#define __UltimateTicTacToe__Board__

#include <vector>
#include "Grid.h"
#include "Tile.h"

class Board : public Grid
{
    std::vector<Tile *> mTiles;
    int mOccupied;
    bool mPlayable;
    int mLatestTile;
    int mClaimedBy;
    void checkWin();
    
public:
    Board(double xIn, double yIn, double sizeIn);
    Board(Square squareIn);
    ~Board();
    void draw(bool mActive) const;
    bool click(double xIn, double yIn, int currentPlayer);
    int getLatestTile();
    void setPlayable(bool value);
    bool isFull();
    int getOccupied();
    
};

#endif /* defined(__UltimateTicTacToe__Board__) */
