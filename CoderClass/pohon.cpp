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
	int parent, height;
	bool isLeaf;
};

node tree[N];
int arr[N];

int main() {
	int n;
	scanf("%d", &n);
	tree[1] = {0, 0, true};
	int countLeaf = 1;
	int mx = 0;
	for (int i = 2; i <= n; i++) {
		int a;
		scanf("%d", &a);
		if (tree[a].isLeaf) {
			tree[a].isLeaf = false;
		} else {
			countLeaf++;
		}
		tree[i] = {a, tree[a].height + 1, true};
		mx = max(tree[a].height + 1, mx);
	}
	printf("%d %d\n", countLeaf, mx);
	return 0;
}
		