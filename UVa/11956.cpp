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

string s;
int arr[100];

int main() {
	int t;
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		memset(arr, 0, sizeof arr);
		int now = 0;
		cin >> s;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '<') now--;
			else if (s[i] == '>') now++;
			else if (s[i] == '+') arr[now]++;
			else if (s[i] == '-') arr[now]--;
			now = (now + 100) % 100;
			arr[now] = (arr[now] + 256) % 256;
		}
		printf("Case %d: ", tc);
		for (int i = 0; i < 100; i++) {
			if (i != 0) cout << " ";
			cout << hex << uppercase << setw(2) << setfill('0') << arr[i];
		}
		cout << endl;
	}
	return 0;
}
		