import java.util.*;

public class E {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int t = sc.nextInt();
		double res = a * t / 2.0;
		System.out.println(String.format("%.2f", res));
	}
}