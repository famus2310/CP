import java.util.*;
import java.lang.*;

class IBIGAME{
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		long t = sc.nextLong();
		for (int tc = 0; tc < t; tc++) {
			long a = sc.nextLong();
			long b = sc.nextLong();
			long c = Math.abs(a - b);
			if (c % 8 == 7 || c % 8 == 0 || c % 8 == 1) {
				System.out.println("Farael");
			} else {
				System.out.println("Ziya");
			}
		}
	}
}