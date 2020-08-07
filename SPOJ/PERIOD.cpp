#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
const ll INF64 = 1e18;

const int N = 1e6 + 5;

string s;
ll prefix[2 * N];
vector<pair<ll, ll> > ans;

void solve() {
	prefix[0] = -1;
	for (int i = 1, j = -1; i < s.size(); i++) {
		while (j != -1 && s[j + 1] != s[i])
			j = prefix[j];
		if (s[j + 1] == s[i])
			j++;
		prefix[i] = j; 
		// cout << i + 1 << " " << j + 1 << endl;
		ll rem = i - j;
		if (rem > 0 && (i + 1) % rem == 0 && (i + 1) / rem > 1)
			cout << i + 1 << " " << (i + 1) / rem << endl;
	}
	cout << endl;
}

int main() {
	NeedForSpeed;
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		ll n;
		cin >> n;
		cin >> s;
		cout << "Test case #" << tc << endl;
		solve();
	}
	return 0;
}
		