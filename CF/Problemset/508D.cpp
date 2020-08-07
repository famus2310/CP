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

unordered_map<string, vector<string> > adjList;
unordered_map<string, int> inDeg, outDeg;
set<string> vert;

vector<string> hierholzer(string src) {
	stack<string> temp;
	vector<string> ret;
	temp.push(src);
	while (!temp.empty()) {
		string now = temp.top();
		if (adjList[now].empty()) {
			ret.push_back(now);
			temp.pop();
		} else {
			temp.push(adjList[now].back());
			adjList[now].pop_back();
		}
	}
	reverse(all(ret));
	return ret;
}


int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		string s1 = s.substr(0, 2), s2 = s.substr(1, 2);
		adjList[s1].push_back(s2);
		outDeg[s1]++;
		inDeg[s2]++;
		vert.insert(s1);
		vert.insert(s2);
	}

	bool isEuler = 1;
	int odd = 0;
	string src = "-1";
	for (string it : vert) {
		if (inDeg[it] - outDeg[it] == 1) odd++;
		else if (outDeg[it] - inDeg[it] == 1) {
			odd++;
			src = it;
		} else if (abs(inDeg[it] - outDeg[it]) > 1)
		isEuler = 0; 
	}
	if (odd > 2) isEuler = 0;
	if (!isEuler) puts("NO");
	else {
		if (src == "-1") {
			src = *vert.begin();
		}
		vector<string> ans = hierholzer(src);
		if (ans.size() != n + 1) {
			puts("NO");
			return 0;
		}
		string ret = src;
		puts("YES");
		for (int i = 1; i < ans.size(); i++) {
			ret += ans[i][1];
		}
		cout << ret << endl;
	}
	return 0;
}
		
