#include <stdio.h>  
#include <float.h>  
int t = 0;  
float min(float a, float b) {  
    t++;  
    return (a < b) ? a : b;  
}  
void obst(int keys[], float p[], float q[], int n) {  
    float e[n + 2][n + 1], w[n + 2][n + 1];  
    int root[n + 1][n + 1];  
    int i, j, l, r;  
    for (i = 1; i <= n + 1; i++) {  
        e[i][i - 1] = q[i - 1];  
        w[i][i - 1] = q[i - 1];  
        t += 2;  
    }  
    for (l = 1; l <= n; l++) {  
        t++;  
        for (i = 1; i <= n - l + 1; i++) {  
            t++;  
            j = i + l - 1;  
            e[i][j] = FLT_MAX;  
            w[i][j] = w[i][j - 1] + p[j] + q[j];  
            t += 3;  
            for (r = i; r <= j; r++) {  
                t++;  
                float cost = e[i][r - 1] + e[r + 1][j] + w[i][j];  
                t += 3;  
                if (cost < e[i][j]) {  
                    e[i][j] = cost;  
                    root[i][j] = r;  
                    t += 2;  
                }  
            }  
        }  
    }  
    printf("Minimum expected search cost: %.2f\n", e[1][n]);  
    printf("Total time complexity count: %d\n", t);  
}  
int main() {  
    int keys[] = {15, 20, 25, 30};  
    float p[] = {0.3f, 0.3f, 0.1f, 0.1f};  // probabilities of keys  
    float q[] = {0.2f, 0.3f, 0.1f, 0.1f, 0.1f}; // probabilities of dummy keys  
    int n = 4;  
    obst(keys, p, q, n);  
    return 0;  
}