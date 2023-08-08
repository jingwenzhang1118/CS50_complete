#include <stdio.h>

int add(int num1, int num2)
{
    int sum;
    sum = num1 + num2;
    return sum;
}


int main(void)
{
    int var1, var2;
    printf("Enter number 1: ");
    scanf("%d", &var1);
    printf("Enter number 2: ");
    scanf("%d", &var2);

    int res = add (var1, var2);
    printf("Output: %d\n", res);

    return 0;
}

