#include <stdbool.h>

#include "../lib/matrix/matrix.h"
#include "../lib/random/random.h"

#include "apple/apple.h"
#include "board/board.h"
#include "snake/snake.h"
#include "game/game.h"

int main() {

    int score = 0;

    randSeed();

    apple app;
    matrix board = createBoard(0, 10, 10);
    snake snke = createSnake();

    bool running = setGame(&app, &board, &snke, &score);

    while (running) {
        running = runGame(&app, &board, &snke, &score);
    }

    deleteMatrix(&board);
    freeSnake(&snke);

    return 0;

}