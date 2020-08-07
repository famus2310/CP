#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
const ll INF64 = 1e18;

const int N = 1e5 + 5;

ll dp[(1 << 20)][20]; //chosen, now
ll required[20]; //required before i
ll weight[20];
map<int, string> numToString;
map<string, int> stringToNum;
string s;
string s1, s2;

int main() {
	NeedForSpeed;
	int t;
	cin >> t;
	while (t--) {
		SET(required, 0);
		SET(weight, 0);
		SET(dp, 0);
		numToString.clear();
		stringToNum.clear();
		ll n, m;
		for (int i = 1; i <= n; i++) {
			cin.ignore();
			getline(cin, s);
			ll sz = s.size();
			ll cur = s.size() - 1;
			ll num = 0;
			while (cur >= 0) {
				if (!isdigit(s[cur]))
					break;
				num = num * 10 + (s[cur] - '0');
				cur--;
			}
			s = s.substr(0, cur);
			numToString[i] = s;
			stringToNum[s] = i;
			weight[i] = num;	
		}
		for (int i = 0; i < m; i++) {
			getline(cin, s);
			auto it = s.find("-->", 0, 3);
			s1 = s.substr(0, it - 1);
			s2 = s.substr(it + 4, s.size() - (it - 4));
			ll num1 = stringToNum[s1];
			ll num2 = stringToNum[s2];
			required[num2] |= (1ll << num1);
		}
		dp[0][0] = 0;
		for (int i = 0; i < (1 << 20); i++)
			dp[i][0] = -INF64;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < (1 << 20); j++) {
				
			}
		}
	}
	return 0;
}
		