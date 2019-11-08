
import java.math.BigInteger;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in=new Scanner(System.in);
		int n=in.nextInt();
		String s="";
		BigInteger a[]=new BigInteger[500];
		a[0]=BigInteger.ONE;a[1]=a[0];
		for(int i=2;i<500;i++)a[i]=a[i-1].add(a[i-2]);
		for(int i=0;i<500;i++)s=s+a[i].toString();
		System.out.println(s.substring(0,n));
	}

}

