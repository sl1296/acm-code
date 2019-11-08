
/*
0_0_17816339_2077.cpp:1:1: error: 'import' does not name a type
 import java.util.*;
 ^
0_0_17816339_2077.cpp:2:1: error: 'import' does not name a type
 import java.math.*;
 ^
0_0_17816339_2077.cpp:5:9: error: expected ':' before 'static'
  public static void main(String[] args)
         ^
0_0_17816339_2077.cpp:5:26: error: 'String' has not been declared
  public static void main(String[] args)
                          ^
0_0_17816339_2077.cpp:5:35: error: expected ',' or '...' before 'args'
  public static void main(String[] args)
                                   ^
0_0_17816339_2077.cpp:23:1: error: expected ';' after class definition
 }
 ^
0_0_17816339_2077.cpp: In static member function 'static void Main::main(int*)':
0_0_17816339_2077.cpp:7:3: error: 'Scanner' was not declared in this scope
   Scanner cin = new Scanner(System.in);
   ^
0_0_17816339_2077.cpp:9:3: error: 'BigInteger' was not declared in this scope
   BigInteger ans,tmp;
   ^
0_0_17816339_2077.cpp:10:9: error: 'cin' was not declared in this scope
   while(cin.hasNext()){
         ^
0_0_17816339_2077.cpp:12:13: error: 'ans' was not declared in this scope
             ans=BigInteger.ONE;
             ^
0_0_17816339_2077.cpp:13:13: error: 'tmp' was not declared in this scope
             tmp=BigInteger.ONE;
             ^
0_0_17816339_2077.cpp:20:13: error: 'System' was not declared in this scope
             System.out.println(ans);
             ^
*/
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


