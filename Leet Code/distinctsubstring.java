import java.util.Scanner;

class Main{

    static int countstring(String str)
    {
        int length = str.length();
        int answer = length * (length+1)/2;

        return answer;
    }

    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);

        String str = sc.nextLine();

        System.out.println(countstring(str));
    }
}
