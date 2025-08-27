#include <stdbool.h>

#include "../position/position.h"

void drawGame(matrix m, snake s);

position handleInput();

bool moveSnake(position offSet, snake* snke, matrix* board, apple* app);

bool setGame(apple* app, matrix* board, snake* snke);

bool runGame(apple* app, matrix* board, snake* snke);
