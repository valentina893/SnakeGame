#include <stdlib.h>
#include <stdio.h>

#include "apple.h"
#include "../../lib/random/random.h"

int main() {

    printf("apple testing suite\n");

    randSeed();

    apple app;
    int size = 5;
    int* xSpots = (int*)malloc(sizeof(int) * size);
    int* ySpots = (int*)malloc(sizeof(int) * size);

    for (int i = 0; i < size; i++) {
        xSpots[i] = i + 1;
        ySpots[i] = size - i;
    }

    setApple(&xSpots, &ySpots, size, &app);

    printf("%d, %d\n", app.Position.x, app.Position.y);

    if (xSpots != NULL || ySpots != NULL) {
        printf("  failed\n");
    }

    return 0;

}