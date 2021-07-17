#include<stdio.h>
#include<string.h>

int countstring(char *str)
{
    int length = strlen(str);
    int answer = length * (length+1)/2;

    return answer;
}

int main()
{
    char *str;
    scanf("%ms",&str);

    printf("%d", countstring(str));

    return 0;
}
