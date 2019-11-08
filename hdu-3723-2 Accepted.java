
import java.util.*;
import java.math.*;
class Main
{
	public static void main(String[] args)
	{
		Scanner cin = new Scanner(System.in);
		int n,i;
		BigInteger ans,tmp;
		while(cin.hasNext()){
            n=cin.nextInt();
            ans=BigInteger.ONE;
            tmp=BigInteger.ONE;
            for(i=0;i<n/2;i++)
            {
                tmp=tmp.multiply(BigInteger.valueOf(n-2*i)).multiply(BigInteger.valueOf(n-2*i-1)).divide(BigInteger.valueOf(i+1)).divide(BigInteger.valueOf(i+2));
                ans=ans.add(tmp);
            }
            ans=ans.mod(BigInteger.TEN.pow(100));
            System.out.println(ans);
		}
	}
}


