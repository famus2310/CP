#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
#define pb push_back
#define debug(x) cout << x << endl
#define NeedForSpeed ios_base::sync_with_stdio(0), cin.tie(0)
#define PI acos(-1)
#define all(c) c.begin(), c.end()
#define SET(x, y) memset((x), y, sizeof(x))
const int MOD = 1e9 + 7;
const int INF = 1e9;
const LL INF64 = 1e18;

const int N = 1e5 + 5;

string pat, text;
vector<int> prefix;
vector<int> ans;
int m;

void build() {
	prefix.pb(-1);
	for (int i = 1, j = -1; i < pat.size(); i++) {
		while (j != -1 && pat[j + 1] != pat[i])
			j = prefix[j];
		if (pat[j + 1] == pat[i])
			j++;
		prefix.pb(j);
	}
}

void kmp() {
	for (int i = 1, j = -1; i < text.size(); i++) {
		while (j != -1 && pat[j + 1] != text[i])
			j = prefix[j];
		if (pat[j + 1] == text[i])
			j++;
		if (j == pat.size() - 1) {
			ans.pb(i - pat.size() + 1);
			j = prefix[j];
		}
	}
}

int main() {
	NeedForSpeed;
	while (cin >> m) {
		prefix.clear();
		ans.clear();
		cin.ignore();
		getline(cin, pat);
		getline(cin, text);
		build(); kmp();
		if (ans.empty())
			cout << endl;
		else {
			for (auto it : ans)
				cout << it << endl;
		}
	}
	return 0;
}
		