
/*
0_0_17804541_23791\Main.java:10: ����: �Ҳ�������
            n=cin.nestInt();
                 ^
  ����:   ���� nestInt()
  λ��: ����ΪScanner�ı��� cin
0_0_17804541_23791\Main.java:11: ����: �����ݵ�����: BigInteger�޷�ת��Ϊint
            ans=BigInteger.ONE;
                          ^
0_0_17804541_23791\Main.java:12: ����: �����ݵ�����: BigInteger�޷�ת��Ϊint
            tmp=BigInteger.ONE;
                          ^
0_0_17804541_23791\Main.java:15: ����: �޷�ȡ������int
                tmp=tmp.multiply(BigInteger.valueOf(n-2*i)).multiply(BigInteger.valueOf(n-2*i-1)).divide(BigInteger.valueOf(i+1)).divide(BigInteger.valueOf(i+2));
                       ^
0_0_17804541_23791\Main.java:16: ����: �޷�ȡ������int
                ans=ans.add(tmp);
                       ^
0_0_17804541_23791\Main.java:18: ����: �޷�ȡ������int
            ans=ans.mod(BigInteger.TEN.pow(100));
                   ^
6 ������
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


