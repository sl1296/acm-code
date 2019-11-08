
/*
0_0_17787586_10313\Main.java:13: 错误: 找不到符号
            z[i]=BigInteger.valuof(4*i-2).multiply(z[i-1]).divide(BigInteger.valueOf(i+1));
                           ^
  符号:   方法 valuof(int)
  位置: 类 BigInteger
0_0_17787586_10313\Main.java:15: 错误: 找不到符号
		while (in.hasnext()){
		       ^
  符号:   变量 in
  位置: 类 Main
2 个错误
*/
import java.util.Scanner;
import java.math.BigInteger;

class Main
{
	public static void main(String[] args)
	{
		Scanner cin = new Scanner(System.in);
		BigInteger []z=new BigInteger[110];
		int i;
        z[1]=BigInteger.ONE;
        for(i=2;i<101;i++){
            z[i]=BigInteger.valuof(4*i-2).multiply(z[i-1]).divide(BigInteger.valueOf(i+1));
        }
		while (in.hasnext()){
			int a = cin.nextInt();
			System.out.println(z[a]);
		}
	}
}

