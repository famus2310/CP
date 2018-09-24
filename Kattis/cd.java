import java.util.*;

public class cd {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long n, m;
		while (true) {
			long sum = 0;
			n = sc.nextLong(); m = sc.nextLong();
			if (n == 0 && m == 0) break;
			Hashtable<Long, Boolean> umap = new Hashtable<Long, Boolean>();
			for (long i = 0; i < n; i++) {
				long tmp = sc.nextLong();
				umap.put(tmp, true);
			}
			for (long i = 0; i < m; i++) {
				long tmp = sc.nextLong();
				if (umap.get(tmp) != null) sum++;
			}
			System.out.println(sum);
		}
	}
}