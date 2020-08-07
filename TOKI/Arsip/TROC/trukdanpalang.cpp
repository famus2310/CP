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

queue<pair<int, int> > q;
queue<int> b; 
int arr[2005][2];

int main() {
	int n, p, t, v, d;
	scanf("%d %d %d %d %d", &n, &p, &t, &v, &d);
	for (int i = 0; i < n; i++) 
		scanf("%d", &arr[i][0]);
	for (int i = 0; i < n; i++) 
		scanf("%d", &arr[i][1]);
	for (int i = 0; i < n; i++)
		q.push({arr[i][0], arr[i][1]});
	double ans = 0;
	int now = t;
	int last = 0;
	while (!q.empty() || !b.empty()) {
		if (b.empty()) {
			if (q.front().second < t) {
				now = q.front().second;
				last = q.front().first;
				b.push(now + p);
			}
			q.pop();
		} else if (q.empty()) {
			ans += (b.front() - last) * abs(t - now);
			b.pop(); 
		} else {
			if (q.front().first < b.front() && q.front().first < t) {
				b.pop();
				ans += (q.front().first - last) * abs(t - now);
				now = q.front().second;
				last = q.front().first;
				b.push(q.front().first + p);
			} else if (q.front().first >= b.front() && q.front().first < t) {
				ans += (b.front() - last) * abs(t - now);
				b.pop();
				now = q.front().second;
				last = q.front().first;
				b.push(q.front().first + p);
			}
			q.pop(); 
		}
	}
	printf("%lf\n", ans);
	return 0;
}
		