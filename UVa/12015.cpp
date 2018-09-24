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

struct node{
	int ref;
	string web;
};

node arr[15];

int main() {
	int t;
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		string s;
		int val;
		int mx = -1;
		for (int i = 0; i < 10; i++) {
			cin >> s >> val;
			arr[i].ref = val;
			arr[i].web = s;
			mx = max(mx, val);
		}
		printf("Case #%d:\n", tc);
		for (int i = 0; i < 10; i++) {
			if (arr[i].ref == mx) 
				cout << arr[i].web << endl;
		}
	}
	return 0;
}
		