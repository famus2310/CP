#include<iostream>
using namespace std;
typedef long long LL;
const int MOD = 1e9 + 7;
const LL INF64 = 1e18;
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define _CRT_SECURE_NO_WARNINGS


const int N = 1e6 + 1;

LL rec[N];

inline void scanint(long long int &x) {
	register long long int c = getchar_unlocked();
	x = 0;
	long long int neg = 0;
	for(; ((c < 48 || c > 57) && c != '-'); c = getchar_unlocked());
	if (c == '-') {
		neg = 1; 
		c = getchar_unlocked();
	}
	for (; c > 47 && c < 58; c = getchar_unlocked())
		x = (x << 1) + (x << 3) + c - 48;
	if (neg) x = -x;
}

void preprocess() {
	rec[0] = 0;
	rec[1] = 1;
	for (int i = 2; i < N; i++) {
		rec[i] = (rec[i - 1] * rec[i - 1] * 5 - 3 * rec[i - 2] + MOD) % MOD;
	}
}

int main() {
	preprocess();
	LL t;
	scanint(t);
	while (t--) {
		LL a;
		scanint(a);
		printf("%lld\n", rec[a]);
	}
	return 0;
}
		