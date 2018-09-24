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

struct node {
	int cnt;
	string key;
	bool operator< (const node& other) const {
		if (other.cnt != cnt) return cnt > other.cnt;
		return key < other.key;
	}
};

map<string, int> cnt;
map<string, string> project;
vector<node> v;

int main() {
	int n = 0;
	string last_project, s;
	while (getline(cin, s)) {
		// cout << cnt["ROBOTS"] << endl;
		if (s == "0") break;
		if (s == "1") {
			v.clear();
			for (auto it : cnt) {
				v.push_back({it.second, it.first});
			}
			sort(all(v));
			for (int i = 0; i < v.size(); i++) {
				if (v[i].key == "-1") continue; 
				cout << v[i].key << " " << v[i].cnt << endl;
			}
			project.clear();
			cnt.clear();
			continue;
		}
		if (islower(s[0]) && project.find(s) == project.end()) {
			cnt[last_project]++;
			project[s] = last_project;
			continue;
		}
		if (islower(s[0]) && project[s] != last_project) {
			cnt[project[s]]--;
			project[s] = "-1";
			continue;
		}
		if (islower(s[0]) && project[s] == last_project) continue;
		if (isupper(s[0])) {
			last_project = s;
			cnt[s] = 0;
			continue;
		}
	}
	return 0;
}
		