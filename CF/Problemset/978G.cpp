#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define debug(x) cout << x << endl
#define fastio ios_base::sync_with_stdio(0), cin.tie(0)
#define PI acos(-1)
#define all(c) c.begin(), c.end()
#define pii pair<int, pair<int, int> > 
const int MOD = 1e9 + 7;
const int INF = 1e9;
const LL INF64 = 1e18;

const int N = 1e5 + 5;

struct node {
	int a, b, c, idx;
	bool operator< (const node& other) const {
		if (a != other.a) return a < other.a;
		else if (b != other.b) return b < other.b;
		return c < other.c;
	}
};

int isExam[105];
int prepared[105];
int need[105];
priority_queue<pii, vector<pii>, greater<pii> > pq;
node arr[105];
vector<int> ans;

int main() {
	memset(prepared, 0, sizeof prepared);
	memset(isExam, 0, sizeof isExam);
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d %d %d", &arr[i].a, &arr[i].b, &arr[i].c);
		arr[i].idx = i;
		isExam[arr[i].b] = i;
		need[i] = arr[i].c;
	}
	sort(arr + 1, arr + m + 1);
	int now = 1;
	for (int i = 1; i <= n; i++) {
		while (now <= m && arr[now].a == i) {
			pq.push({arr[now].b, {arr[now].c, arr[now].idx}});
			now++;
		}
		if (isExam[i]) {
			if (prepared[isExam[i]] < need[isExam[i]]) {
				puts("-1");
				return 0;
			} else {
				ans.pb(m + 1);
			}
		} else {
			if (!pq.empty()) {
				int tp = pq.top().first;
				int prep = pq.top().second.first;
				int idx = pq.top().second.second;
				pq.pop();
				prepared[idx]++;
				ans.pb(idx);
				prep--;
				if (prep != 0) {
					pq.push({tp, {prep, idx}});
				}
			} else ans.pb(0);
		}
	}
	for (int i = 0; i < ans.size(); i++) {
		printf("%d%c", ans[i], i == ans.size() - 1 ? '\n' : ' ');
	}
	return 0;
}
		