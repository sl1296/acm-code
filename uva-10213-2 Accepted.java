
import java.util.Scanner;
import java.math.BigInteger;

class Main
{
	public static void main(String[] args)
	{
		Scanner cin = new Scanner(System.in);
		int n;

		n = cin.nextInt();
		while (n-- > 0) {
			BigInteger a = cin.nextBigInteger();

			BigInteger b = a.multiply(a);
			BigInteger c = b.multiply(a);
			BigInteger d = c.multiply(a);

			BigInteger tmp1 = c.multiply(BigInteger.valueOf(6));
			BigInteger tmp2 = b.multiply(BigInteger.valueOf(23));
			BigInteger tmp3 = a.multiply(BigInteger.valueOf(18));

			BigInteger ans = d.subtract(tmp1).add(tmp2).subtract(tmp3).divide(BigInteger.valueOf(24)).add(BigInteger.valueOf(1));

			System.out.println(ans.toString());
		}
	}
}

