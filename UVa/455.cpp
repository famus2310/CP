#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
#define pb push_back
#define debug(x) cout << x << endl
#define NeedForSpeed ios_base::sync_with_stdio(0), cin.tie(0)
#define PI acos(-1)
#define all(c) c.begin(), c.end()
#define SET(x, y) memset((x), y, sizeof(x))
const int MOD = 1e9 + 7;
const int INF = 1e9;
const LL INF64 = 1e18;

const int N = 1e5 + 5;

string pat, text;
vector<int> prefix;

void build() {
	prefix.pb(-1);
	for (int i = 1, j = -1; i < pat.size(); i++) {
		while (j != -1 && pat[j + 1] != pat[i])
			j = prefix[j];
		if (pat[j + 1] == pat[i])
			j++;
		prefix.pb(j);
	}
	int curlen = pat.size() - prefix.back() - 1;
	if (pat.size() % curlen == 0)
		cout << curlen << endl;
	else cout << 1 << endl;
}

int main() {
	NeedForSpeed;	
	int t;
	cin >> t;
	while (t--) {
		prefix.clear();
		cin >> pat;
		build();
	}
	return 0;
}
		