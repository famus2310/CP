import java.util.*;

public class beavergnaw {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		while (true) {
			double d = sc.nextDouble();
			double v = sc.nextDouble();
			if (d == 0 && v == 0) break;
			double res = solve(d, v);
			System.out.println(String.format("%.6f", res));
		}
	}
	public static double solve(double d, double v) {
		return Math.pow(d*d*d - 4.0*(v*v*v)/Math.PI, 1.0/3.0);
	}
}