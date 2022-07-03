#include <stdio.h>

int myAtoi(char *str)
{
    int res = 0;    // Initalise result
    int sign = 1;   // Initalise sign as positive
    int i = 0;      // Initalise index of first digit

    // If number is negative, then update sign
    if (str[0] == '-')
    {
        sign = -1;
        i++;
    }

    for (; str[i] != '\0'; i++)
        res = res*10 + str[i] - '0';        // asci '0' = 48,   asci '1' = 49,  '1' - '0' = 1
    
    return sign*res;
}

int main() {
    char str1[] = "-1234";
    int val = myAtoi(str1);
    printf("%d",val);
    return 0;
}