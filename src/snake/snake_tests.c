#include <stdbool.h>
#include <stdio.h>

#include "snake.h"
#include "../position/position.h"

bool test_createSnakeNode() {

    printf("  testing createSnakeNode()\n");

    position p = createPosition(0, 1);
    snakeNode* head = createSnakeNode(p, NULL);

    if (head == NULL || head->Position.x != 0 || head->Position.y != 1 || head->next != NULL) {
        printf("    FAILED\n");
        return false;
    }

    return true;

}

bool test_createSnake() {

    printf("  testing createSnake()\n");

    snake s = createSnake();

    if (s.size != 2) {
        printf("    incorrect size: %d\n", s.size);
        return false;
    }

    if (s.head == NULL) {
        printf("    null head\n");
        return false;
    }

    if (s.tail == NULL) {
        printf("    null tail\n");
        return false;
    }

    if (s.tail->next != s.head || s.head->next != NULL) {
        printf("    FAILED\n");
        return false;
    }

    return true;

}

bool test_appendSnake() {

    printf("  testing appendSnake()\n");

    snake s = createSnake();

    appendSnake(&s);

    if (s.size != 3) {
        printf("    incorrect size: %d\n", s.size);
        return false;
    }

    if (s.head == NULL) {
        printf("    null head\n");
        return false;
    }

    if (s.tail == NULL) {
        printf("    null tail\n");
        return false;
    }

    if (s.tail->next == s.head) {
        printf("    node never inserted in between tail and head\n");
        return false;
    }

    return true;

}

bool test_moveSnake() {

    printf("  testing moveSnake()\n");

    position offset = createPosition(1, 0);
    snake s = createSnake();

    moveSnake(offset, &s, false);

    // expected coords: head -> (1,0), tail -> (0,0)

    if (s.head->Position.x != 1 || s.head->Position.y != 0) {
        printf("  did not eat apple: wrong head coords -> %d, %d\n", s.head->Position.x, s.head->Position.y);
        return false;
    }

    if (s.tail->Position.x != 0 || s.tail->Position.y != 0) {
        printf("  did not eat apple: wrong tail coords -> %d, %d\n", s.tail->Position.x, s.tail->Position.y);
        return false;
    }

    moveSnake(offset, &s, true);

    // expected coords: head -> (2,0), middle -> (1,0), tail -> (0,0)

    if (s.size != 3) {
        printf("  wrong size: %d\n", s.size);
        return false;
    }

    if (s.tail->Position.x != 0 || s.tail->Position.y != 0) {
        printf("  ate apple: wrong tail coords -> %d, %d\n", s.tail->Position.x, s.tail->Position.y);
        return false;
    }

    if (s.tail->next->Position.x != 1 || s.tail->next->Position.y != 0) {
        printf("  ate apple: wrong middle coords -> %d, %d\n", s.tail->next->Position.x, s.tail->next->Position.y);
        return false;
    }

    if (s.head->Position.x != 2 || s.head->Position.y != 0) {
        printf("  ate apple: wrong head coords -> %d, %d\n", s.head->Position.x, s.head->Position.y);
        return false;
    }

    return true;

}

bool test_freeSnake() {

    printf("  testing freeSnake()\n");

    snake s = createSnake();

    for (int i = 0; i < 5; i++) {
        appendSnake(&s);
    }

    freeSnake(&s);

    if (s.size != 0 || s.head != NULL || s.tail != NULL) {
        printf("    FAILED\n");
        return false;
    }

    return true;

}

int main() {

    printf("snake testing suite\n");

    int passed = 0;

    if (test_createSnakeNode()) {
        passed++;
    }
    if (test_createSnake()) {
        passed++;
    }
    if (test_appendSnake()) {
        passed++;
    }
    //if (test_moveSnake()) {
       // passed++;
    //}
    if (test_freeSnake()) {
        passed++;
    }

    printf("%d tests passed\n", passed);

    return 0;

}
