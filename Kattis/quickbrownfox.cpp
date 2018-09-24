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

bool arr[256];

int main() {
	int n;
	cin >> n;
	cin.ignore();
	while (n--) {
		memset(arr, 0, sizeof arr);
		string s;
		getline(cin, s);
		int cnt = 0;
		for (int i = 0; i < s.size(); i++) {
			s[i] = tolower(s[i]);
			arr[s[i]] = 1;
		}
		string ans;
		for (int i = 'a'; i <= 'z'; i++) {
			if (arr[i] == 1) continue;
			ans.pb((char)i);
		}
		if (ans.empty()) puts("pangram");
		else printf("missing "); cout << ans << endl;
	}
	return 0;
}
		