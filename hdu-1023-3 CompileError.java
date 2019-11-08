
/*
0_0_17788159_10390\Main.java:12: 错误: 不兼容的类型: int无法转换为Long
        for(i=2;i<101;i++){
              ^
0_0_17788159_10390\Main.java:13: 错误: 不兼容的类型: Long无法转换为int
            z[i]=z[i-1].multiply(BigInteger.valueof(4*i-2));
              ^
0_0_17788159_10390\Main.java:13: 错误: 找不到符号
            z[i]=z[i-1].multiply(BigInteger.valueof(4*i-2));
                                           ^
  符号:   方法 valueof(long)
  位置: 类 BigInteger
0_0_17788159_10390\Main.java:13: 错误: 不兼容的类型: 从long转换到int可能会有损失
            z[i]=z[i-1].multiply(BigInteger.valueof(4*i-2));
                    ^
0_0_17788159_10390\Main.java:14: 错误: 不兼容的类型: Long无法转换为int
            z[i]=z[i].divide(BigInteger.valueOf(i+1));
              ^
0_0_17788159_10390\Main.java:14: 错误: 不兼容的类型: Long无法转换为int
            z[i]=z[i].divide(BigInteger.valueOf(i+1));
                   ^
0_0_17788159_10390\Main.java:16: 错误: 找不到符号
		while (cin.hasnext()){
		          ^
  符号:   方法 hasnext()
  位置: 类型为Scanner的变量 cin
7 个错误
*/
import java.util.Scanner;
import java.math.BigInteger;

class Main
{
	public static void main(String[] args)
	{
		Scanner cin = new Scanner(System.in);
		BigInteger []z=new BigInteger[110];
		Long i;
        z[1]=BigInteger.ONE;
        for(i=2;i<101;i++){
            z[i]=z[i-1].multiply(BigInteger.valueof(4*i-2));
            z[i]=z[i].divide(BigInteger.valueOf(i+1));
        }
		while (cin.hasnext()){
			int a = cin.nextInt();
			System.out.println(z[a]);
		}
	}
}

