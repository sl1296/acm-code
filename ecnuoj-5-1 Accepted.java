
import java.math.BigInteger;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in=new Scanner(System.in);
		int n=in.nextInt();
		BigInteger a[]=new BigInteger[110];
		a[0]=BigInteger.ZERO;
		a[1]=BigInteger.ONE;
		for(int i=2;i<=n;i++) {
			a[i]=a[i-2].add(BigInteger.ONE).multiply(BigInteger.valueOf(i*i)).add(a[i-1]);
		}
		System.out.println(a[n]);
	}

}

