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

LL notPrime[N];
LL comp[N];
LL arr[N];
LL cnt[N];
int n;

void sieve() {
	SET(comp, 0);
	memset(notPrime, -1, sizeof notPrime);
	notPrime[0] = notPrime[1] = 1;
	for (LL i = 2; i < N; i++) {
		if (notPrime[i] == -1) {
			notPrime[i] = i;
			comp[i] = 1;
			for (LL j = 2 * i ; j < N; j += i) {
				if (notPrime[j] == -1)
					notPrime[j] = i;
				comp[j]++;
			}
		}
	}
}

LL solve() {
	LL ret = 0LL;
	LL id = 0LL;
	for (int i = 0; i < n; i++) {
		cnt[arr[i]]++;
		ret = max(ret, cnt[arr[i]] * comp[arr[i]]);
		if (notPrime[arr[i]] != arr[i]) {
			while (arr[i] > 1) {
				LL div = notPrime[arr[i]];
				cnt[div]++;
				ret = max(ret, cnt[div] * comp[div]);
				while (arr[i] % div == 0) {
					if (arr[i] / div != div && arr[i] / div != 1) {
						cnt[arr[i] / div]++;
						ret = max(ret, cnt[arr[i] / div] * comp[arr[i] / div]);
					}
					arr[i] /= div;
				}
				if (notPrime[arr[i]] == arr[i]) break;
			}
		}
		// debug(ret);
	}
	return ret;
}

int main() {
	sieve();
	int t;
	scanf("%d", &t);
	while (t--) {
		SET(cnt, 0);
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%lld", arr + i);
		printf("%lld\n", solve());
	}
	return 0;
}
		