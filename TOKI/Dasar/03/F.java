import java.util.*;

public class F {
	private static int[][] matrix = new int[3][3];

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				matrix[i][j] = sc.nextInt();
			}
		}
		printMatrix();
	}

	public static void printMatrix() {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (j != 0) System.out.print(" ");
				System.out.print(matrix[j][i]);
			}
			System.out.println("");
		}
	}
}