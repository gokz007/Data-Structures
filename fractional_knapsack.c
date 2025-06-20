#include <stdio.h>  
#include <stdlib.h>  
int t = 0;  
struct item {  
    int id;  
    int weight;  
    int profit;  
    float ratio;  
};  
int cmp(const void *a, const void *b) {  
    t += 1;  
    float r1 = ((struct item *)a)->ratio;  
    float r2 = ((struct item *)b)->ratio;  
    if (r2 > r1) return 1;  
    if (r2 < r1) return -1;  
    return 0;}  
int main() {  
    int n, w;  
    printf("Enter number of items: ");  
    scanf("%d", &n);  
    printf("Enter knapsack capacity: ");  
    scanf("%d", &w);  
    struct item items[n];  
    for (int i = 0; i < n; i++) {  
        printf("Enter id, weight and profit of item %d: ", i + 1);  
        scanf("%d %d %d", &items[i].id, &items[i].weight, &items[i].profit);  
        items[i].ratio = (float)items[i].profit / items[i].weight;  }  
    qsort(items, n, sizeof(struct item), cmp);  
    t += 5;  // qsort overhead approximation  
    float tvalue = 0.0;  
    int rem = w;  
    for (int i = 0; i < n; i++) {  
        t += 3;  
        if (items[i].weight <= rem) {  
            tvalue += items[i].profit;  
            rem -= items[i].weight;  
            t += 7;  
        } else {  
            tvalue += items[i].ratio * rem;  
            t += 4;  
            break;}  }  
    printf("Total profit: %.2f\n", tvalue);  
    printf("Time taken: %d\n", t);  
    return 0;
}