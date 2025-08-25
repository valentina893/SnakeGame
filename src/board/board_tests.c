#include <stdio.h>

#include "../../lib/matrix/matrix.h"
#include "board.h"

int main() {

    printf("board testing suite\n");

    matrix m = createBoard(0, 10, 10);

    m.data[0][0] = 1;

    stringMatrix(m);

    return 0;

}