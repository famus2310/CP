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
const double EPS = 1e-7;
const int N = 1e5 + 5;
const double g = 10.0;


struct pole {
	ll x, h, idx;
};

ll n;
vector<pole> v;
vector<pole> vfront;
vector<pole> vback;

double degToRad(double theta) {
	return theta * PI / 180.0;
}

double solY(ll v0, ll theta, ll x) {
	double v0x = (double)v0 * cos(degToRad(theta));
	double v0y = (double)v0 * sin(degToRad(theta));
	double t = (double)x / v0x;
	return v0y * t - 0.5 * g * t * t;
}

bool solveFront(ll v0, ll theta) {
	ll lo = 0;
	ll hi = vfront.size() - 1;
	while (lo < hi) {
		ll mid = (lo + hi) / 2;
		if (solY(v0, theta, vfront[mid].x) - vfront[mid].h < EPS) {
			hi = mid;
		} else 
			lo = mid + 1;
	}
	if (lo > hi)
		swap(hi, lo);
	for (; lo <= hi; lo++) {
		if (solY(v0, theta, vfront[lo].x) - vfront[lo].h < EPS) {
			return lo;
		} 
	}
	return -1;
}

bool solveBack(ll v0, ll theta) {
	double v0x = (double)v0 * cos(degToRad(theta));
	double v0y = (double)v0 * sin(degToRad(theta));
	double lastPoint = v0x * v0y * 2.0 * g;

	ll lo = 0;
	ll hi = vback().size() - 1;
	while (lo < hi) {
		ll mid = (lo + hi) / 2;
		if (vback[mid].x - lasPoint > EPS)
			lo = mid + 1;
		else if (solY(v0, theta, vfront[mid].x) - vfront[mid].h < EPS) {
			lo = mid;
		} else 
			hi = mid + 1;
	}
	if (lo > hi)
		swap(hi, lo);
	for (; lo <= hi; lo++) {
		if (solY(v0, theta, vfront[lo].x) - vfront[lo].h < EPS) {
			return lo;
		} 
	}
	return -1;
}

int main() {
	NeedForSpeed;
	cin >> n;
	ll lasth = 0;
	for (int i = 0; i < n; i++) {
		ll x, h;
		cin >> x >> h;
		v.pb({xi, hi, i + 1});
	}
	for (int i = 0; i < n; i++) {
		if (v[i].h < lasth)
			continue;
		lasth = h;
		vfront.pb(v[i]);
	}
	lasth = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (v[i].h < lasth)
			continue;
		lasth = h;
		vback.pb(v[i]);
	}

	return 0;
}
		