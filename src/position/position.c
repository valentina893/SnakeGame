#include <stdbool.h>

#include "position.h"

position createPosition(int newX, int newY) {

    position newPos;
    newPos.x = newX;
    newPos.y = newY;

    return newPos;

}

void setPosition(position* pos1, position* pos2) {

    pos1->x = pos2->x;
    pos1->y = pos2->y;

}

bool equalPositon(position pos1, position pos2) {

    return pos1.x == pos2.x && pos1.y == pos2.y;

}
