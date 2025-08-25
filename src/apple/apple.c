#include <stdbool.h>
#include <stdlib.h>

#include "apple.h"
#include "../position/position.h"

#include "../../lib/random/random.h"

void setApple(int** openSpotsX, int** openSpotsY, int size, apple* app) {
    
    int xSpot = randint(0, size-1);
    int ySpot = randint(0, size-1);

    position newPos = createPosition(xSpot, ySpot);

    app->eaten = false;
    setPosition(&app->Position, &newPos);

    free(*openSpotsX);
    free(*openSpotsY);
    *openSpotsX = NULL;
    *openSpotsY = NULL;

}
