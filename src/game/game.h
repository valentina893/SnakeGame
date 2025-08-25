#include <stdbool.h>

#include "../position/position.h"

void drawGame(matrix m, snake s);

position handleInput();

bool moveSnake(position offSet, snake* snke, matrix* board, apple* app, int* score);

bool setGame(apple* app, matrix* board, snake* snke, int* score);

bool runGame(apple* app, matrix* board, snake* snke, int* score);
