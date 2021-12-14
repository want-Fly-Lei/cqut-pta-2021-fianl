import java.util.Scanner;
import java.util.*;

public class Main 
{
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n=input.nextInt();
        String str=new String();
        String c=input.nextLine();//去掉回车
        
        for(int i=0;i<n;i++)
        {
            Scanner in = new Scanner(input.nextLine());
            while(true)
            {
                str=in.next();
                StringBuilder stbu=new StringBuilder(str);
 
                if(in.hasNext())
                    System.out.print(stbu.reverse()+" ");
                else
                {
                    System.out.println(stbu.reverse());
                    break;
                }
            }
        }
    }
}
