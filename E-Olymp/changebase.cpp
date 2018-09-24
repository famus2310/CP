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
	vis.clear();
	LL cnt[10];
	LL res = 0;
	LL now = 0;
	LL temp;
	memset(cnt, 0, sizeof cnt);
	for (LL i = 0; i < 10; i++) {
		if (now > dest || cnt[i] == 2) continue;
		cnt[i]++;
		now += i;
		for (LL j = i; j < 10; j++) {
			if (now > dest || cnt[j] == 2) continue;
			cnt[j]++;
			now += j;
			for (LL k = j; k < 10; k++) {
				if (now > dest || cnt[k] == 2) continue;
				cnt[k]++;
				now += k;
				for (LL l = k; l < 10; l++) {
					if (now > dest || cnt[l] == 2) continue;
					cnt[l]++;
					now +=l;
					for (LL m = l; m < 10; m++) {
						if (now > dest || cnt[m] == 2) continue;
						cnt[m]++;
						now += m;
						for (LL n = m; n < 10; n++) {
							if (now > dest || cnt[n] == 2) continue;
							cnt[n]++;
							now += n;
							for (LL o = n; o < 10; o++) {			
								if (now > dest || cnt[o] == 2) continue;
								cnt[o]++;
								now += o;
								for (LL p = o; p < 10; p++) {
									if (now > dest || cnt[p] == 2) continue;
									cnt[p]++;
									now += p;
									for (LL q = p; q < 10; q++) {	
										if (now > dest || cnt[q] == 2) continue;
										cnt[q]++;
										now += q;
										for (LL r = q; r < 10; r++) {
											if (now > dest || cnt[r] == 2) continue;
											string temp = "";
											temp.pb((char)(i + '0'));
											temp.pb((char)(j + '0'));
											temp.pb((char)(k + '0'));
											temp.pb((char)(l + '0'));
											temp.pb((char)(m + '0'));
											temp.pb((char)(n + '0'));
											temp.pb((char)(o + '0'));
											temp.pb((char)(p + '0'));
											temp.pb((char)(q + '0'));
											temp.pb((char)(r + '0'));
											sort(all(temp));
											if (vis[temp]) continue;
											cnt[r]++;
											now += r;
											vis[temp] = 1;
											if (now == dest) {
												LL now = 3628800;
												LL div = 1;
												for (int it = 0; it < 10; it++) {
													if (cnt[it] == 2) div = div << 1;
												}
												LL ans1 = now / div;
												LL ans2 = now / div;
												if (cnt[0] == 1) {
													ans1 -= (now / 10) / div;
												} else if (cnt[0] == 0) {
													div = div >> 1;
													ans1 -= (now / 10) / div;
												}
												res += ans1 * ans2;
											}
											now -= r;
											cnt[r]--;
										}
										now -= q;
										cnt[q]--;
									}
									now -= p;
									cnt[p]--;
								}
								now -= o;
								cnt[o]--;
							}
							now -= n;
							cnt[n]--;
						}
						now -= m;
						cnt[m]--;
					}
					now -= l;
					cnt[l]--;
				}
				now -=k;
				cnt[k]--;
			}
			now -= j;
			cnt[j]--;
		}
		now -= i;
		cnt[i]--;
	}
	cout << dest << " = " << res << endl;
	return res;
}

int main() {
	for (int i = 0; i < 11; i++) {
		cout << i << "= " << endl;
		LL res = 0;
		for (int j = 0; j <= 90; j++) {
			for (int k = 0; k <= 90; k++) {
				if (j + k != 90) continue;
				LL tmp = j - k;
				while (tmp < 0) tmp += 11;
				tmp %= 11;
				if (tmp % 11 == i) {
					cout << j << " " << k << endl;
					res += solve(j);
				}
			}
		}
		cout << res << endl;
	}
	return 0;
}
x`