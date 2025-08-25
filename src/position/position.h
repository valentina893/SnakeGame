#pragma once

#include <stdbool.h>

typedef struct position {

    int x;
    int y;

} position;

position createPosition(int newX, int newY);

void setPosition(position* pos1, position* pos2);

bool equalPositon(position pos1, position pos2);
