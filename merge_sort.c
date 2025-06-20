#include <stdio.h>  
int t=0;  
void merge(int arr[], int left, int mid, int right) {  
    int n1 = mid - left + 1;  
    int n2 = right - mid;  
    t=t+5;  
    int leftArr[n1], rightArr[n2];  
    for (int i = 0; i < n1; i++)  
        leftArr[i] = arr[left + i];  
        t=t+5;  
    for (int j = 0; j < n2; j++)  
        rightArr[j] = arr[mid + 1 + j];  
        t=t+6;  
    int i = 0, j = 0, k = left;  
    while (i < n1 && j < n2) {  
        if (leftArr[i] <= rightArr[j]) {  
            arr[k] = leftArr[i];  
            i++;  
            t=t=6;  
        } else {  
            arr[k] = rightArr[j];  
            j++;  
            t=t+3;  
        }  
        k++;  
        t=t+1;  
    }  
    while (i < n1) {  
        arr[k] = leftArr[i];  
        i++;  
        k++;  
        t=t+4;  
    }  
    while (j < n2) {  
        arr[k] = rightArr[j];  
        j++;  
        k++;  
        t=t=4;  
    }  
}  
void mergeSort(int arr[], int left, int right) {  
    if (left < right) {  
        int mid = left + (right - left) / 2;  
        t=t=5;  
        mergeSort(arr, left, mid);  
        mergeSort(arr, mid + 1, right);  
        merge(arr, left, mid, right);  
    }  
}  
int main() {  
    int n;  
    printf("Enter number of elements: ");  
    scanf("%d", &n);  
    int arr[n];  
    printf("Enter %d elements: \n", n);  
    for (int i = 0; i < n; i++) {  
        scanf("%d", &arr[i]);  
    }  
    mergeSort(arr, 0, n - 1);  
    printf("Sorted array: \n");  
    for (int i = 0; i < n; i++) {  
        printf("%d ", arr[i]);  
    }  
    printf("\n");  
printf("Time taken :%d",t);  
    return 0;  
} 