#include <stdbool.h>
#include <stdio.h>

#include "position.h"

bool test_createPosition() {

    printf("  testing createPosition()\n");

    position p = createPosition(100, 1234);

    if (p.x != 100 || p.y != 1234) {
        printf("    FAILED\n");
        return false;
    }

    return true;

}

bool test_setPosition() {

    printf("  testing setPosition\n");

    position one = createPosition(1, 2);
    position two = createPosition(3, 4);

    setPosition(&one, &two);

    if (one.x != 3 || one.y != 4) {
        printf("    FAILED\n");
        return false;
    }

    return true;

}

bool test_equalPosition() {

    printf("  testing equalPosition\n");

    position one = createPosition(1, 2);
    position two = createPosition(3, 4);

    if (equalPositon(one, two) == true) {
        printf("    FAILED\n");
        return false;
    }

    position three = createPosition(1, 1);
    position four = createPosition(1, 1);

    if (equalPositon(three, four) == false) {
        printf("    FAILED\n");
        return false;
    }

    return true;

}

int main() {

    int passed = 0;

    printf("position testing suite\n");

    if (test_createPosition()) {
        passed++;
    }
    if (test_setPosition()) {
        passed++;
    }
    if (test_equalPosition()) {
        passed++;
    }

    printf("%d tests passed\n", passed);

    return 0;

}