
import java.util.Scanner;
import java.math.BigInteger;
public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner cin=new Scanner(System.in);
		int[] cnt=new int[] {0,0,1,1,1,3,3,1};
		BigInteger[] ans=new BigInteger[2010];
		BigInteger[] add=new BigInteger[2010];
		for(int i=0;i<2005;i++)ans[i]=add[i]=BigInteger.ZERO;
		add[2]=add[3]=add[4]=add[7]=BigInteger.ONE;
		add[5]=BigInteger.valueOf(3);
		add[6]=BigInteger.valueOf(2);
		for(int i=2;i<2005;i++) {
			for(int j=2;j<8;j++) {
				if(i-j>0) {
					add[i]=add[i].add(BigInteger.valueOf(cnt[j]).multiply(add[i-j]));
				}
			}
		}
		add[6]=add[6].add(BigInteger.ONE);
		for(int i=2;i<2005;i++) {
			ans[i]=ans[i-1].add(add[i]);
		}
		while(cin.hasNext()) {
			int a=cin.nextInt();
			System.out.println(ans[a]);
		}
	}

}

