#include<stdio.h>

int sum(int array[], int N)
{
    int total = 0;

    for(int i=0; i<N; i++)
        total += array[i];

    return total;
}

void rank(int subjects, int student_1[], int student_2[], int student_3[])
{
    

    int mark_1 = sum(student_1,subjects);
    int mark_2 = sum(student_2,subjects);
    int mark_3 = sum(student_3,subjects);

    int array[3] = {mark_1,mark_2,mark_3};
    

     for (int i = 0; i < 3; ++i) 
        { 
            for (int j = i + 1; j < 3; ++j)
            { 
                if (array[i] < array[j]) 
                { 
                    int a =  array[i];
                    array[i] = array[j];
                    array[j] = a; 
                } 
            } 
        }

    int one,two,three;

    for (int i=0; i<3;i++)
    {   
        
        if (array[i] == mark_1)
            one = i+1;

        if (array[i] == mark_2)
            two = i+1;

        if (array[i] == mark_3)
            three = i+1;
    }

    printf("%d %d %d",one,two,three);
}

int main()
{
    int subjects;

    scanf("%d",&subjects);
    
    int student_1[subjects];
    int student_2[subjects];
    int student_3[subjects];

    for(int i=0; i<subjects; i++)
        scanf("%d",&student_1[i]);

    for(int i=0; i<subjects; i++)
        scanf("%d",&student_2[i]);

    for(int i=0; i<subjects; i++)
        scanf("%d",&student_3[i]);

    rank(subjects, student_1, student_2, student_3);

    return 0;
}

