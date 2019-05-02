#include <bits/stdc++.h>
using namespace std;
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
const int INF = 1e9 + 5;
const LL INF64 = 1e18;

const int N = 1e5 + 5;

LL LOG[2 * N];
LL sparse[2 * N][20];
LL arr[2 * N];
LL pos[2 * N];

void build() {
	LOG[1] = 0;
	for (int i = 1; i < 2 * N; i++) {
		if (i > 1)
			LOG[i] = LOG[i / 2] + 1;
		sparse[i][0] = i;
	}
	for (int j = 1; j < 20; j++) {
		for (int i = 1; i < 2 * N && i + (1LL << (j - 1)) < 2 * N; i++) {
			if (arr[sparse[i][j - 1]] > arr[sparse[i + (1LL << (j - 1))][j - 1]])
				sparse[i][j] = sparse[i][j - 1];
			else sparse[i][j] = sparse[i + (1LL << (j - 1))][j - 1];
		}
		// cout << j << endl;
	}
	// debug("yes");
}

LL query(LL a, LL b) {
	LL now = LOG[b - a + 1];
	if (arr[sparse[a][now]] > arr[sparse[b - (1LL << now) + 1][now]]) {
		return sparse[a][now];
	} 
	return sparse[b - (1LL << now) + 1][now];
}

LL solve(LL a, LL b) {
	if (b <= a)
		return 0;
	LL ret = 0LL;
	LL now = query(a, b);
	if (b - now < now - a) {
		for (int i = now + 1; i <= b; i++) {
			LL cur = arr[now] - arr[i];
			if (a <= pos[cur] && pos[cur] < now)
				ret++;
		}
	} else {
		for (int i = a; i < now; i++) {
			LL cur = arr[now] - arr[i];
			if (now + 1 <= pos[cur] && pos[cur] <= b)
				ret++;
		}
	}
	// cout << now << " " << ret << endl;
	ret = ret + solve(a, now - 1);
	ret = ret + solve(now + 1, b);
	return ret;
}

int main() {
	SET(arr, 0);
	fastio;
	LL n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		pos[arr[i]] = i;
	}
	build();
	// debug(1);
	cout << solve(1, n);
	return 0;
}
		