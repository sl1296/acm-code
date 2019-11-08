
/*
0_0_17804541_23791\Main.java:10: 错误: 找不到符号
            n=cin.nestInt();
                 ^
  符号:   方法 nestInt()
  位置: 类型为Scanner的变量 cin
0_0_17804541_23791\Main.java:11: 错误: 不兼容的类型: BigInteger无法转换为int
            ans=BigInteger.ONE;
                          ^
0_0_17804541_23791\Main.java:12: 错误: 不兼容的类型: BigInteger无法转换为int
            tmp=BigInteger.ONE;
                          ^
0_0_17804541_23791\Main.java:15: 错误: 无法取消引用int
                tmp=tmp.multiply(BigInteger.valueOf(n-2*i)).multiply(BigInteger.valueOf(n-2*i-1)).divide(BigInteger.valueOf(i+1)).divide(BigInteger.valueOf(i+2));
                       ^
0_0_17804541_23791\Main.java:16: 错误: 无法取消引用int
                ans=ans.add(tmp);
                       ^
0_0_17804541_23791\Main.java:18: 错误: 无法取消引用int
            ans=ans.mod(BigInteger.TEN.pow(100));
                   ^
6 个错误
*/
import java.util.*;
import java.math.*;
class Main
{
	public static void main(String[] args)
	{
		Scanner cin = new Scanner(System.in);
		int n,ans,tmp,i;
		while(cin.hasNext()){
            n=cin.nestInt();
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


