import java.util.Scanner;

public class Main
{
    
    static String ispossible(int a, int b, int c, int x, int y)
    {
        if ((a+b+c) != (x+y))
        {
            return "NO";
        }

        else if ( y < Math.min(a,Math.min(b,c)) || x < Math.min(a, Math.min(b,c)))
        {
            return "NO";
        }

        else
        {
            return "YES";
        }
    }
    
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

        int test = sc.nextInt();

        while (test != 0)
        {
            int a,b,c,x,y;

            a = sc. nextInt();
            b = sc.nextInt();
            c = sc.nextInt();
            x = sc.nextInt();
            y = sc.nextInt();

            String result = ispossible(a,b,c,x,y);

            System.out.println(result);
            test--;
        }
	}
}

