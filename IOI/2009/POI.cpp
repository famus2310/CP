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

int n, t, p;
int solved[2005];

struct node{
	int idx, AC[2005], problems, score;
	// node(int n) : idx(n) {} 
	bool operator<(node const& other) const {
		if (score != other.score) 
			return score > other.score;
		else if (problems != other.problems)
			return problems > other.problems;
		return idx < other.idx;
	}
	void getScore() {
		int ret = 0;
		for (int i = 1; i <= t; i++) {
			if (!AC[i]) continue;
			ret += n - solved[i];
		}
		score = ret;
	}
};

node contestant[2005];

int main() {
	memset(solved, 0, sizeof solved);
	scanf("%d %d %d", &n, &t, &p);
	for (int i = 1; i <= n; i++) {
		contestant[i].idx = i;
		int sum = 0;
		for (int j = 1; j <= t; j++) {
			int a;
			scanf("%d", &a);
			if (a) {
				solved[j]++;
				contestant[i].AC[j] = 1;
				sum++;
			}
		}
		contestant[i].problems = sum;
	}
	for (int i = 1; i <= n; i++)
		contestant[i].getScore();
	sort(contestant + 1, contestant + n + 1);
	for (int i = 1; i <= n; i++) {
		if (contestant[i].idx == p) {
			cout << contestant[i].score << " " << i << endl;
			break;
		}
	}
	return 0;
}
		