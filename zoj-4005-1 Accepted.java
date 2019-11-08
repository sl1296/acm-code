
import java.util.*;
import java.math.*;

public class Main
{
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		int t=in.nextInt();
		for(int z=0;z<t;z++){
			BigInteger x=in.nextBigInteger();
			int p=(x.toString().length()+1)/2;
			char tmp[]=new char[p+1];
			tmp[0]='1';
			for(int i=1;i<=p;i++)tmp[i]='0';
			String tt=String.valueOf(tmp);
			BigInteger r=new BigInteger(tt);
			//System.out.println(r);
			while(true){
				BigInteger dec=r.multiply(r).subtract(x).divide(r.multiply(BigInteger.valueOf(2)));
				if(dec.compareTo(BigInteger.ZERO)<=0)break;
				r=r.subtract(dec);
			}
			String rr=r.toString();
			int rrr=rr.charAt(rr.length()-1);
			if(rrr%2==0)System.out.println("1");
			else System.out.println("0");
		}
	}
}

