#include <stdio.h>  
int main() {  
    int arr[100], n, i, j, temp,t=0;  
    printf("Enter the number of elements: ");  
    scanf("%d", &n);  
    printf("Enter %d elements:\n", n);  
    for (i = 0; i < n; i++) {  
        scanf("%d", &arr[i]);  
    }  
    for (i = 0; i < n; i++) {  
     t=t+3;  
        for (j = 0; j < n - i - 1; j++) {  
         t=t+3;  
            if (arr[j] > arr[j + 1]) {  
                temp = arr[j];  
                arr[j] = arr[j + 1];  
                arr[j + 1] = temp;  
                t=t+7;  
            }  
        }  
    }  
    printf("Sorted array:\n");  
    for (i = 0; i < n; i++) {  
        printf("%d ", arr[i]);  
    }  
printf("Time taken:%d",t);  
    return 0;  
} 