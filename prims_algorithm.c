#include <stdio.h>  
#define MAX 10  
#define INF 9999  
int t = 0;  
void prim(int G[MAX][MAX], int n, int TREE[MAX][MAX]) {  
    int selected[MAX] = {0};  
    int i, j, x, y, min, ne = 0;  
    for (i = 0; i < n; i++) {  
        for (j = 0; j < n; j++) {  
            TREE[i][j] = 0;  
            t++;  
        }  
    }  
    selected[0] = 1;  
    t++;  
    while (ne < n - 1) {  
        min = INF;  
        for (i = 0; i < n; i++) {  
            if (selected[i]) {  
                for (j = 0; j < n; j++) {  
                    if (!selected[j] && G[i][j]) {  
                        if (G[i][j] < min) {  
                            min = G[i][j];  
                            x = i;  
                            y = j;  
                            t += 5;  
                        }  
                        t += 3;  
                    }  
                    t += 2;  
                }  
            }  
            t++;  
        }  
        TREE[x][y] = TREE[y][x] = 1;  
        selected[y] = 1;  
        ne++;  
        t += 4;  
    }  
}  
int main() {  
    int G[MAX][MAX], TREE[MAX][MAX], n, i, j;  
    printf("Enter the number of vertices: ");  
    scanf("%d", &n);  
    printf("Enter the adjacency matrix (enter 0 if no edge, INF as 9999):\n");  
    for (i = 0; i < n; i++) {  
        for (j = 0; j < n; j++) {  
            scanf("%d", &G[i][j]);  
            if (G[i][j] == 0)  
                G[i][j] = INF;  
            t++;  
        }  
    }  
  
    prim(G, n, TREE);  
    printf("\nMinimum Spanning Tree (as adjacency matrix of edges used):\n");  
    for (i = 0; i < n; i++) {  
        for (j = 0; j < n; j++) {  
            printf("%d ", TREE[i][j]);  
        }  
        printf("\n");  
    }  
    printf("Total time taken = %d\n", t);  
    return 0;  
}