
import java.math.BigInteger;
import java.util.Scanner;

public class Main {

	static BigInteger num[] = new BigInteger[200];
	static Scanner in = new Scanner(System.in);
	static int s[] = new int[200];
	static BigInteger dp[] = new BigInteger[200];
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		num[0] = BigInteger.valueOf(1);
		for(int i = 1; i < 200 ; i++) {
			num[i] = num[i-1].multiply(BigInteger.valueOf(3));
		}
		while(in.hasNext()) {
			int len = 0;
			BigInteger n = in.nextBigInteger();
			BigInteger ans = n.add(BigInteger.valueOf(2)).multiply(n.add(BigInteger.ONE)).divide(BigInteger.valueOf(2));
			n = n.add(BigInteger.ONE);
			while(n.compareTo(BigInteger.ZERO) > 0) {
				s[++len] = n.mod(BigInteger.valueOf(2)).toString().charAt(0)-'0';
				n = n.divide(BigInteger.valueOf(2));
			}
			for(int i=0;i<=len;i++)
				dp[i] = BigInteger.valueOf(-1);
			BigInteger obb = dfs(len);
			System.out.println(ans.subtract(obb));
		}
	}
	private static BigInteger dfs(int len) {
		// TODO Auto-generated method stub
		if(!dp[len].equals(BigInteger.valueOf(-1))) return dp[len];
		if(len == 0) return BigInteger.ZERO;
		if(s[len] == 1) {
			dp[len] = num[len-1].add(dfs(len-1).multiply(BigInteger.valueOf(2)));
		}
		else {
			dp[len] = dfs(len-1);
		}
		//System.out.println(len + " " + dp[len]);
		return dp[len];
	}
	
}

