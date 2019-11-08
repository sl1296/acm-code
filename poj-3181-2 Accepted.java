

import java.math.BigInteger;
import java.util.*;
public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		BigInteger dp[][]=new BigInteger[1010][110];
		Scanner in=new Scanner(System.in);
		while(in.hasNext()) {
			int n=in.nextInt();
			int k=in.nextInt();
			dp[1][1]=BigInteger.ONE;
			for(int i=2;i<=k;i++)dp[1][i]=BigInteger.ZERO;
			for(int i=2;i<=n;i++) {
				for(int j=1;j<=k;j++) {
					if(i-j<=0) {
						dp[i][j]=BigInteger.ZERO;
					}else {
						dp[i][j]=dp[i-j][j];
					}
				}
				if(i<=k)dp[i][i]=BigInteger.ONE;
				for(int j=k-1;j>0;j--)dp[i][j]=dp[i][j].add(dp[i][j+1]);
			}
			System.out.println(dp[n][1]);
		}
		in.close();
	}

}

