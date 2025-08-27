#include <stdbool.h>

#include "../lib/matrix/matrix.h"
#include "../lib/random/random.h"

#include "apple/apple.h"
#include "board/board.h"
#include "snake/snake.h"
#include "game/game.h"

int main() {

    randSeed();

    apple app;
    matrix board = createBoard(0, 10, 10);
    snake snke = createSnake();

    bool running = setGame(&app, &board, &snke);

    while (running) {
        running = runGame(&app, &board, &snke);
    }

    deleteMatrix(&board);
    freeSnake(&snke);

    return 0;

}