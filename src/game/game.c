#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "../../lib/random/random.h"
#include "../../lib/matrix/matrix.h"

#include "../apple/apple.h"
#include "../board/board.h"
#include "../position/position.h"
#include "../snake/snake.h"

#include "game.h"

void drawGame(matrix m, snake s) {

    system("clear");

    printf("\nSNAKE | score: %d\n", s.size-2);

    printf(" ");
    for (int i = 0; i < m.cols; i++) {
        printf("-");
    }
    printf("\n");

    for (int r = 0; r < m.rows; r++) {
        printf("|");
        for (int c = 0; c < m.cols; c++) {
            if (m.data[r][c] == 0) {
                printf(" ");
            } else if (m.data[r][c] == 1) {
                printf("o");
            } else {
                printf("a");
            }
        }
        printf("|\n");
    }

    printf(" ");
    for (int i = 0; i < m.cols; i++) {
        printf("-");
    }
    printf("\n");

    printf("your choice: ");

}

position handleInput() {

    char c;
    scanf(" %c", &c);

    position p;

    if (c == 'w') {
        p = createPosition(-1, 0);
    } else if (c == 'a') {
        p = createPosition(0, -1);
    } else if (c == 's') {
        p = createPosition(1, 0);
    } else if (c == 'd') {
        p = createPosition(0, 1);
    } else if (c == 'q') {
        p = createPosition(-2, -2);
    } else {
        p = createPosition(0, 0);
    }

    return p;

}

bool moveSnake(position offSet, snake* snke, matrix* board, apple* app, int* score) {

    /*
        int headBuffer = 1;
        snakeNodePtr curr = s->tail;

        if (ateApple) {
            appendSnake(s);
            headBuffer = 2;
        }

        for (int i = 0; i < s->size-headBuffer; i++) {
            curr->Position.x = curr->next->Position.x;
            curr->Position.y = curr->next->Position.y;
            curr = curr->next;
        }

        s->head->Position.x += offSet.x;
        s->head->Position.y -= offSet.y;
    */

    int headBuffer = 1;
    snakeNodePtr curr = snke->tail;

    // check for colliding with wall
    if (snke->head->Position.x + offSet.x < 0 || snke->head->Position.x + offSet.x > 9) {
        printf("BAM!\n");
        return false;
    }
    if (snke->head->Position.y + offSet.y < 0 || snke->head->Position.y + offSet.y > 9) {
        //printf("collided on y axis\n");
        printf("CRASH!\n");
        return false;
    }
    // check for colliding with snake piece
    if (board->data[snke->head->Position.x + offSet.x][snke->head->Position.y + offSet.y] == 1) {
        //printf("collided with snake piece\n");
        printf("OUCH!\n");
        return false;
    }
    // check for eating apple
    if (equalPositon(snke->head->Position, app->Position) == true) {
        appendSnake(snke);
        headBuffer = 2;
        board->data[app->Position.x][app->Position.y] = 1;
        app->Position = createPosition(randint(0, board->rows-1), randint(0, board->cols-1));
        board->data[app->Position.x][app->Position.y] = 2;
    } else {
        //board->data[snke->tail->Position.y][snke->tail->Position.x] = 0;
        board->data[snke->tail->Position.x][snke->tail->Position.y] = 0;
    }

    //snke->head->Position.x += offSet.x;
    //snke->head->Position.y += offSet.y;

    for (int i = 0; i < snke->size - headBuffer; i++) {
        setPosition(&curr->Position, &curr->next->Position);
        curr = curr->next;
    }

    snke->head->Position.x += offSet.x;
    snke->head->Position.y += offSet.y;

    //setPosition(&snke->head->Position, &offSet);
    
    board->data[snke->head->Position.x][snke->head->Position.y] = 1;

    return true;

}

bool setGame(apple* app, matrix* board, snake* snke, int* score) {

    //apple app;
    //matrix board = createBoard(0, 10, 10);
    //snake snke = createSnake();

    // get amount of available spots in array
    //  - size of array is known
    //  - write more helper functions in board
    //  - update snake create function to place in known area.

    app->Position = createPosition(randint(0, board->rows-1), randint(0, board->cols-1));

    //board->data[4][3] = 1;
    //board->data[4][2] = 1;
    board->data[snke->head->Position.x][snke->head->Position.y] = 1;
    board->data[snke->head->Position.x][snke->head->Position.y-1] = 1;
    board->data[app->Position.x][app->Position.y] = 2;

    drawGame(*board, *snke);

    //printf("\nhead coords: %d, %d\n", snke->head->Position.x, snke->head->Position.y);
    //printf("tail coords: %d, %d\n", snke->tail->Position.x, snke->tail->Position.y);

    position offSet = handleInput();

    if (offSet.x == -2) {
        return false;
    }

    bool game = moveSnake(offSet, snke, board, app, score);

    return game;

}

bool runGame(apple* app, matrix* board, snake* snke, int* score) {

    //board->data[app->Position.x][app->Position.y] = 2;

    drawGame(*board, *snke);

    //printf("\nhead coords: %d, %d\n", snke->head->Position.x, snke->head->Position.y);
    //printf("tail coords: %d, %d\n", snke->tail->Position.x, snke->tail->Position.y);

    position offSet = handleInput();

    if (offSet.x == -2) {
        return false;
    }

    bool game = moveSnake(offSet, snke, board, app, score);

    return game;

}
