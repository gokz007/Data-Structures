#include <stdio.h>  
#define MAX 10  
int t = 0;  
void warshall(int G[MAX][MAX], int n, int p[MAX][MAX]) {  
    for (int i = 0; i < n; i++) {  
        for (int j = 0; j < n; j++) {  
            p[i][j] = G[i][j];  
            t += 2;  
        }  
    }  
    for (int k = 0; k < n; k++) {  
        for (int i = 0; i < n; i++) {  
            for (int j = 0; j < n; j++) {  
                p[i][j] = p[i][j] || (p[i][k] && p[k][j]);  
                t += 5;  
            }  
        }  
    }  
}  
int main() {  
    int n;  
    int G[MAX][MAX], p[MAX][MAX];  
    printf("Enter the number of vertices: ");  
    scanf("%d", &n);  
    printf("Enter the adjacency matrix (use 0/1 only):\n");  
    for (int i = 0; i < n; i++) {  
        for (int j = 0; j < n; j++) {  
            scanf("%d", &G[i][j]);  
            t++;  
        }  
    }  
    warshall(G, n, p);  
    printf("\nPath Matrix (Transitive Closure):\n");  
    for (int i = 0; i < n; i++) {  
        for (int j = 0; j < n; j++) {  
            printf("%d ", p[i][j]);  
        }  
        printf("\n");  
    }  
    printf("Total time taken = %d\n", t);  
    return 0;  
} 