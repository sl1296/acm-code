
import java.util.Scanner;
import java.math.BigInteger;
public class Main {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner cin=new Scanner(System.in);
		BigInteger[] a=new BigInteger[110];
		BigInteger tmp=BigInteger.ONE;
		a[1]=BigInteger.ONE;
		int i;
		for(i=2;i<105;i++) {
			a[i]=a[i-1].multiply(BigInteger.valueOf(4*i-2)).divide(BigInteger.valueOf(i+1));
		}
		for(i=2;i<105;i++) {
			tmp=tmp.multiply(BigInteger.valueOf(i));
			a[i]=a[i].multiply(tmp);
		}
		while(true) {
			int n=cin.nextInt();
			if(n==0)break;
			System.out.println(a[n]);
		}
	}
}

