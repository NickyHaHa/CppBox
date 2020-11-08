import java.math.BigInteger;
import java.util.Scanner;
public class Main{

	public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in);
		int num;
		BigInteger ans = new BigInteger("0");
		
		BigInteger[] n = new BigInteger[ 2001 ];
		n[0] = BigInteger.valueOf(1);
		n[1] = BigInteger.valueOf(3);
		
		for(int i = 2; i <= 2000; i++)
		{
			n[i] = n[ i-1 ].multiply(BigInteger.valueOf(3)).subtract(n[ i-2 );
		}
		
		while((scanner.hasNextInt())) {
			num = scanner.nextInt();
			if(num == 0)break;
			System.out.println(n[ num-1 ]);
		}
	}
}