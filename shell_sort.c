#include <stdio.h>  
int main() {  
    int arr[100], n, i, j, gap, temp,t=0;  
    printf("Enter the number of elements: ");  
    scanf("%d", &n);  
    printf("Enter %d elements:\n", n);  
    for(i = 0; i < n; i++) {  
        scanf("%d", &arr[i]);  
    }  
    for(gap = n / 2; gap > 0; gap /= 2) {  
     t=t+4;  
        for(i = gap; i < n; i++) {  
         t=t+3;  
  
            for(j = i - gap; j >= 0 && arr[j + gap] < arr[j]; j -= gap) {  
             t=t+7;  
                temp = arr[j];  
                arr[j] = arr[j + gap];  
                arr[j + gap] = temp;  
                t=t+5;  
            }  
        }  
    }  
    printf("Sorted array in ascending order:\n");  
    for(i = 0; i < n; i++) {  
       t++; 
        printf("%d ", arr[i]);  
    }  
printf("Time taken :%d",t);  
    return 0;  
} 
