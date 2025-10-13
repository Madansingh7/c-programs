//Write a C program to find nth element of fibonacci series recursively
#include<stdio.h>

int fibonacci(int n)
{
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    return (fibonacci(n - 1) + fibonacci(n - 2));    
}

main()
{
    int n;
    printf("Enter n value: ");
    scanf("%d", &n);
    for(int i=0; i<=n; i++){
    printf("Fib(%d) is %d\n", i, fibonacci(i));
    }
}