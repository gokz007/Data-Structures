#include <stdio.h>  
#include <stdlib.h>  
void addMatrix(int n, int A[n][n], int B[n][n], int C[n][n]) {  
    int i, j;  
    for (i = 0; i < n; i++)  
       for (j = 0; j < n; j++)  
            C[i][j] = A[i][j] + B[i][j];  
}  
void subtractMatrix(int n, int A[n][n], int B[n][n], int C[n][n]) {  
    int i, j;  
    for (i = 0; i < n; i++)  
        for (j = 0; j < n; j++)  
            C[i][j] = A[i][j] - B[i][j];  
}  
void strassen(int n, int A[n][n], int B[n][n], int C[n][n]) {  
    if (n == 1) {  
        C[0][0] = A[0][0] * B[0][0];  
        return;  
    }  
    int newSize = n / 2;  
    int (*A11)[newSize] = malloc(sizeof(int[newSize][newSize]));  
    int (*A12)[newSize] = malloc(sizeof(int[newSize][newSize]));  
    int (*A21)[newSize] = malloc(sizeof(int[newSize][newSize]));  
    int (*A22)[newSize] = malloc(sizeof(int[newSize][newSize]));  
    int (*B11)[newSize] = malloc(sizeof(int[newSize][newSize]));  
    int (*B12)[newSize] = malloc(sizeof(int[newSize][newSize]));  
    int (*B21)[newSize] = malloc(sizeof(int[newSize][newSize]));  
    int (*B22)[newSize] = malloc(sizeof(int[newSize][newSize]));  
    int (*P)[newSize] = malloc(sizeof(int[newSize][newSize]));  
    int (*Q)[newSize] = malloc(sizeof(int[newSize][newSize]));  
    int (*R)[newSize] = malloc(sizeof(int[newSize][newSize]));  
    int (*S)[newSize] = malloc(sizeof(int[newSize][newSize]));  
    int (*T)[newSize] = malloc(sizeof(int[newSize][newSize]));  
    int (*U)[newSize] = malloc(sizeof(int[newSize][newSize]));  
    int (*V)[newSize] = malloc(sizeof(int[newSize][newSize]));  
    int (*temp1)[newSize] = malloc(sizeof(int[newSize][newSize]));  
    int (*temp2)[newSize] = malloc(sizeof(int[newSize][newSize]));  
    int i, j;  
    for (i = 0; i < newSize; i++)  
        for (j = 0; j < newSize; j++) {  
            A11[i][j] = A[i][j];  
            A12[i][j] = A[i][j + newSize];  
            A21[i][j] = A[i + newSize][j];  
            A22[i][j] = A[i + newSize][j + newSize];  
            B11[i][j] = B[i][j];  
            B12[i][j] = B[i][j + newSize];  
            B21[i][j] = B[i + newSize][j];  
            B22[i][j] = B[i + newSize][j + newSize];  
        }  
    addMatrix(newSize, A11, A22, temp1);  
    addMatrix(newSize, B11, B22, temp2);  
    strassen(newSize, temp1, temp2, P);  
    addMatrix(newSize, A21, A22, temp1);  
    strassen(newSize, temp1, B11, Q);  
    subtractMatrix(newSize, B12, B22, temp2);  
    strassen(newSize, A11, temp2, R);  
    subtractMatrix(newSize, B21, B11, temp2);  
    strassen(newSize, A22, temp2, S);  
    addMatrix(newSize, A11, A12, temp1);  
    strassen(newSize, temp1, B22, T);  
    subtractMatrix(newSize, A21, A11, temp1);  
    addMatrix(newSize, B11, B12, temp2);  
    strassen(newSize, temp1, temp2, U);  
    subtractMatrix(newSize, A12, A22, temp1);  
    addMatrix(newSize, B21, B22, temp2);  
    strassen(newSize, temp1, temp2, V);  
    int (*C11)[newSize] = malloc(sizeof(int[newSize][newSize]));  
    int (*C12)[newSize] = malloc(sizeof(int[newSize][newSize]));  
    int (*C21)[newSize] = malloc(sizeof(int[newSize][newSize]));  
    int (*C22)[newSize] = malloc(sizeof(int[newSize][newSize]));  
    addMatrix(newSize, P, S, temp1);  
    subtractMatrix(newSize, temp1, T, temp2);  
    addMatrix(newSize, temp2, V, C11);  
    addMatrix(newSize, R, T, C12);  
    addMatrix(newSize, Q, S, C21);  
    addMatrix(newSize, P, R, temp1);  
    subtractMatrix(newSize, temp1, Q, temp2);  
    addMatrix(newSize, temp2, U, C22);  
    for (i = 0; i < newSize; i++)  
        for (j = 0; j < newSize; j++) {  
            C[i][j] = C11[i][j];  
            C[i][j + newSize] = C12[i][j];  
            C[i + newSize][j] = C21[i][j];  
            C[i + newSize][j + newSize] = C22[i][j];  
        }  
    free(A11); free(A12); free(A21); free(A22);  
    free(B11); free(B12); free(B21); free(B22);  
    free(P); free(Q); free(R); free(S); free(T); free(U); free(V);  
    free(temp1); free(temp2);  
    free(C11); free(C12); free(C21); free(C22);  
}  

int main() {  
    int n;  
    scanf("%d", &n);  
    int A[n][n], B[n][n], C[n][n];  
    for (int i = 0; i < n; i++)  
        for (int j = 0; j < n; j++)  
            scanf("%d", &A[i][j]);  
    for (int i = 0; i < n; i++)  
        for (int j = 0; j < n; j++)  
            scanf("%d", &B[i][j]);  
    strassen(n, A, B, C);  
    for (int i = 0; i < n; i++) {  
        for (int j = 0; j < n; j++)  
            printf("%d ", C[i][j]);  
        printf("\n");}  
    return 0;
} 