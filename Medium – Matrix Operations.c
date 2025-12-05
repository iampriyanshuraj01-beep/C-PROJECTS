#include <stdio.h>

// Function to input a matrix
void inputMatrix(int m, int n, int a[m][n]) {
    printf("Enter elements of matrix (%d x %d):\n", m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
}

// Function to display a matrix
void printMatrix(int m, int n, int a[m][n]) {
    printf("Matrix (%d x %d):\n", m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

// Matrix Addition
void addMatrix(int m, int n, int a[m][n], int b[m][n], int result[m][n]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

// Matrix Multiplication
void multiplyMatrix(int m, int n, int p, int a[m][n], int b[n][p], int result[m][p]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            result[i][j] = 0;
            for (int k = 0; k < n; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

// Matrix Transpose
void transposeMatrix(int m, int n, int a[m][n], int result[n][m]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result[j][i] = a[i][j];
        }
    }
}

int main() {
    int m, n, p;

    // Input first matrix
    printf("Enter rows and columns of Matrix A: ");
    scanf("%d %d", &m, &n);
    int A[m][n];
    inputMatrix(m, n, A);

    // Input second matrix
    printf("Enter rows and columns of Matrix B: ");
    scanf("%d %d", &n, &p);
    int B[n][p];
    inputMatrix(n, p, B);

    // Matrix Addition (only if sizes match)
    if (m == n && n == p) {
        int addResult[m][n];
        addMatrix(m, n, A, B, addResult);
        printf("\n--- Matrix Addition ---\n");
        printMatrix(m, n, addResult);
    } else {
        printf("\nMatrix addition not possible (size mismatch).\n");
    }

    // Matrix Multiplication
    int mulResult[m][p];
    multiplyMatrix(m, n, p, A, B, mulResult);
    printf("\n--- Matrix Multiplication ---\n");
    printMatrix(m, p, mulResult);

    // Transpose of Matrix A
    int transA[n][m];
    transposeMatrix(m, n, A, transA);
    printf("\n--- Transpose of Matrix A ---\n");
    printMatrix(n, m, transA);

    return 0;
}
