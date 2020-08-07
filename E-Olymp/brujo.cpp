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

const int NMAX = 1e5 + 5;


int arr[105];
map<vector<int>, bool> mp;
map<int, bool> vis;

void sum() {
	for (int i = 1; i <= 100; i++) arr[i] = INF;
	arr[1] = 0;
	queue<vector<int> > q;
	vector<int> tmp = {1};
	q.push(tmp);
	while (!q.empty()) {
		vector<int> now = q.front(); q.pop();
		mp[now] = 1;	
		int len = now.size();
		arr[now[len - 1]] = min(len - 1, arr[now[now.size() - 1]]);
		vis[now[len - 1]] = 1;
		for (int i = 0; i < len; i++) {
			for (int j = i; j < len; j++) {
				int tempo = now[i] + now[j];
				if (vis[tempo]) continue;
				if (tempo > 100 || tempo < now[len - 1]) continue;
				bool flag = 0;
				for (int k = 0; k < len; k++) {
					if (now[k] == tempo) {
						flag = 1;
						break;
					}
				}
				if (flag) continue;
				vector<int> temp = now;
				temp.pb(now[i] + now[j]);
				if (mp[temp]) continue;
				q.push(temp);
				mp[temp] = 1;
			}
		}
	}
}

int main() {
	int n;
	debug("1");
	//cin >> n;
	freopen("output.out", "w", stdout);
	sum();
	for (int i = 1; i <= 100; i++) {
		int m;
		//cin >> m;
		cout << "arr[" << i << "] = " << arr[i] << ";" << endl;
	}
	return 0;
}
		