
import java.util.Scanner;
import java.math.BigInteger;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner cin=new Scanner(System.in);
		BigInteger[] a=new BigInteger[110];
		int i;
		a[1]=BigInteger.ONE;
		for(i=2;i<105;i++) {
			a[i]=a[i-1].multiply(BigInteger.valueOf(4*i-2)).divide(BigInteger.valueOf(i+1));
		}
		while(cin.hasNext()) {
			int n=cin.nextInt();
			System.out.println(a[n]);
		}
	}
}

