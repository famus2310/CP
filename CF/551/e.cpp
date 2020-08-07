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

list<int>::iterator it[2 * n];
list<int> ls;
vector<int> ori;
vector<int> container;
int team[2 * N];
bool deleted[2 * N];
int n, k;

int main() {
	fastio;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		ori.pb(a);
		ls.pb(a);
		auto now = ls.end();
		now--;
		it[a] = now;
		s.insert(a);
		container.pb(a);
	}
	sort(all(container), greater<int>());
	int curteam = 1;
	for (int i = container) {
		if (deleted[i])
			continue;
		auto now = it[i];
		auto tmp = now;
		tmp--;
		int dec = k;
		while (tmp != ls.begin() && dec) {
			deleted[*tmp] = 1;
			team[*tmp] = curteam;
			ls.erase(tmp);
			dec--;
			tmp--;
		}
		if (dec) {
			deleted[*tmp] = 1;
			team[*tmp] = curteam;
			ls.erase(tmp);
			dec--;
		}
		tmp = now;
		tmp++;
		dec = k;
		while (tmp != ls.end() && dec) {
			deleted[*tmp] = 1;
			team[*tmp] = curteam;
			ls.erase(tmp);
			dec--;
			tmp++;
		}
		deleted[*now] = 1;
		ls.erase(now);
		curteam = (curteam % 2) + 1;
	}
	return 0;
}
		