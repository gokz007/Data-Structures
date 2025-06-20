#include <stdio.h>  
#include <stdlib.h>  
#define MAX 100  
int t = 0;  
typedef struct {  
    int u, v, weight;  
} Edge;  
Edge edges[MAX], mst[MAX];  
int parent[MAX];  
int find(int i) {  
    while (i != parent[i]) {  
        i = parent[i];  
        t += 2;  
    }  
    return i;  
}  
void union_set(int i, int j) {  
    int a = find(i);  
    int b = find(j);  
    parent[a] = b;  
    t += 3;  
}  
int compare(const void *a, const void *b) {  
    Edge *e1 = (Edge *)a;  
    Edge *e2 = (Edge *)b;  
    t += 1;  
    return e1->weight - e2->weight;  
}  
int main() {  
    int n = 4, i, e = 5;  
    t = 2;  
    Edge inputEdge[] = {  
        {0, 1, 10},  
        {0, 2, 6},  
        {0, 3, 5},  
        {1, 3, 15},  
        {2, 3, 4}  
    };  
    for (i = 0; i < e; i++) {  
        edges[i] = inputEdge[i];  
        t += 4;  
    }  
    for (i = 0; i < n; i++) {  
        parent[i] = i;  
        t += 4;  
    }  
    qsort(edges, e, sizeof(Edge), compare);  
    int totalWeight = 0, count = 0;  
    for (i = 0; i < e && count < n - 1; i++) {  
        int u = edges[i].u;  
        int v = edges[i].v;  
        int w = edges[i].weight;  
        t += 8;  
        if (find(u) != find(v)) {  
            mst[count++] = edges[i];  
            union_set(u, v);  
            totalWeight += w;  
            t += 4;  
        }  
    }  
    printf("Minimum Spanning Tree:\n");  
    for (i = 0; i < count; i++) {  
        printf("%c -- %c = %d\n", mst[i].u + 'a', mst[i].v + 'a', mst[i].weight);  
    }  
    printf("Total weight of MST = %d\n", totalWeight);  
    printf("Total time taken = %d\n", t);  
    return 0;  
} 