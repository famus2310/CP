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

string a, b;
int k;

int main() {
	cin >> a >> b >> k;
	int i = 0, j = 0;
	while (i <= a.size() && j < b.size() && a[i] == b[j]) {
		i++;
		j++;
	}
	int lena = a.size();
	int lenb = b.size();
	k -= (a.size() - i) + (b.size() - j);
	if (k < 0) {
		cout << "No" << endl;
	} else {
		cout << "Yes" << endl;
	}
	return 0;
}
		