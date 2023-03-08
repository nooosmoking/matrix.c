#include "../s21_matrix.h"

void minor_matrix(matrix_t *A, matrix_t *result) {
  matrix_t *tmp = NULL;
  int size = A->rows;
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++){
        s21_create_matrix(size-1, size-1, tmp);
        get_matrix(A, tmp, i, j, size);
        result->matrix[i][j] = simple_determinant(tmp, size-1);
      }
    }
}


int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int status = 0;
  if (A->rows <= 0 && A->columns <= 0 && !(A->matrix) && !(result)) {
    status = 1;
  } else if (A->columns != A->rows) {
    status = 2; 
  } else {
    s21_create_matrix(A->rows, A->rows, result);
    minor_matrix(A, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++)
        result->matrix[i][j] = result->matrix[i][j] * pow((-1), i + j);
    }
  }
  return status;
}