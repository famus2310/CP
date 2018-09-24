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

string arr[] = {"+x", "-x", "+y", "-y", "+z", "-z"};

int main() {
	int n;
	while (scanf("%d", &n) == 1, n != 0) {
		int x = n;
		int y = 0;
		int z = 0;
		char point = 'x';
		int dir = 0; //x+ = 0, x- = 1, y+ = 2, y- = 3, z+ = 4, z- = 5
		for (int i = n - 1; i >= 1; i--) {
			string q;
			cin >> q;
			if (q[0] == 'N') continue;
			else if (q[0] == '+') {
				if (q[1] == 'y') {
					if (dir == 0) dir = 2;
					else if (dir == 1) dir = 3;
					else if (dir == 2) dir = 1;
					else if (dir == 3) dir = 0;
				} else {
					if (dir == 0) dir = 4;
					else if (dir == 1) dir = 5;
					else if (dir == 4) dir = 1;
					else if (dir == 5) dir = 0;
				}
			} else {
				if (q[1] == 'y') {
					if (dir == 0) dir = 3;
					else if (dir == 1) dir = 2;
					else if (dir == 2) dir = 0;
					else if (dir == 3) dir = 1; 
				} else {
					if (dir == 0) dir = 5;
					else if (dir == 1) dir = 4;
					else if (dir == 4) dir = 0;
					else if (dir == 5) dir = 1;
				}
			}
		}
		cout << arr[dir] << endl;
	}
	return 0;
}
		