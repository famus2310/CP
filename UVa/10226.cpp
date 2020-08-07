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

map<string, int> species;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		string dummy;
		cin.ignore();
		species.clear();
		string s;
		double total = 0;
		while (getline(cin, s) && !s.empty()) {
			total = total + 1;
			species[s]++;
		}
		for (auto it : species) {
			cout << it.first << " " << setprecision(4) << fixed << (double)it.second / total * 100.0 << endl;
		}
	} 
	return 0;
}
		