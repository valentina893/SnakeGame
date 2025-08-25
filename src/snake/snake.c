#include <stdbool.h>
#include <stdlib.h>

#include "snake.h"
#include "../position/position.h"

snakeNodePtr createSnakeNode(position pos, snakeNodePtr nextNode) {

    snakeNodePtr newNode = (snakeNode*)malloc(sizeof(snakeNode));
    newNode->Position = createPosition(pos.x, pos.y);
    newNode->next = nextNode;

    return newNode;

}

void appendSnake(snake* s) {

    snakeNodePtr newNode = createSnakeNode(s->tail->Position, s->tail);
    s->tail = newNode;
    s->size++;

}

snake createSnake() {

    snake s;

    position pos = createPosition(3, 4);

    s.size = 1;
    s.head = createSnakeNode(pos, NULL);
    s.tail = s.head;

    appendSnake(&s);

    s.tail->Position = createPosition(3, 3);

    return s;

}
/*
void moveSnake(position offSet, snake* s, bool ateApple) {

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

}
*/

void freeSnake(snake* s) {

    snakeNodePtr toFree = NULL;

    for (int i = 0; i < s->size; i++) {
        toFree = s->tail;
        s->tail = s->tail->next;
        free(toFree);
        toFree = NULL;
    }

    s->size = 0;
    s->head = NULL;
    s->tail = NULL;

}
