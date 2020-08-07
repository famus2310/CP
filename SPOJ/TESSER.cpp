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

const int N = 2e5 + 5;

string text, pat;
ll prefix[N];

void solve() {
	prefix[0] = -1;
	string now = pat + "$" + text;
	for (int i = 1, j = -1; i < now.size(); i++) {
		while (j != -1 && now[j + 1] != now[i]) 
			j = prefix[j];
		if (now[j + 1] == now[i])
			j++;
		prefix[i] = j;
		if (j == pat.size() - 1) {
			cout << "YES" << endl;
			return;
		}
	}
	cout << "NO" << endl;
}

int main() {
	NeedForSpeed;
	ll t;
	cin >> t;
	while (t--) {
		text.clear();
		ll n;
		cin >> n;
		ll a;
		cin >> a;
		for (int i = 0; i < n - 1; i++) {
			ll x;
			cin >> x;
			if (x > a)
				text.pb('G');
			else if (x < a)
				text.pb('L');
			else text.pb('E');
			a = x;
		}
		cin >> pat;
		solve();
	}
	return 0;
}
		