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
const int INF = 1e9 + 5;
const LL INF64 = 1e18;

const int N = 1e5 + 5;

string dir[] = {"north", "east", "south", "west"};

int main() {
	int n;
	scanf("%d", &n);
	int now = 0;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s[0] == 'l')
			now--;
		else if (s[0] == 'r')
			now++;
		else now = now + 2;
		now = (now + 4) % 4;
	}
	cout << dir[now] << endl;
	return 0;
}
		