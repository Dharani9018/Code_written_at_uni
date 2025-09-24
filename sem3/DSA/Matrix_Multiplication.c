#include <stdio.h>
#include <stdlib.h>

// Function to allocate memory for 2D matrix
int** allocate_matrix(int rows, int cols) {
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
        matrix[i] = (int *)malloc(cols * sizeof(int));
    return matrix;
}

// Function to free memory
void free_matrix(int **matrix, int rows) {
    for (int i = 0; i < rows; i++)
        free(matrix[i]);
    free(matrix);
}

int main() {
    int r1, c1, r2, c2;
    int **A, **B, **C;

    // Input dimensions
    printf("Enter rows and columns for matrix A: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter rows and columns for matrix B: ");
    scanf("%d %d", &r2, &c2);

    if (c1 != r2) {
        printf("Matrix multiplication not possible: columns of A != rows of B\n");
        return 1;
    }

    // Dynamic allocation
    A = allocate_matrix(r1, c1);
    B = allocate_matrix(r2, c2);
    C = allocate_matrix(r1, c2);

    // Input elements for A
    printf("Enter elements of matrix A:\n");
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++)
            scanf("%d", &A[i][j]);

    // Input elements for B
    printf("Enter elements of matrix B:\n");
    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++)
            scanf("%d", &B[i][j]);

    // Matrix multiplication
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            C[i][j] = 0;
            for (int k = 0; k < c1; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
    }

    // Output
    printf("Resultant matrix after multiplication:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }

    // Clean up
    free_matrix(A, r1);
    free_matrix(B, r2);
    free_matrix(C, r1);

    return 0;
}
