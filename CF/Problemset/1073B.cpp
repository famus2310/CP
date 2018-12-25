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

queue<int> q;
bool notStack[2 * N];
int arr[2 * N];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		q.push(a);
	}
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		if (notStack[a]) {
			printf("0");
		} else {
			int cnt = 0;
			while (!q.empty()) {
				cnt++;
				int now = q.front(); q.pop();
				notStack[now] = 1;
				if (now == a)
					break;
			}
			printf("%d", cnt);
		}
		if (i == n - 1)
			puts("");
		else printf(" ");
	}
	return 0;
}
		