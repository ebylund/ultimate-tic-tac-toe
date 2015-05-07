
// ******************************* Erik Bylund ********************************//

#ifndef __UltimateTicTacToe__Game__
#define __UltimateTicTacToe__Game__

#include <vector>
#include "Grid.h"
#include "Board.h"

class Game : public Grid
{
    std::vector<Board *> mBoards;
    bool mActive;
    int mCurrentPlayer;

public:
    Game(double xIn, double yIn, double sizeIn);
    Game(Square squareIn);
    ~Game();
    void setSize();
    void draw()const;
    bool click(double xIn, double yIn);
    void setPlayableBoard(int indexIn);
    void checkWin();
};

#endif /* defined(__UltimateTicTacToe__Game__) */
