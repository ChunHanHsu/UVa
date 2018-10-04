import java.math.BigInteger;
import java.util.*;

public class UVA_10069 {
	public static BigInteger[][] table = new BigInteger[11000][11000];
	private static Scanner sc;

	public static void main(String[] args) {
		int T;
		sc = new Scanner(System.in);
		T = sc.nextInt();
		sc.nextLine();
		while (T >= 0) {
			T = T - 1;
			char[] X, Z;
			X = sc.nextLine().toCharArray();
			Z = sc.nextLine().toCharArray();

			for (int i = 0; i <= Z.length; i++)
				table[i][0] = new BigInteger("0");
			for (int i = 0; i <= X.length; i++)
				table[0][i] = new BigInteger("0");
			int check = 0, counter;
			BigInteger temp = new BigInteger("0");
			for (int i = 1; i <= Z.length; i++) {
				counter = 0;
				temp=BigInteger.ZERO;
				if (i - 2 >= 0 && Z[i - 1] == Z[i - 2])
					check = check + 1;
				else
					check = 1;

				for (int j = 1; j <= X.length; j++) {
					if (i == 1) {
						if (Z[i - 1] == X[j - 1])
							table[i][j] = table[i][j - 1].add(BigInteger.ONE);
						else
							table[i][j] = table[i][j - 1];
					} else if (check == 1) {
						if (Z[i - 1] == X[j - 1])
							table[i][j] = table[i][j - 1].add(table[i - 1][j]);
						else
							table[i][j] = table[i][j - 1];
					} else {
						if (Z[i - 1] == X[j - 1])
							counter++;
						if (Z[i - 1] != X[j - 1] && temp.compareTo(BigInteger.ZERO) == 0)
							counter = 0;
						if (Z[i - 1] == X[j - 1] && counter == check - 1)
							temp = table[i - 1][j];
						if (counter < check)
							table[i][j] = BigInteger.ZERO;
						else if (Z[i - 1] == X[j - 1]) {
							if (counter == check)
								table[i][j] = temp;
							else {
								table[i][j] = table[i][j - 1].multiply(new BigInteger(Integer.toString(counter)));
								table[i][j] = table[i][j].divide(new BigInteger(Integer.toString(counter-check)));
							}
						}
						else table[i][j]=table[i][j-1];
					}
				}
			}
			System.out.println(table[Z.length][X.length]);
		}
	}
}
