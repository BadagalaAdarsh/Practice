import java.util.Scanner;

public class classstudents
{
 static int sum(int array[], int N)
    {
        int total = 0;

        for(int i=0; i<N; i++)
            total += array[i];

        return total;
    }

    static void rank(int subjects, int[] student_1, int[] student_2, int[] student_3)
    {
        

        int mark_1 = sum(student_1,subjects);
        int mark_2 = sum(student_2,subjects);
        int mark_3 = sum(student_3,subjects);

        int array[] = new int[3];
        array[0] = mark_1;
        array[1] = mark_2;
        array[2] = mark_3;
        

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

        int one = 0, two = 0, three = 0;

        for (int i=0; i<3;i++)
        {   
            
            if (array[i] == mark_1)
                one = i+1;

            if (array[i] == mark_2)
                two = i+1;

            if (array[i] == mark_3)
                three = i+1;
        }

        System.out.println(one+" "+two+" "+three);
    }

    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);

        int subjects = sc.nextInt();
        
        int student_1[] = new int[subjects];
        int student_2[] = new int[subjects];
        int student_3[] = new int[subjects];

        for(int i=0; i<subjects; i++)
            student_1[i] = sc.nextInt();

        for(int i=0; i<subjects; i++)
            student_2[i] = sc.nextInt();

        for(int i=0; i<subjects; i++)
            student_3[i] = sc.nextInt();
        
        rank(subjects,student_1,student_2,student_3);
    }
}
