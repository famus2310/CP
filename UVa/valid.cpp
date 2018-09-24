class BinaryCalculator {
public:
	int minimumSteps(int a, int b) {
		if (a == b) return 0;
		else if (b > a) {
			int diff = b - a;
			int move = diff / 3;
			diff -= (move * 3);
			if (diff > 0) move += 2 * diff;
			return move;
		} else {
			int diff = a - b;
			int move = (diff) / 2;
			diff -= (move * 2);
			if (diff != 0) move += 3 * diff;
			return move;
		}
	}
}