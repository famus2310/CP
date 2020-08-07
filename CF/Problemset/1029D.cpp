#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long LL;
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

const int N = 2e5 + 5;

map<LL , LL> umap[11];
LL arr[N];

LL readInt () {
	bool minus = false;
	LL result = 0;
	char ch;
	ch = getchar();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') minus = true;
	else result = ch-'0';
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}

LL findDegree(LL x) {
	LL ret = 0;
	while (x) {
		ret++;
		x /= 10;
	}
	return ret;
}

LL power[11];

void precompute() {
	power[0] = 1LL;
	for (int i = 1; i < 11; i++)
		power[i] = power[i - 1] * 10;
}

int main() {
	precompute();
	LL n, k;
	n = readInt();
	k = readInt();
	for (int i = 0; i < n; i++) {
		LL a;
		a = readInt();
		arr[i] = a;
		for (LL j = 1; j <= 10; j ++) {
			LL multiplier = power[j];
			LL now = arr[i] * multiplier;
			umap[j][now % k]++;
			// cout << j << " " << now % k << " ";
		}
		// cout << endl;
	}
	LL ret = 0LL;
	for (int i = 0; i < n; i++) {
		LL tmp = arr[i] % k;
		LL degree = log10(arr[i]) + 1;
		LL ans = 0;
		LL modul = ((arr[i] % k) * (power[degree] % k)) % k;
		if (modul == k - tmp || modul == 2 * k - tmp) ans--;
		if (modul == 0 && tmp == 0) ans--;
		// cout << umap[{degree, k - tmp}] << endl;
		// cout << tmp << " " << degree << endl;
		// debug(k - tmp);
		if (umap[degree].find((k - tmp) % k) != umap[degree].end())
			ans += umap[degree][(k - tmp) % k];
		ret += ans;
		// debug(ans);
	}
	printf("%llu\n", ret);
	return 0;
}
