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

int main() {
	cin >> s;
	if (s[0] == '0') puts("nol");
	else if (s[0] == '-') puts("bilangan bulat negatif");
	else if ('0' <= s[0] && s[0] <= '9') puts("bilangan bulat positif");
	else puts("kata");
	return 0;
}
