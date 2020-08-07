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

LL countDiv(LL a) {
	LL ret = 0LL;
	for (LL i = 1LL; i <= sqrt(a); i++) {
		if (a % i == 0) {
			if (a / i == i) ret++;
			else ret += 2;
		}
	}
	return ret;
}

LL divisor[N];

void preprocess() {
	for (int i = 1; i < N; i++) {
		divisor[i] = countDiv(i);
		// debug(divisor[i]);
	}
}

int main() {
	preprocess();
	LL t;
	scanf("%lld", &t);
	while (t--) {
		LL a, b, c;
		scanf("%lld %lld %lld", &a, &b, &c);
		// cout << divisor[a] << " " << divisor[b] << " " << divisor[c];
		LL ret = countDiv(a) * countDiv(b) * countDiv(c) - (countDiv(__gcd(a , b)) * countDiv(__gcd(b , c)) * countDiv(__gcd(a , c))) + countDiv(__gcd(a , __gcd(b , c)));
		printf("%lld\n", ret);
	} 
	return 0;
}
		