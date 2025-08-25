#include <stdbool.h>

#include "../position/position.h"

typedef struct apple {

    bool eaten;
    position Position;

} apple;

void setApple(int** openSpotsX, int** openSpotsY, int size, apple* app);
