#include <stdio.h>  
#include <string.h>  
int t = 0;  
int max(int a, int b) {  
 t++;  
 return (a > b) ? a : b;  
}  
void lcs(char X[], char Y[], int m, int n) {  
 int L[m + 1][n + 1];  
 int i, j; t += 2;  
 for (i = 0; i <= m; i++) { t++;  
 for (j = 0; j <= n; j++) { t++;  
 if (i == 0 || j == 0) {  
 L[i][j] = 0; t++;  
 } else if (X[i - 1] == Y[j - 1]) {  
 L[i][j] = L[i - 1][j - 1] + 1; t += 2;  
 } else {  
 L[i][j] = max(L[i - 1][j], L[i][j - 1]);  
 t += 2;  
 }  
 }  
 }  
 int index = L[m][n];  
 char lcsStr[index + 1];  
 lcsStr[index] = '\0';  
 t += 2;  
 i = m;  
 j = n;  
 while (i > 0 && j > 0) { t++;  
 if (X[i - 1] == Y[j - 1]) {  
 lcsStr[index - 1] = X[i - 1];  
 i--;  
 j--;  
 index--; t += 4;  
 } else if (L[i - 1][j] > L[i][j - 1]) {  
 i--; t++;  
 } else {  
 j--; t++; } }  
 printf("Length of LCS is: %d\n LCS string is: %s\n ", L[m][n], lcsStr);  
 printf("Total time complexity count: %d\n", t);}  

void main() {  
 char X[] = "ADVENTOROUS";  
 char Y[] = "ARTIST";  
 int m = strlen(X);  
 int n = strlen(Y);  
 lcs(X, Y, m, n);
} 