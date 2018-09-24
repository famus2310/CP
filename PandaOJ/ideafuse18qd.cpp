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

map<string, int> mp;
string a, b;

bool comp(pair<int, string> s1, pair<int, string> s2) {
	if (s1.first != s2.first)
		return s1.first > s2.first;
	return s1.second < s2.second;
}

int main() {
	for (int i = 0; i < 8; i++) {
		cin >> a; 
	}
	for (int i = 0; i < 28; i++) {
		int x, y;
		char c;
		cin >> a >> x >> c >> y >> b;
		if (x > y)
			mp[a]++;
		else
			mp[b]++;
	}
	vector<pair<int, string> > ans;
	for (auto it : mp)
		ans.pb({it.second, it.first});
	sort(all(ans), comp);
	for (auto it : ans) 
		cout << it.second << " " << it.first << endl;
	return 0;
}
		