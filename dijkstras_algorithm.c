#include <stdio.h>  
#define MAX 100  
#define INF 999999  
int t = 0;  
int searchMin(int length[], int selected[], int n) {  
    int min = INF, idx = -1;  
    for (int i = 0; i < n; i++) {  
        t += 2;  
        if (!selected[i] && length[i] < min) {  
            min = length[i];  
            idx = i;  
            t++;  
        }  
    }  
    return idx;  
}  
int main() {  
    int n, S;  
    int G[MAX][MAX], length[MAX], path[MAX], selected[MAX] = {0};  
    printf("Enter number of vertices: ");  
    scanf("%d", &n); t++;  
    printf("Enter the adjacency matrix (0 if no edge):\n");  
    for (int i = 0; i < n; i++)  
        for (int j = 0; j < n; j++) {  
            scanf("%d", &G[i][j]); t++;  
            if (i != j && G[i][j] == 0) G[i][j] = INF;  
        }  
    printf("Enter the source vertex (0 to %d): ", n - 1);  
    scanf("%d", &S); t++;  
    for (int i = 0; i < n; i++) {  
        if (G[S][i] != INF) {  
            length[i] = G[S][i];  
            path[i] = S;  
        } else {  
            length[i] = INF;  
            path[i] = -1;  
        }  
        selected[i] = 0;  
        t += 4;  
    }  
    length[S] = 0; selected[S] = 1; t += 2;  
    for (int count = 1; count < n; count++) {  
        int u = searchMin(length, selected, n);  
        if (u == -1) break;  
        selected[u] = 1; t++;  
        for (int v = 0; v < n; v++) {  
            if (!selected[v] && G[u][v] != INF && length[u] + G[u][v] < length[v]) 
{  
                length[v] = length[u] + G[u][v];  
                path[v] = u;  
                t += 2;  
            }  
            t += 2;}}  
    printf("\nShortest distances from source vertex %d:\n", S);  
    for (int i = 0; i < n; i++) {  
        if (length[i] == INF)  
            printf("Vertex %d: Unreachable\n", i);  
        else  
            printf("Vertex %d: Distance = %d, Predecessor = %d\n", i, length[i], 
path[i]);  
    }  
    printf("Total time taken = %d\n", t);  
    return 0;  
}