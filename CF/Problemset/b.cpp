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

int main() {
	string s;
	cin >> s;
	int row = 1;
	while (row <= 5) {
		if (ceil((double)s.size() / (double)row) <= 20)
			break;
		row++;
	}
	int ast = 0;
	while ((s.size() + ast) % row != 0) {
		ast++;
	};
	int col = (s.size() + ast) / row;
	string ans[7];
	int i = 0;
	while (ast) {
		ans[i].pb('*');
		i++;
		i %= row;
		ast--;
	}
	int k = 0;
	for (int i = 0; i < s.size(); i++) {
		if (ans[k].size() == col)
			k++;
		ans[k].pb(s[i]);
	}
	cout << row << " " << col << endl;
	for (int i = 0; i < row; i++)
		cout << ans[i] << endl;
	return 0;
}
		