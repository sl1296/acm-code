
/*
0_0_17788159_10390\Main.java:12: ����: �����ݵ�����: int�޷�ת��ΪLong
        for(i=2;i<101;i++){
              ^
0_0_17788159_10390\Main.java:13: ����: �����ݵ�����: Long�޷�ת��Ϊint
            z[i]=z[i-1].multiply(BigInteger.valueof(4*i-2));
              ^
0_0_17788159_10390\Main.java:13: ����: �Ҳ�������
            z[i]=z[i-1].multiply(BigInteger.valueof(4*i-2));
                                           ^
  ����:   ���� valueof(long)
  λ��: �� BigInteger
0_0_17788159_10390\Main.java:13: ����: �����ݵ�����: ��longת����int���ܻ�����ʧ
            z[i]=z[i-1].multiply(BigInteger.valueof(4*i-2));
                    ^
0_0_17788159_10390\Main.java:14: ����: �����ݵ�����: Long�޷�ת��Ϊint
            z[i]=z[i].divide(BigInteger.valueOf(i+1));
              ^
0_0_17788159_10390\Main.java:14: ����: �����ݵ�����: Long�޷�ת��Ϊint
            z[i]=z[i].divide(BigInteger.valueOf(i+1));
                   ^
0_0_17788159_10390\Main.java:16: ����: �Ҳ�������
		while (cin.hasnext()){
		          ^
  ����:   ���� hasnext()
  λ��: ����ΪScanner�ı��� cin
7 ������
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

