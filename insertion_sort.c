#include <stdio.h>  
int main() {  
    int arr[100], n, i, j, key,t=0;  
    printf("Enter the number of elements: ");  
    scanf("%d", &n);  
    printf("Enter %d elements:\n", n);  
    for(i = 0; i < n; i++) {  
     t=t=3;  
        scanf("%d", &arr[i]);  
    }  
    for(i = 1; i < n; i++) {  
        key = arr[i];  
        j = i - 1;  
        t=t+6;  
        while(j >= 0 && arr[j] > key) {  
            arr[j + 1] = arr[j];  
            j--;  
            t=t=6;  
        }  
        arr[j + 1] = key;  
        t=t=2;  
    }  
    printf("Sorted array:\n");  
    for(i = 0; i < n; i++) {  
        printf("%d ", arr[i]);}  
printf("Time taken :%d",t);  
    return 0; 
}