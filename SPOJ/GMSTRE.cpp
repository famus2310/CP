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
	int level, health, enemy, ammo;
	bool operator<(node other) {
		if (health != other.health) return health > other.health;
		if (enemy != other.enemy) return enemy < other.enemy;
		return ammo > other.ammo; 
	}
};

int n;
node arr[105];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int h, e, a;
		scanf("%d %d %d", &h, &e, &a);
		arr[i] = {i + 1, h, e, a};
	}
	sort(arr, arr + n);
	if (n > 1){
		printf("Easiest is level %d\n", arr[0].level);
		printf("Hardest is level %d\n", arr[n - 1].level);
	} else {
		puts("Easiest and Hardest is level 1");
	}
	return 0;
}
		