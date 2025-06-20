#include <stdio.h>  
#define MAX 100  
#define INF 999999  
typedef struct {  
    int u, v, w;  
} Edge;  
int main() {  
    int V, E, S, i, j;  
    int length[MAX], path[MAX];  
    Edge edge[MAX * MAX];  
    int G[MAX][MAX];  
    printf("Enter number of vertices: ");  
    scanf("%d", &V);  
    printf("Enter adjacency matrix (0 for no edge):\n");  
    for (i = 0; i < V; i++)  
        for (j = 0; j < V; j++)  
            scanf("%d", &G[i][j]);  
    printf("Enter source vertex (0 to %d): ", V-1);  
    scanf("%d", &S);  
    E = 0;  
    for (i = 0; i < V; i++)  
        for (j = 0; j < V; j++)  
            if (G[i][j] != 0) {  
                edge[E].u = i; edge[E].v = j; edge[E].w = G[i][j];  
                E++; }  
    for (i = 0; i < V; i++) {  
        length[i] = INF;  
        path[i] = -1;}  
    length[S] = 0;  
    for (i = 1; i <= V - 1; i++) {  
        for (j = 0; j < E; j++) {  
            int u = edge[j].u;  
            int v = edge[j].v;  
            int w = edge[j].w;  
            if (length[u] != INF && length[u] + w < length[v]) {  
                length[v] = length[u] + w;  
                path[v] = u;  
            }  
        }  }  
    for (j = 0; j < E; j++) {  
        int u = edge[j].u;  
        int v = edge[j].v;  
        int w = edge[j].w;  
        if (length[u] != INF && length[u] + w < length[v]) {  
            printf("Negative weight cycle detected!\n");  
            return 0; }}  
    printf("Vertex\tDistance from Source\tPredecessor\n");  
    for (i = 0; i < V; i++)  
        if (length[i] == INF)  
            printf("%d\t\tINF\t\t\t%d\n", i, path[i]);  
        else  
            printf("%d\t\t%d\t\t\t%d\n", i, length[i], path[i]);  
    return 0;
} 