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

int p, s;

struct node{
	int score[35], solve[35];
	int idx;
	bool operator< (const node& other) const {
		int n1 = 0, n2 = 0;
		for (int i = 2; i <= s; i++) {
			// debug(i);
			if (solve[i] < solve[i - 1]) n1++;
			if (other.solve[i] < other.solve[i - 1]) n2++;
		}
		// cout << n1 << " " << n2 << endl;
		if (n1 != n2) return n1 < n2;
		return idx < other.idx;
	}
};

struct temp{
	int score, solve;
	bool operator< (const temp& other) const {
		return score < other.score;
	}
};

node problems[N];

int main() {
	scanf("%d %d", &p, &s);
	for (int i = 1; i <= p; i++) {
		problems[i].idx = i;
		temp tmp[35];
		for (int j = 1; j <= s; j++) {
			scanf("%d", &tmp[j].score);
		}
		for (int j = 1; j <= s; j++) {
			scanf("%d", &tmp[j].solve);
		}
		sort(tmp + 1, tmp + s + 1);
		for (int j = 1; j <= s; j++) {
			problems[i].score[j] = tmp[j].score;
			problems[i].solve[j] = tmp[j].solve;
		}
	}
	sort(problems + 1, problems + p + 1);
	for (int i = 1; i <= p; i++) {
		printf("%d\n", problems[i].idx);
	}
	return 0;
}
		