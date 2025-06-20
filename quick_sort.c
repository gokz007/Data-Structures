#include <stdio.h>  
int t=0; 
void quickSort(int arr[], int low, int high)   
{  
    if (low < high)   
    {  
        int pivot = partition(arr, low, high);   
        quickSort(arr, low, pivot - 1);   
        quickSort(arr, pivot + 1, high);  
    }  
}  
int partition(int arr[], int low, int high)   
{  
    int pivot = arr[high];   
    int i = low - 1;   
 t=t=3;  
    for (int j = low; j < high; j++)   
    {  
     t=t+3;  
        if (arr[j] <= pivot)   
        {  
            i++;   
            int temp = arr[i];  
            arr[i] = arr[j];  
            arr[j] = temp;  
            t=t+5;  
        }  
    }  
    int temp = arr[i + 1];  
    arr[i + 1] = arr[high];  
    arr[high] = temp;  
    t=t+6;  
    return i + 1;  
}  
int main()   
{  
    int arr[] = {50, 8, 33, 24, 78, 100, 70};  
    int n = sizeof(arr) / sizeof(arr[0]);  
    printf("Unsorted array: \n");  
    for (int i = 0; i < n; i++)   
    {  
        printf("%d ", arr[i]);  
    }  
    printf("\n");  
    quickSort(arr, 0, n - 1);  
    printf("Sorted array: \n");  
    for (int i = 0; i < n; i++)   
    {  
        printf("%d ", arr[i]);  
    }  
    printf("\n");  
printf("Time taken (approximate operations) :%d",t);  
    return 0;  
} 