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
const int INF = 1e9;
const LL INF64 = 1e18;

const int N = 1e5 + 5;

vector<LL> ans;

int main() {
	int k;
	cin >> k;
	string a, b;
	cin >> a >> b;
	int nowa = 0;
	int nowb = 0;
	int t = 0;
	int sza = a.size();
	int szb = b.size();
	int cnt = 0;
	while (cnt < k) {
		if (a[nowa] != b[nowb]) {
			cout << t << endl;
			cnt++;
		}
		t++;
		nowa = (nowa + 1) % sza;
		nowb = (nowb + 1) % szb;
		if (t > 2000 && cnt == 0) break;
	}
	if (cnt == 0)
		for (int i = 0; i < k; i++)
			cout << -1 << endl;
	return 0;
}
		