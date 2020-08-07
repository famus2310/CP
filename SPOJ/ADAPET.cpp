#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
#define pb push_back
#define debug(x) cout << x << endl
#define NeedForSpeed ios_base::sync_with_stdio(0), cin.tie(0)
#define PI acos(-1)
#define all(c) c.begin(), c.end()
#define SET(x, y) memset((x), y, sizeof(x))
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll INF64 = 1e18;

const int N = 1e5 + 5;

char text[5 * N];
ll prefix[5 * N];
ll len;

ll solve() {
	prefix[0] = -1;
	for (int i = 1, j = -1; i < len; i++) {
		while (j != -1 && text[j + 1] != text[i])
			j = prefix[j];
		if (text[j + 1] == text[i])
			j++;
		prefix[i] = j;
	}
	return (prefix[len - 1] + 1);
}

int main() {
	// NeedForSpeed;
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%s %d", text, &n);
		len = strlen(text);	
		printf("%lld\n", (ll)len + (n - 1) * (len - solve()));
	}
	return 0;
}
		