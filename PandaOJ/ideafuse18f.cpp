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

void solve(LL num, LL idx) {
	string s = to_string(num);
	for (int i = 0; i < s.size(); i++) {
		if (idx == i + 1) printf("(");
		cout << s[i];
		if (idx == i + 1) printf(")");
	}
	puts("");
}

LL toDec(LL n) {
	LL ret = 0;
	LL now = 0;
	while (n) {
		ret += (n % 10) * pow(8.0, now);
		n /= 10;
		now++;
	}
	return ret;
}

LL toOct(LL n) {
	LL ret = 0;
	LL now = 0;
	while (n) {
		ret += (n % 8) * pow(10.0, now);
		n /= 8; 
		now++;
	}
	return ret;
}

LL countDig(LL n) {
	LL ret = 0;
	while (n) {
		ret++;
		n /= 10;
	}
	return ret;
}

int main() {
	LL t;
	scanf("%lld", &t);
	t = toDec(t);
	for (int tc = 1; tc <= t; tc++) {
		LL n, base = 9, digit;
		scanf("%lld", &n);
		LL nTen = toDec(n);
		while (nTen - base * digit > 0) {
			nTen -= base * digit;
			base *= 10;
			digit++;
		}
		digit = countDig(n); 
		LL idx = nTen % digit;
		if (idx == 0) idx = digit;
		LL num = toDec(n);
		// for (int i = 1; i < digit; i++) {
		// 	num *= 10;
		// }
		// num += (idx == digit) ? nTen / digit - 1 : n / digit;
		stack<LL> st;
		debug(num);
		st.push(num % 8);
		num /= 8;
		while (num) {
			st.push(num % 8);
			num /= 8;
		}
		LL i = 1;
		while (!st.empty()) {
			if (idx == i) printf("(%lld)", st.top());
			else printf("%lld", st.top());
			st.pop();
			i++;
		}
		puts("");
	}
	return 0;
}