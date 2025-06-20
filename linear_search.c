#include <stdio.h>  
int SequentialSearch(int arr[], int n, int key) {  
    int i, flag = 0, t = 0;  
    for (i = 0; i < n; i++) {  
        t = t + 3;   
        if (arr[i] == key) {  
            t = t + 1;  
            printf("Element found at index %d.\n", i);  
            flag = 1;  
            break;  
        }  
    }  
    if (flag == 0) {  
        printf(" Element not found.\n");  
    }  
    return t;   
}

int main() {  
    int n, key, i, t;  
    printf("Enter the number of elements in the array: ");  
    scanf("%d", &n);  
    int arr[n];  
    printf("Enter %d elements:\n", n);  
    for (i = 0; i < n; i++) {  
        scanf("%d", &arr[i]);  
    }  
    printf("Enter the element to search: ");  
    scanf("%d", &key);  
    t = SequentialSearch(arr, n, key);  
    printf("Time taken: %d units\n", t);  
    return 0;  
}