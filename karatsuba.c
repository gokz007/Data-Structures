#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
void trim_leading_zeros(char *str) {  
    int len = strlen(str);  
    int index = 0;  
    while (index < len - 1 && str[index] == '0') index++;  
    if (index != 0) memmove(str, str + index, len - index + 1);  
}  
void pad_strings(char **a, char **b) {  
    int len1 = strlen(*a);  
    int len2 = strlen(*b);  
    int maxlen = len1 > len2 ? len1 : len2;  
    if (maxlen % 2 != 0) maxlen++;  // make length even  
    *a = realloc(*a, maxlen + 1);  
    *b = realloc(*b, maxlen + 1);  
    char *tmpa = (char *)calloc(maxlen + 1, sizeof(char));  
    char *tmpb = (char *)calloc(maxlen + 1, sizeof(char));  
    memset(tmpa, '0', maxlen - len1);  
    strcpy(tmpa + maxlen - len1, *a);  
    memset(tmpb, '0', maxlen - len2);  
    strcpy(tmpb + maxlen - len2, *b);  
    tmpa[maxlen] = '\0';  
    tmpb[maxlen] = '\0';  
    strcpy(*a, tmpa);  
    strcpy(*b, tmpb);  
    free(tmpa);  
    free(tmpb);  
}  
char *add(char *num1, char *num2) {  
    int len = strlen(num1);  
    char *res = (char *)calloc(len + 2, sizeof(char));  
    int carry = 0;  
    for (int i = len - 1; i >= 0; i--) {  
        int sum = (num1[i] - '0') + (num2[i] - '0') + carry;  
        res[i + 1] = (sum % 10) + '0';  
        carry = sum / 10;  
    }  
    res[0] = carry + '0';  
    res[len + 1] = '\0';  
    trim_leading_zeros(res);  
    return res;  
}  
char *subtract(char *num1, char *num2) {  
    int len = strlen(num1);  
    char *res = (char *)calloc(len + 1, sizeof(char));  
    int borrow = 0;  
    for (int i = len - 1; i >= 0; i--) {  
        int diff = (num1[i] - '0') - (num2[i] - '0') - borrow;  
        if (diff < 0) {  
            diff += 10;  
            borrow = 1;  
        } else {  
            borrow = 0;  
        }  
        res[i] = diff + '0';  
    }  
    res[len] = '\0';  
    trim_leading_zeros(res);  
    return res;  
}  
char *shift(char *num, int n) {  
    int len = strlen(num);  
    char *res = (char *)calloc(len + n + 1, sizeof(char));  
    strcpy(res, num);  
    for (int i = 0; i < n; i++)  
        res[len + i] = '0';  
    res[len + n] = '\0';  
    return res;  
}  
char *karatsuba(char *x, char *y) {  
    pad_strings(&x, &y);  
    int n = strlen(x);  
    if (n == 1) {  
        int prod = (x[0] - '0') * (y[0] - '0');  
        char *res = (char *)calloc(3, sizeof(char));  
        sprintf(res, "%d", prod);  
        return res;  
    }  
    int m = n / 2;  
    char *a = strndup(x, m);  
    char *c = strdup(x + m);  
    char *b = strndup(y, m);  
    char *d = strdup(y + m);  
    char *ac = karatsuba(a, b);  
    char *bd = karatsuba(c, d);  
    char *a_plus_c = add(a, c);  
    char *b_plus_d = add(b, d);  
    char *abcd = karatsuba(a_plus_c, b_plus_d);  
    char *ad_plus_bc = subtract(subtract(abcd, ac), bd);  
    char *ac_shifted = shift(ac, 2 * m);  
    char *adbc_shifted = shift(ad_plus_bc, m);  
    char *sum = add(ac_shifted, adbc_shifted);  
    char *final_res = add(sum, bd);  
    trim_leading_zeros(final_res);  
    free(a); free(b); free(c); free(d);  
    free(ac); free(bd); free(abcd); free(ad_plus_bc);  
    free(ac_shifted); free(adbc_shifted); free(sum);  
    return final_res;  
}  
int main() {  
    char *num1 = (char *)malloc(512), *num2 = (char *)malloc(512);  
    printf("Enter first large number: ");  
    scanf("%s", num1);  
    printf("Enter second large number: ");  
    scanf("%s", num2);  
    char *result = karatsuba(num1, num2);  
    printf("\nProduct: %s\n", result);  
  
    free(num1);  
    free(num2);  
    free(result);  
    return 0;  
} 