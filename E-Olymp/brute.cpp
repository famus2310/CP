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

unordered_map<string, bool> vis;

LL solve(LL dest) {
	LL cnt[10];
	LL now = 0;
	LL res = 0;
	bool zero = 0;
	memset(cnt, 0, sizeof cnt);
	for (int i = 0; i < 10; i++) {
		if (i == 0) zero = 1;
		else zero = 0;
		now += i;
		for (int j = i + 1; j < 10; j++) {
			if (now > dest) continue;
			now += j;
			for (int k = j + 1; k < 10; k++) {
				if (now > dest) continue;
				now += k;
				for (int l = k + 1; l < 10; l++) {
					if (now > dest) continue;
					now += l;
					for (int m = l + 1; m < 10; m++) {
						if (now > dest) continue;
						now += m;
						if (now == dest) {
							LL now = 120;
							LL ans1 = now;
							LL ans2 = now;
							if (!zero) {
								ans1 -= (now / 5);
							}
							res += ans1 * ans2;
						}
						now -= m;
					}
					now -= l;
				}
				now -= k;
			}
			now -= j;
		}
		now -= i;
	}
	return res;
}

int main() {

	for (int n = 0; n < 11; n++) {
		cout << n << "= " << endl;
		LL ans = 0;
		for (int i = 0; i <= 90; i++) {
			for (int j = 0; j <= 90; j++) {
				if (i + j != 45) continue;
				LL tmp = i - j;
				while (tmp < 0) tmp += 11;
				tmp %= 11; 
				if (tmp == n) {
					cout <<i << " " << j << endl;
					ans += solve(i);
				}
			}
		}
		cout << ans << endl;
	}
}

//45 = 129464906256000
//56 =  33698476980000
//34 = 	35950185936000
//67 = 	  231472080000
//23 =    257191200000

// mod 1 = 44 46, 33 57, 22 68
// mod 2 = 43 47, 32 58, 21 69
// mod 3 = 42 48, 31 59, 20, 70
// mod 4 = 41 49, 

// a - b
//a + b = 45
//a - b