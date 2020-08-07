#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define debug(x) cout << x << endl
#define fastio ios_base::sync_with_stdio(0), cin.tie(0)
#define PI acos(-1)
#define all(c) c.begin(), c.end()
const int MOD = 1e9 + 7;
const int INF = 1e9;
const LL INF64 = 1e18;

const int N = 1e5 + 5;

string arr[15];
map<string, int> umap;
int net[15];

int main() {
	int n;
	bool fi = 1;
	while (scanf("%d", &n) == 1) {
		if (!fi) cout << endl;
		fi = 0;
		umap.clear();
		memset(net, 0, sizeof net);
		memset(arr, 0, sizeof arr);
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			umap[s] = i;
			arr[i] = s;
		}
		for (int i = 0; i < n; i++) {
			string a, b;
			int val, m;
			cin >> a >> val >> m;
			if (m == 0) continue;
			int rem = val % m;
			net[umap[a]] += rem;
			net[umap[a]] -= val;
			for (int j = 0; j < m; j++) {
				cin >> b;
				net[umap[b]] += val / m;
			}
		}
		for (int i = 0; i < n; i++) {
			cout << arr[i] << " " << net[umap[arr[i]]] << endl;
		}
	}
	return 0;
}
		