import java.util.Scanner;

public class Main
{
    
    static int choose_dish(int array[], int n)
    {
        int frequency[] = new int[1001];
        
        for (int i=0; i<1001 ; i++)
            frequency[i] = 0;
            
        int max = 0, result= 0;

        for(int i = 0 ; i < n-1 ; i++ )
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
    
    
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

        int test = sc.nextInt();

        while(test != 0)
        {
            int n = sc.nextInt();
            int array[] = new int[n];

            for (int i = 0; i < n; i++)
                array[i] = sc.nextInt();

            int result = choose_dish(array, n);

            System.out.println(result);
            test--;

        }
    }
}
