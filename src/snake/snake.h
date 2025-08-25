#include <stdbool.h>

#include "../position/position.h"

typedef struct snakeNode* snakeNodePtr;
typedef struct snakeNode {

    position Position;
    snakeNodePtr next; // pointer to forward-most snakeNode

} snakeNode;

typedef struct snake {

    int size;
    snakeNodePtr head;
    snakeNodePtr tail;

} snake;

position createPosition(int newX, int newY);

snakeNodePtr createSnakeNode(position pos, snakeNodePtr nextNode);

void appendSnake(snake* s);

snake createSnake();

//void moveSnake(position offSet, snake* s, bool ateApple);

void freeSnake(snake* s);
