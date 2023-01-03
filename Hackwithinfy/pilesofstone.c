#include<stdio.h>
#define min(a, b) (((a) < (b)) ? (a) : (b))

const char *ispossible(long long int a, long long int b, long long int c, long long int x, long long int y)
{

    if ((a+b+c) != (x+y))
    {
        return "NO";
    }

    else if ( y < min(a,min(b,c)) || x < min(a, min(b,c)))
    {
        return "NO";
    }

    else
    {
        return "YES";
    }
}

int main()
{
    int test;
    scanf("%d",&test);

    while (test--)
    {
        long long int a, b, c, x, y;

        scanf("%lld%lld%lld%lld%lld",&a,&b,&c,&x,&y);

        printf("%s\n",ispossible(a,b,c,x,y));
    }

    return 0;
}
