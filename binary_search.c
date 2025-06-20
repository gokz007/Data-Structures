#include <stdio.h>  
int main() {  
    int n, key, i, low, high, mid,t=0;      
    printf("Enter the number of elements (sorted): ");  
    scanf("%d", &n);  
    int arr[n];  
    printf("Enter %d sorted elements:\n", n);  
    for (i = 0; i < n; i++) {  
     t=t+3;  
        scanf("%d", &arr[i]);  
    }  
    printf("Enter the element to search: ");  
    scanf("%d", &key);  
    low = 0;  
    high = n - 1;  
    int found = 0;  
    t=t+3;  
    while (low <= high) {  
        mid = (low + high) / 2;  
  t=t+3;  
        if (arr[mid] == key) {  
            printf("Search is successful. Element found at index %d.\n", mid);  
            found = 1;  
            t=t+2;  
            break;  
        }  
        else if (arr[mid] > key) {  
            high = mid - 1;  
            t=t+3;  
        }  
        else {  
            low = mid + 1;  
            t=t+2;  
        }  
    }  
    if (!found) {  
        printf("Search is unsuccessful. Element not found.\n");  
    }  
printf("Time taken:%d",t);  
    return 0;  
}