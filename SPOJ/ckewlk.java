import java.util.*;
import java.lang.*;

class ckewlk{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long t = sc.nextLong();
		long m = sc.nextLong();
		long ans = 0;
		for (int i = 0; i < t; i++) {
			long n = sc.nextLong();
			long f = func(n, m);
			long c = solve(f + n % 1000000007 + m % 1000000007) % 1000000007;
			ans += c;
		}
		System.out.print("The President needs to pay ");
		System.out.print(ans);
		System.out.println(" dollar(s)");
	}
	static long modex(long a, long b) {
		long ret = 1;
		while (b > 0) {
			if (b % 2 == 1) ret = (ret * a) % 1000000007;
			b = b >> 1;
			a = (a * a) % 1000000007;
		}
		return ret;
	}
	static long func(long n, long m) {
		if (n == 1 || n == 2) return m % 1000000007;
		return (modex(2, n - 2) * (m % 1000000007)) % 1000000007;
	}

	static long solve(long n) {
		long ret = -1;
		while (n % 2 == 0) {
			ret = 2;
			n = n >> 1;
		}
		for (int i = 3; i * i <= n && n > 1; i += 2) {
			while (n % i == 0){
				ret = i;
				n /= i;
			}
		}
		if (n > 1) ret = Math.max(ret, n);
		return ret;
	}
}