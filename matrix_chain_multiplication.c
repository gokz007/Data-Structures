#include <stdio.h>  
#include <limits.h>  
int t = 0;  
int matrixChainOrder(int p[], int n) {  
 int m[n][n], i, j, k, L, q;  
 for (i = 1; i < n; i++) {  
 m[i][i] = 0; t++; }  
 for (L = 2; L < n; L++) { t++;  
 for (i = 1; i < n - L + 1; i++) { t++;  
 j = i + L - 1;  
 m[i][j] = INT_MAX; t++;  
 for (k = i; k <= j - 1; k++) { t++;  
 q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j]; t += 4;  
 if (q < m[i][j]) {  
 m[i][j] = q; t++;  
 } }  
 } }  
 return m[1][n - 1];  
}  
void main() {  
 int arr[] = {1, 2, 3, 4, 3 };  
 int size = sizeof(arr) / sizeof(arr[0]);  
 int minCost = matrixChainOrder(arr, size);  
 printf("Minimum number of multiplications is: %d\n", minCost);  
 printf("Total time complexity count: %d\n", t);  
} 