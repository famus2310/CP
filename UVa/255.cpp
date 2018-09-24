#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define debug(x) cout << x << endl
#define fastio ios_base::sync_with_stdio(0), cin.tie(0)
#define PI acos(-1)
#define all(c) c.begin(), c.end()
const int MOD = 1e9 + 7;
const int INF = 1e9;
const LL INF64 = 1e18;

const int N = 1e5 + 5;

int dx[] = {-8, 8, -1, 1};

bool isBound(int a) {
	return a >= 0 && a < 64;
}

bool move(int a, int b, int c) {
	if (c == b || ((c % 8 != b % 8) && (c / 8 != b / 8))) return true;
	if (a % 8 == b % 8 && b % 8 == c % 8) {
		if (a > b && c >= a) return true;
		if (a < b && c <= a) return true;
	}
	if (a / 8 == b / 8 && b / 8 == c / 8) {
		if (a > b && c >= a) return true;
		if (a < b && c <= a) return true;
	}
	return false;
}

int main() {
	int a, b, c;
	while (scanf("%d %d %d", &a, &b, &c) == 3) {
		if (a == b || !isBound(a) || !isBound(b))
			puts("Illegal state");
		else if (move(a, b, c))
			puts("Illegal move");
		else {
			bool flag = 1;
			bool isContinue = 0;
			for (int i = 0; i < 4; i++) {
				if (!isBound(a + dx[i])) continue;
				if (dx[i] == -1 || dx[i] == 1) {
					if (a / 8 != (a + dx[i]) / 8) continue;
 				}
				if (c == a + dx[i]) {
					flag = 0;
				}
				int now = a + dx[i];
				if ((now % 8 != c % 8) && (now / 8 != c / 8))
					isContinue = 1;
			}
			if (!flag)
				puts("Move not allowed");
			else if (isContinue)
				puts("Continue");
			else 
				puts("Stop");
		}
	}
	return 0;
}
		