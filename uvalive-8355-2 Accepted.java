
import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	private static int lower_bound(BigInteger x[], int l, int r, BigInteger k) {
		if(x[r].compareTo(k)<0) return r+1;
		int mid;
		while(l+1<r) {
			mid = l+r>>1;
			if(x[mid].compareTo(k)>=0) r=mid;
			else l=mid+1;
		}
		if(x[l].compareTo(k)>=0) return l;
		else return r;
	}
	private static BigInteger dis(BigInteger a, BigInteger b) {
		if(a.compareTo(b)<0) return b.subtract(a);
		else return a.subtract(b);
	}
	public static void main(String[] args) {
		BigInteger x[][] = new BigInteger[10][100010];
		for(int i=1;i<100000;++i) x[1][i]=BigInteger.valueOf(i);
		for(int i=2;i<10;++i)
			for(int j=1;j<100000;++j)
				x[i][j]=x[i-1][j].multiply(BigInteger.valueOf(j));
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		while(t>0) {
			--t;
			int n,z,sx=0,sy=0;
			n=sc.nextInt();
			z=sc.nextInt();
			BigInteger ans=x[n][z];
			for(int i=z-1;i>=2;--i) {
				BigInteger res = x[n][z].subtract(x[n][i]);
				int pos=lower_bound(x[n],1,i-1,res);
//				System.out.println(pos);
				if(pos<i && x[n][pos].compareTo(res)==0) {
					ans = BigInteger.valueOf(0);
					sy = i; sx = pos;
				} else {
					if(pos<i && dis(x[n][pos], res).compareTo(ans)<0) {
						ans = dis(x[n][pos], res);
						sy = i; sx = pos;
					}
					if(pos-1>0 && dis(x[n][pos-1], res).compareTo(ans)<0) {
						ans = dis(x[n][pos-1], res);
						sy =i; sx = pos-1;
					}
				}
			}
			System.out.println(sx + " " + sy + " " + ans);
		}
	}
}

