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

const int N = 1e5 + 5;

bool checkPal(string& s) {
	for (int i = 0; i < s.size() / 2; i++) {
		if (s[i] != s[s.size() - i - 1])
			return false;
	}
	return true;
}

bool isPal6(ll x) {
	string s;
	while (x) {
		s.pb(char(x % 6 + '0'));
		x /= 6;
	}
	return checkPal(s);
}

bool isPal4(ll x) {
	string s;
	while (x) {
		s.pb(char(x % 4 + '0'));
		x /= 4;
	}
	return checkPal(s);
}

int main() {
	NeedForSpeed;
	ll sum = 0ll;
	for (ll i = 1; i < 10000000; i++)
		if (isPal4(i) && isPal6(i))
			sum += i;
	cout << sum << endl;
	return 0;
}
		