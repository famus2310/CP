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

struct node{
	int mn, mx;
};

node arr[35];
int ans[35];

int main() {
	int d, sumTime;
	scanf("%d %d", &d, &sumTime);
	int minTime = 0, maxTime = 0;
	for (int i = 0; i < d; i++) {
		scanf("%d %d", &arr[i].mn, &arr[i].mx);
		minTime += arr[i].mn; maxTime += arr[i].mx;
	}
	if (sumTime < minTime || sumTime > maxTime) puts("NO");
	else {
		puts("YES");
		memset(ans, 0, sizeof ans);
		for (int i = 0; i < d; i++) {
			ans[i] = arr[i].mn;
			sumTime -= arr[i].mn;
		}
		while (sumTime > 0) {
			for (int i = 0; i < d && sumTime > 0; i++) {
				if (ans[i] < arr[i].mx){
					ans[i]++;
					sumTime--;
				}
			}
		}
		for (int i = 0; i < d; i++) {
			printf("%d%c", ans[i], i == d - 1 ? '\n' : ' ');
		}
	}
	return 0;
}
		