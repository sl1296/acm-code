
import java.util.Scanner;
import java.math.BigInteger;

class Main
{
	public static void main(String[] args)
	{
		Scanner cin = new Scanner(System.in);
		BigInteger []z=new BigInteger[110];
		int i;
        z[1]=BigInteger.ONE;
        for(i=2;i<101;i++){
            z[i]=z[i-1].multiply(BigInteger.valueOf(4*i-2));
            z[i]=z[i].divide(BigInteger.valueOf(i+1));
        }
		while (cin.hasNext()){
			int a = cin.nextInt();
			System.out.println(z[a]);
		}
	}
}

