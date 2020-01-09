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

double degToRad(double x) {
	return x * PI / 180.0;
}

double calculateNeed(double x, double y, double theta) {
	return (double)(5.0 * x * x) / (double)((x * tan(degToRad(theta)) - y) * cos(degToRad(theta)) * cos(degToRad(theta)));
}

struct projectile {
	int x, y;
	double vneedhi[90];
	double vneedlo[90];
	void init() {
		for (int i = 1; i < 90; i++) {
			vneedhi[i] = calculateNeed(x, y, i);
			vneedlo[i] = calculateNeed(x, 0, i);
		}
	}
};

vector<pair<double, ll> > vhi[90];
vector<pair<double, ll> > vlo[90];

ll solveLo(ll angle, ll speed) {
	ll lo = 0;
	ll hi = vlo[angle].size() - 1;
	while (hi - lo > 1) {
		ll mid = (lo + hi) / 2;
		if (vlo[angle][mid].first <= speed) {
			lo = mid;
		} else 
			hi = mid;
	}
	cout << lo << " " << hi << endl;
	if (lo > hi)
		swap(lo, hi);
	for (int i = hi; i >= lo; i--) {
		if (vlo[angle][i].first <= speed)
			return i;
	}
	return 0;
}

double solveHi(ll angle, ll speed) {
	ll lo = 0;
	ll hi = solveLo(angle, speed);
	debug(hi);
	while (lo < hi) {
		ll mid = (lo + hi) / 2;
		if (vhi[angle][mid].first < speed) {
			lo = mid + 1;
		} else 
			hi = mid;
	}
	cout << lo << " " << hi << endl;
	return vhi[angle][lo].second;
}

ll n;
projectile arr[100005];

int main() {
	NeedForSpeed;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].x >> arr[i].y;
		arr[i].init();
		if (i == 0) {
			for (int j = 1; j < 90; j++) {
				vhi[j].pb({arr[i].vneedhi[j], i + 1});
				vlo[j].pb({arr[i].vneedlo[j], i + 1});
			}
		} else {
			for (int j = 1; j < 90; j++) {
				if (arr[i].vneedhi[j] < vhi[j].back().first)
					continue;
				vhi[j].pb({arr[i].vneedhi[j], i + 1});
				vlo[j].pb({arr[i].vneedlo[j], i + 1});	
			}
		}
	}
	int q;
	cin >> q;
	cout << arr[1].vneedhi[50] << endl;
	cout << arr[1].vneedlo[50] << endl;
	for (auto it : vlo[50])
		cout << it.first << endl;
	cout << endl;
	for (auto it : vhi[50])
		cout << it.first << endl;
	while (q--) {
		ll a, s;
		cin >> a >> s;
		s *= s;
		cout << solveHi(a, s) << endl;
	}
	return 0;
}
