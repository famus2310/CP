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

const int N = 1e6 + 5;


int prefix[N];
string s;
vector<int> cand;

int main() {
	SET(prefix, 0);
	int n;
	scanf("%d", &n);
	cin >> s;
	int now = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '(')
			now++;
		else now--;
		prefix[i] = now;
		if (now < 0) {
			cand.pb(i);
		}
		if (now < 1) {
			puts("0");
			return 0;
		}
	}
	if (prefix[n - 1] == 0 && cand.size() == 0) {
		puts("0");
	} else if (prefix[n - 1] == 1) {
		for (int i = n - 1; i >= 0; i--) {
			if (prefix[i] == 0) {
				puts("0");	
				return 0;
			}
			if (s[i] == '(') {
				printf("%d\n", i + 1);
				return 0;
			}
		}
	} else if (prefix[n - 1] == -1) {
		for (int i = 0; i < n; i++) {
			if (prefix[i] == -1 && s[i] == ')') {
				printf("%d\n", i + 1);
				return 0;
			}
		}
	}
	puts("0");
	return 0;
}