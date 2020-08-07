#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const int N = 100000;

pair<int, int> ans[N];

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	
	if (m < n - 1) {
		puts("Impossible");
		return 0;
	}
	
	int cur = 0;
	
	forn(i, n) for (int j = i + 1; j < n; ++j){
		if (cur == m)
			break;
		if (__gcd(i + 1, j + 1) == 1)
			ans[cur++] = make_pair(j, i);
	}
	
	if (cur != m){
		puts("Impossible");
		return 0;
	}
	
	puts("Possible");
	forn(i, m)
		printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
	
	return 0;
}