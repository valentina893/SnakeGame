#include "../../lib/matrix/matrix.h"
#include "board.h"

matrix createBoard(int startData, int rows, int cols) {
    
    matrix m = createMatrix(rows, cols);
    setMatrix(startData, &m);

    return m;
}
/*
int getOpenAmount(matrix mat, ) {

    for (int r = 0; r < mat.rows; r++) {
        for (int c = 0; c < mat.cols; c++) {
            if (mat.data[r][c] == 0) {
                
            }
        }
    }

}
    */
