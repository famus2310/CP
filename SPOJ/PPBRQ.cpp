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

string init[6];
int pos[6];

void rotateX() {
	int tmp = pos[0];
	pos[0] = pos[2];
	pos[2] = pos[5];
	pos[5] = pos[1];
	pos[1] = tmp;
}

void rotateY() {
	int tmp = pos[1];
	pos[1] = pos[3];
	pos[3] = pos[2];
	pos[2] = pos[4];
	pos[4] = tmp;
}

void rotateZ() {
	int tmp = pos[0];
	pos[0] = pos[3];
	pos[3] = pos[5];
	pos[5] = pos[4];
	pos[4] = tmp;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		iota(pos, pos + 6, 0);
		for (int i = 0; i < 6; i++)
			cin >> init[i];
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			char c;
			int q;
			cin >> c >> q;
			q = q % 4;
			if (c == 'X') {
				while (q--)
					rotateX();
			}
			if (c == 'Y') {
				while (q--)
					rotateY();
			}
			if (c == 'Z') {
				while (q--)
					rotateZ();
			}
		}
		for (int i = 0; i < 6; i++) {
			if (i != 0)
				cout << " ";
			cout << init[pos[i]];
		}
		cout << endl;
	}
	return 0;
}
		