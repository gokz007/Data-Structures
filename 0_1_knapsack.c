#include <stdio.h>  
int t = 0;  
int max(int a, int b) {  
 t++;   
 return (a > b) ? a : b;  
}  
void knapsack(int n, int wi[], int pi[], int m) {  
 int i, w;  
 int K[n + 1][m + 1];  
 t += 2;  
 for (i = 0; i <= n; i++) {  
 t++;  
 for (w = 0; w <= m; w++) {  
 t++;  
 if (i == 0 || w == 0) {  
 K[i][w] = 0;  
 t++;  
 } else if (wi[i - 1] <= w) {  
 K[i][w] = max(pi[i - 1] + K[i - 1][w - wi[i - 1]], K[i - 1][w]);  
 t += 4;  
 } else {  
 K[i][w] = K[i - 1][w];  
 t++;  
 }  
 }  
 }  
 printf("Maximum profit: %d\n", K[n][m]);  
}  
void main() {  
 int n = 5, m = 50;  
 int wi[5] = {40, 30, 20, 10, 5};  
 int pi[5] = {10, 20, 30, 40, 50};  
 knapsack(n, wi, pi, m);  
 printf("The total time of the algorithm is: %d\n", t);  
} 