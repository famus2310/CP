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

unordered_map<int, int> umap;
string s;
int x;

int main() {
	int n;
	int cnthetero = 0;
	int cnthomo = 0;
	bool hetero = 0, homo = 0;
	scanf("%d", &n);
	while (n--) {
		cin >> s;
		scanf("%d", &x);
		if (s[0] == 'i') {
			if (umap[x] == 0) cnthetero++;
			if (umap[x] == 1) cnthomo++;
			umap[x]++;
		} else if (umap[x] > 0){
			if (umap[x] == 2) cnthomo--;
			umap[x]--;
			if (umap[x] == 0) cnthetero--;
		}
		if (cnthomo > 0) homo = 1;
		else homo = 0;
		if (cnthetero > 1) hetero = 1;
		else hetero = 0;
		if (hetero && homo) puts("both");
		else if (homo) puts("homo");
		else if (hetero) puts("hetero");
		else puts("neither");
	}
	return 0;
}
		