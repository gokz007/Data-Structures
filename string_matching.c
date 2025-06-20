#include <stdio.h>  
#include <string.h>  
int t=0;  
int string_match(char a[], char p[]) {  
    int n = strlen(a);  
    int m = strlen(p);  
    t=t=2;  
    int i, j;  
    for (i = 0; i <= n - m; i++) {  
        j = 0;  
        t=t+5;  
        while (j < m && p[j] == a[i + j])  
            j++;  
            t=t+5;  
        if (j == m)  
            return i;  
    }  
    return -1;  
}  
int main() {  
    char a[100], p[100];  
    printf("Enter the main string: ");  
    scanf("%s", a);  
    printf("Enter the pattern: ");  
    scanf("%s", p);  
    int index = string_match(a, p);  
    if (index != -1)  
        printf("Pattern found at index: %d\n", index);  
    else  
        printf("Pattern not found\n");  
printf("Time taken :%d",t);  
    return 0;  
} 