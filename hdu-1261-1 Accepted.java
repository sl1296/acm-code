
import java.util.Scanner;
import java.math.BigInteger;
public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] a=new int[30];
		BigInteger[] jc=new BigInteger[350];
		Scanner cin=new Scanner(System.in);
		jc[0]=BigInteger.ONE;
		for(int i=1;i<340;i++)jc[i]=jc[i-1].multiply(BigInteger.valueOf(i));
		while(true) {
			int n=cin.nextInt();
			if(n==0)break;
			int sum=0;
			for(int i=0;i<n;i++) {
				a[i]=cin.nextInt();
				sum+=a[i];
			}
			BigInteger ans=jc[sum];
			for(int i=0;i<n;i++)ans=ans.divide(jc[a[i]]);
			System.out.println(ans);
		}
	}

}

