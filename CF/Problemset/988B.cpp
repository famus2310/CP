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

vector<string> v;
int n;

bool comp(string s1, string s2) {
	return s1.size() < s2.size();
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		v.pb(s);
	}
	sort(v.begin(), v.end(), comp);
	bool flag = 1;
	for (int i = 1; i < n && flag; i++) {
		if (v[i].find(v[i - 1]) == string::npos) flag = 0;
	}
	if (!flag) puts("NO");
	else {
		puts("YES");
		for (int i = 0; i < n; i++) cout << v[i] << endl;
	}
	return 0;
}
