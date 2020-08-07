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

string text, pat;
vector<int> prefix;

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

bool kmp() {
	for (int i = 0, j = -1; i < text.size(); i++) {
		while (j != -1 && pat[j + 1] != text[i])
			j = prefix[j];
		if (pat[j + 1] == text[i])
			j++;
		if (j == pat.size() - 1)
			return true;
	}
	return false;
}

int main() {
	NeedForSpeed;
	int t;
	cin >> t;
	while (t--) {
		cin >> text;
		int n;
		cin >> n;
		while (n--) {
			cin >> pat;
			prefix.clear();
			build();
			if (kmp())
				cout << 'y';
			else cout << 'n';
			cout << endl;
		}
	}
	return 0;
}
		