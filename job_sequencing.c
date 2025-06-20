#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
int t = 0;  
struct job {  
    char id[10];  
    int deadline;  
    int profit;  
};  
int cmp(const void *a, const void *b) {  
    t += 1;  
    return ((struct job *)b)->profit - ((struct job *)a)->profit;  
}  
int main() {  
    int n;  
    printf("Enter number of jobs: ");  
    scanf("%d", &n);  
    struct job jobs[n];  
    for (int i = 0; i < n; i++) {  
        printf("Enter job id, deadline, and profit for job %d: ", i + 1);  
        scanf("%s %d %d", jobs[i].id, &jobs[i].deadline, &jobs[i].profit);  
    }  
    qsort(jobs, n, sizeof(struct job), cmp);  
    t += 5;  
    int max_deadline = 0;  
    for (int i = 0; i < n; i++) {  
        if (jobs[i].deadline > max_deadline)  
            max_deadline = jobs[i].deadline;  
    }  
    char result[max_deadline][10];  
    int slot[max_deadline];  
    for (int i = 0; i < max_deadline; i++) {  
        slot[i] = 0;  
    }  
    int tvalue = 0;  
    for (int i = 0; i < n; i++) {  
        t += 3;  
        for (int j = jobs[i].deadline - 1; j >= 0; j--) {  
            if (slot[j] == 0) {  
                slot[j] = 1;  
                strcpy(result[j], jobs[i].id);  
                tvalue += jobs[i].profit;  
                t += 7;  
                break;  
            }  
        }  
    }  
    printf("Scheduled Jobs: ");  
    for (int i = 0; i < max_deadline; i++) {  
        if (slot[i])  
            printf("%s ", result[i]);  
    }  
    printf("\nTotal profit: %d\n", tvalue);  
    printf("Time taken: %d\n", t);  
    return 0;  
} 