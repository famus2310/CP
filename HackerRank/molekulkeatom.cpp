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

string s;
stack<pair<string, LL> > st, tmp;
map<string, LL> mp;

int main() {
	cin >> s;
	int i = 0;
	while (i < s.size()) {
		string now;
		if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
			string x;
			x.pb(s[i]);
			st.push({x, 0});
			i++;
			continue;
		}
		if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
			i++;
			LL num = 0;
			if (i < s.size() && '1' <= s[i] && s[i] <= '9') {
				num = s[i] - '0';
				i++;
				while (i < s.size() && '1' <= s[i] && s[i] <= '9') {
					num = num * 10 + s[i] - '0';
					i++;
				}
			}
			if (num == 0) num = 1;
			while (!tmp.empty()) {
				tmp.pop();
			}
			while (st.top().first != "(" && st.top().first != "{" && st.top().first != "[") {
				string x = st.top().first;
				LL y = st.top().second; st.pop();
				tmp.push({x, y * num});
			}
			st.pop();
			while (!tmp.empty()) {
				st.push(tmp.top()); tmp.pop();
			}
			continue;
		}
		if (i < s.size() && 'A' <= s[i] && s[i] <= 'Z') {
			now.pb(s[i]);
			i++;
			while (i < s.size() && 'a' <= s[i] && s[i] <= 'z') {
				now.pb(s[i]);
				i++;
			}
		}
		LL num = 0;
		if (i < s.size() && '1' <= s[i] && s[i] <= '9') {
			num = s[i] - '0';
			i++;
			while (i < s.size() && '1' <= s[i] && s[i] <= '9') {
				num = num * 10 + s[i] - '0';
				i++;
			}
		}
		if (num == 0) num = 1;
		st.push({now, num});
	}
	while (!st.empty()) {
		string now = st.top().first;
		LL num = st.top().second; st.pop();
		mp[now] += num;
	}
	for (auto it = mp.begin(); it != mp.end(); it++) {
		cout << it->first << " : " << it->second << endl;
	}
	return 0;
}
		