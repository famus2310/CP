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

LL table[N][18];
LL arr[N];
LL tmp[N];
deque<LL> dq;

inline void scanint(long long int &x)
 {     register long long int c = getchar_unlocked();
     x = 0;
     long long int neg = 0;
     for(;((c<48 || c>57) && c != '-');c = getchar_unlocked());
     if(c=='-') {neg=1;c=getchar_unlocked();}
     for(;c>47 && c<58;c = getchar_unlocked()) {x = (x<<1) + (x<<3) + c - 48;}
     if(neg) x=-x;
 }

void build(LL n) {
	for (int i = 0; i < n; i++)
		table[i][0] = tmp[i];
	for (int i = 1; i <= 17; i++) {
		for (int j = 0; j <= n - (1LL << i); j++) 
			table[j][i] = max(table[j][i - 1], table[j + (1LL << (i - 1))][i - 1]);
	}
}

LL query(LL l, LL r) {
	LL ans = -INF64;
	for (int i = 17; i >= 0; i--) {
		if (l + (1LL << i) - 1 <= r) {
			ans = max(ans, table[l][i]);
			l += 1LL << i;
		}
	}
	return ans;
}

int main() {
	LL t; scanint(t);
	for (int tc = 1; tc <= t; tc++) {
		LL n, k; scanint(n); scanint(k);
		dq.clear();
		int now = 0;
		for (int i = 0; i < n; i++) {
			scanint(arr[i]);
			if (i < k - 1) {
				while (!dq.empty() && arr[dq.back()] >= arr[i])
					dq.pop_back();
				dq.push_back(i);
			}
			else {
				while (!dq.empty() && dq.front() < now) 
					dq.pop_front();
				while (!dq.empty() && arr[dq.back()] >= arr[i])
					dq.pop_back();
				dq.push_back(i);
				tmp[now] = arr[dq.front()];
				//cout << now << " " << tmp[now] << endl;
				now++;
			}
		}
		build(now);
		LL q;
		scanint(q);
		printf("Case %d:\n", tc);
		while (q--) {
			LL u, v;
			scanf("%lld %lld", &u, &v);
			if (v - u + 1 < k) puts("Impossible");
			else {
				LL tmp = query(u - 1, v - k);
				printf("%lld\n", tmp);
			} 
		}
	}
	return 0;
}
		