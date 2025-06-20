#include <stdio.h>  
int t=0;  
void swap(int *a, int *b) {  
    int temp = *a;  
    *a = *b;  
    *b = temp;  
    t=t+3;  
}  
void heapify(int arr[], int n, int i) {  
    int lar = i;  
    int left = 2 * i + 1;  
    int right = 2 * i + 2;  
    t=t=7;  
    if (left < n && arr[left] > arr[lar])  
        lar = left;  
        t=t=4;  
    if (right < n && arr[right] > arr[lar])  
        lar = right;  
        t=t=4;  
    if (lar != i) {  
        swap(&arr[i], &arr[lar]);  
        heapify(arr, n, lar);  
    }  
}  
int main() {  
    int n;  
    printf("Enter the number of elements: ");  
    scanf("%d", &n);  
    int arr[n];  
    printf("Enter the elements: ");  
    for (int i = 0; i < n; i++) {  
        scanf("%d", &arr[i]);  
    }  
    for (int i = n / 2 - 1; i >= 0; i--) {  
     t=t=5;  
        heapify(arr, n, i);  
    }  
    for (int i = n - 1; i > 0; i--) {  
     t=t+4;  
        swap(&arr[0], &arr[i]);    
        heapify(arr, i, 0);         
    }  
    printf("Sorted array: ");  
    for (int i = 0; i < n; i++) {  
        printf("%d ", arr[i]);  
    }  
    printf("\n");  
printf("Time taken :%d",t);  
    return 0;  
}