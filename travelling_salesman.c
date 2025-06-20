#include <stdio.h>  
#include <limits.h>  
int t = 0;  
#define INF 100000000  
int min(int a, int b) {  
 t++;  
 return (a < b) ? a : b;  
}  
int tsp(int mask, int pos, int n, int dist[n][n], int dp[1 << n][n]) {  
 t++;  
 if (mask == (1 << n) - 1) {  
 t++;  
 return dist[pos][0];  
 }  
 if (dp[mask][pos] != -1) {  
 t++;  
 return dp[mask][pos];  
 }  
 int ans = INF;  
 t++;  
 for (int city = 0; city < n; city++) {  
 t++;  
 if ((mask & (1 << city)) == 0) {  
 int newAns = dist[pos][city] + tsp(mask | (1 << city), city, n, dist, dp);  
 ans = min(ans, newAns);  
 t += 4;  
 }  
 }  
 dp[mask][pos] = ans;  
 t++;  
 return ans;  
}  
void main() {  
 int n = 4;  
 int dist[4][4] = {  
 {0, 10, 15, 20},  
 {10, 0, 35, 25},  
 {15, 35, 0, 30},  
 {20, 25, 30, 0}  
 };  
 int dp[1 << n][n];  
 t++;  
 for (int i = 0; i < (1 << n); i++) {  
 t++;  
 for (int j = 0; j < n; j++) {  
 dp[i][j] = -1;  
 t++;  
 }  
 }  
 int minCost = tsp(1, 0, n, dist, dp);  
 printf("Minimum TSP cost: %d\n", minCost);  
 printf("Total time complexity count: %d\n", t);  
}