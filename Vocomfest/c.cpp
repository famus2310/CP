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
const int INF = 1e9 + 5;
const LL INF64 = 1e18;

const int N = 1e5 + 5;

LL cnt[5];

bool check() {
	for (int i = 0; i < 5; i++) {
		if (cnt[i] == 0)
			return 0;
	}
	return 1;
}

bool isValid(string x) {
	LL a = 0, i = 0, u = 0, e = 0, o = 0;
	for (char c : x) {
		if (c == 'a')
			a++;
		if (c == 'i')
			i++;
		if (c == 'u')
			u++;
		if (c == 'e')
			e++;
		if (c == 'o')
			o++;
	}
	return a > 0 && i > 0 && u > 0 && e > 0&& o > 0;
}

string s;

int main() {
	SET(cnt, 0);
	cin >> s;
	LL i = 0;
	LL ans = 0LL;
	LL last = 0;
	while (i < s.size()) {
		if (s[i] == 'a') {
			cnt[0]++;
		} 
		if (s[i] == 'i') {
			cnt[1]++;
		} 
		if (s[i] == 'u') {
			cnt[2]++;
		} 
		if (s[i] == 'e') {
			cnt[3]++;
		} 
		if (s[i] == 'o') {
			cnt[4]++;
		} 
		if (check()) {

			// debug(i);
			while (check()) {
				ans = ans + s.size() - i;
				if (s[last] == 'a') {
					cnt[0]--;
				} 
				if (s[last] == 'i') {
					cnt[1]--;
				} 
				if (s[last] == 'u') {
					cnt[2]--;
				} 
				if (s[last] == 'e') {
					cnt[3]--;
				} 
				if (s[last] == 'o') {
					cnt[4]--;
				} 
				last++;
			}
			// debug(ans);
		}
		i++;
	}
	// LL tmp = 0LL;
	// for (int i = 5; i <= s.size(); i++) {
	// 	for (int j = 0; j + i <= s.size(); j++) {
	// 		string now = s.substr(j, i);
	// 		if (isValid(now)) {
	// 			tmp++;
	// 			debug(now);
	// 		}
	// 	}
	// }
	// cout << tmp << endl;
	printf("%lld\n", ans);
	return 0;
}
		