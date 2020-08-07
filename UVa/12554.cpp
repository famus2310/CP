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

string arr[105];
string song[] = {"Happy", "birthday", "to", "you",
				"Happy", "birthday", "to", "you",
				"Happy", "birthday", "to", "Rujia",
				"Happy", "birthday", "to", "you"};

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int rep = n / 16 + (n % 16 != 0 ? 1 : 0);
	int now = 0;
	for (int i = 0; i < rep; i++) {
		for (int j = 0; j < 16; j++) {
			cout << arr[now++] << ": " << song[j] << endl;
			now = now % n;
		}
	}
	return 0;
}
		