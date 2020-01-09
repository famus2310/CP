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

vector<ll> prime;
bool notPrime[N];

void sieve() {
	for (ll i = 2; i < N; i++) {
		if (!notPrime[i]) {
			prime.pb(i);
			for (ll j = i * i; j < N; j += i)
				notPrime[j] = 1;
		}
	}
}

ll sumVector(ll lo, ll hi, vector<ll>& v) {
	ll ans = 0;
	for (int i = lo; i <= hi; i++)
		ans += v[i];
	return ans;
}

ll countLongest(vector<ll>& v) {
	ll cur = 0;
	ll ans = 0;
	for (int i = 0; i < v.size(); i++) {
		if (!v[i])
			cur++;
		else cur = 0;
		ans = max(ans, cur);
	}
	return ans;
}

vector<ll> paintVector(ll lo, ll hi, vector<ll>& v) {
	vector<ll> ret = v;
	for (int i = lo; i <= hi; i++)
		ret[i] = 1;
	return ret;
}

ll solve(vector<ll> p, ll turn) {
	ll sum = sumVector(0, p.size() - 1, p);
	if (sum == p.size())
		return (turn + 1) % 2;
	ll longest = countLongest(p);
	longest = longest / 2 + longest % 2;
	ll solved = 0;
	ll ans = -1;
	for (int i = prime.size() - 1; i >= 0; i--) {
		if (prime[i] > longest)
			continue;
		solved = 1;
		for (int j = 0; j + prime[i] - 1 < p.size(); j++) {
			if (sumVector(j, j + prime[i] - 1, p) == 0) {
				vector<ll> now = paintVector(j, j + prime[i] - 1, p);
				if (ans == -1)
					ans = solve(now, (turn + 1) % 2);
				else if (turn == 0)
					ans = min(ans, solve(now, (turn + 1) % 2));
				else ans = max(ans, solve(now, (turn + 1) % 2));
			}
		}
	}
	if (!solved) {
		for (int j = 0; j < p.size(); j++) {
			if (p[j] == 0) {
				vector<ll> now = paintVector(j, j, p);
				if (ans == -1)
					ans = solve(now, (turn + 1) % 2);
				else if (turn == 0)
					ans = min(ans, solve(now, (turn + 1) % 2));
				else ans = max(ans, solve(now, (turn + 1) % 2));
			}
		}
	}
	return ans;
}

int main() {
	sieve();
	NeedForSpeed;
	ll n;
	for (n = 1; n <= 100000; n++) {
		vector<ll> cur;
		for (int i = 0; i < n; i++)
			cur.pb(0);
		cout << n << " : " <<  solve(cur, 0) << endl;
	}
	cout << "yes";
	return 0;
}
		