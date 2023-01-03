#include<stdio.h>
#include<stdlib.h>

int choose_dish(long long int array[], long long int n)
{
    long long int frequency[1001] = {0};
    long long int max = 0, result;

    for(long long int i = 0 ; i < n-1 ; i++ )
    {
        frequency[array[i]]++;

        if (array[i] == array[i+1])
            i++;
    }

    for(int i = 1; i <= 1000; i++)
    {
        if (frequency[i] > max)
        {
            max = frequency[i];
            result = i;
        }
    }

    return result;
}

int main()
{
    long long int test;
    scanf("%lld",&test);
    
    while (test--)
    {
        long long int n;
               
        scanf("%lld",&n);
        long long int array[n];

        for (long long int i = 0 ; i < n ; i++ )
            scanf("%lld",&array[i]);

        int result = choose_dish(array, n);

        printf("%d\n",result);
    }
    return 0;
}
