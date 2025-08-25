#include <stdbool.h>
#include <stdio.h>

#include "../../lib/matrix/matrix.h"
#include "../../lib/random/random.h"

#include "../apple/apple.h"
#include "../board/board.h"
#include "../position/position.h"
#include "../snake/snake.h"

#include "game.h"

int main() {

    int score = 0;

    randSeed();

    apple app;
    matrix board = createBoard(0, 10, 10);
    snake snke = createSnake();

    //app.Position = createPosition(0, 0);

    bool running = setGame(&app, &board, &snke, &score);

    while (running) {
        running = runGame(&app, &board, &snke, &score);
    }

    //printf("%d, %d\n", snke.head->Position.x, snke.tail->Position.x);

    return 0;

}