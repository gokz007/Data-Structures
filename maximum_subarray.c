#include <stdio.h>  
int t=0;  
int maxCrossSum(int arr[], int low, int mid, int high) {  
    int sum = 0, left_sum = -2147483648, right_sum = -2147483648, i;  
    for (i = mid; i >= low; i--) {  
     t=t+3;  
        sum += arr[i];  
        if (sum > left_sum)  
            left_sum = sum;  
            t=t=4;  
    }  
    sum = 0;  
    for (i = mid + 1; i <= high; i++) {  
     t=t=5;  
        sum += arr[i];  
        if (sum > right_sum)  
            right_sum = sum;  
            t=t=4;  
    }  
    return left_sum + right_sum;  
    t=t+1;}  
int maxSubArraySum(int arr[], int low, int high) {  
    if (low == high)  
        return arr[low];  
    int mid = (low + high) / 2;  
    t=t+3;  
    int left_sum = maxSubArraySum(arr, low, mid);  
    int right_sum = maxSubArraySum(arr, mid + 1, high);  
    int cross_sum = maxCrossSum(arr, low, mid, high);  
    if (left_sum >= right_sum && left_sum >= cross_sum)  
        return left_sum;  
    else if (right_sum >= left_sum && right_sum >= cross_sum)  
        return right_sum;  
    else  
        return cross_sum;}  
 
int main() {  
    int n, i;  
    printf("Enter number of elements: ");  
    scanf("%d", &n);  
    int arr[n];  
    printf("Enter array elements:\n");  
    for (i = 0; i < n; i++)  
        scanf("%d", &arr[i]);  
    int max_sum = maxSubArraySum(arr, 0, n - 1);  
    printf("Maximum subarray sum: %d\n", max_sum);  
printf("Time taken :%d",t);  
    return 0;
}