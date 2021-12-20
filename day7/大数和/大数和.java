import java.util.Scanner;
import java.math.BigInteger;

public class 大数和 {
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        while(true)
        {
            BigInteger sum=new BigInteger("0");
            int n=input.nextInt();
            if(n==0)
                break;
            BigInteger[] number=new BigInteger[n];

            for(int i=0;i<n;i++)
                number[i]=new BigInteger(input.next());

            for(int i=0;i<n;i++)
                sum=sum.add(number[i]);

            System.out.println(sum);
        }
        input.close();
    }
}