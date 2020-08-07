#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
#define pb push_back
#define debug(x) cout << x << endl
#define fastio ios_base::sync_with_stdio(0), cin.tie(0)
#define PI acos(-1)
#define all(c) c.begin(), c.end()
#define SET(x, y) memset((x), y, sizeof(x))
const int MOD = 1e9 + 7;
const int INF = 1e9;
const LL INF64 = 1e18;

const int N = 1e5 + 5;

struct PT {
	int x, y;
};

PT arr[2005];

int readint () {
	bool minus = false;
	int result = 0;
	char ch;
	ch = _getchar_nolock();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = _getchar_nolock();
	}
	if (ch == '-') minus = true;
	else result = ch-'0';
	while (true) {
		ch = _getchar_nolock();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}


inline int euclidDist(const PT& x1, const PT& x2) {
	int dx = x1.x - x2.x;
	int dy = x1.y - x2.y;
	return dx * dx + dy * dy;
}

int main() {
	int n = readint(), q = readint();
	for (int i = 0; i < n; i++) {
		int a = readint(), b = readint();
		arr[i] = {a, b};
	}
	while (q--) {
		int x = readint(), y = readint();
		PT cur = {x, y};
		int mn = INF;
		int cnt = 0;
		int region[5];
		for (int i = 0; i < n; i++) {
			int now = euclidDist(arr[i], cur);
			if (now < mn) {
				cnt = 1;
				mn = now;
				region[1] = i + 1;
			} else if (now == mn && cnt < 3) {
				cnt++;
				region[cnt] = i + 1;
			}
		}
		if (cnt == 1) 
			printf("REGION %d\n", region[1]);
		else if (cnt == 2)
			printf("LINE %d %d\n", region[1], region[2]);
		else if (cnt > 2)
			puts("POINT");
		else puts("NONE");
	}
	return 0;
}
		