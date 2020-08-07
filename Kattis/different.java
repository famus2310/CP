import java.util.*;

public class different {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		while (sc.hasNext()) {
			long a = sc.nextLong();
			long b = sc.nextLong();
			System.out.println(solve(a, b));
		}
	}

	static long solve(long a, long b) {
		return Math.abs(a - b);
	}
}