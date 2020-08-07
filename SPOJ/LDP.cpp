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
const int MOD = 1e9 + 9;
const int INF = 1e9 + 5;
const LL INF64 = 1e18;

const int N = 1e5 + 5;

inline void scanint(long long int &x) {
	register long long int c = getchar();
	x = 0;
	long long int neg = 0;
	for(; ((c < 48 || c > 57) && c != '-'); c = getchar());
	if (c == '-') {
		neg = 1; 
		c = getchar();
	}
	for (; c > 47 && c < 58; c = getchar())
		x = (x << 1) + (x << 3) + c - 48;
	if (neg) x = -x;
}

LL modex(LL a, LL b) {
	LL ret = 1LL;
	while (b) {
		if (b & 1) ret = (ret * a) % MOD;
		b = b / 2;
		a = (a * a) % MOD;
	}
	return ret;
}

LL inverse(LL a) {
	return modex(a, MOD - 2);
}

vector<LL> prime;
map<int, int> cnt;
LL power[N][35];
bool notPrime[N];
LL LCM;

LL suspect(LL b, LL t, LL u, LL n) {
	LL prod = 1LL;
	while (u) {
		if (u & 1) prod = (prod * b) % n;
		b = (b * b) % n;
		u = u / 2;
	}
	if (prod == 1)
		return 1;
	for (LL i = 1; i <= t; i++) {
		if (prod == n - 1)
			return 1;
		prod = (prod * prod) % n;
	}
	return 0;
}

LL miller(LL n) {
	if (n == 1 || n == 0)
		return 0;
	LL k = n - 1;
	LL t = 0;
	while (!(k % 2)) {
		t++;
		k = k / 2;
	}
	if (n > 2 && n % 2 == 0)
		return 0;
	if (n > 3 && n % 3 == 0)
		return 0;
	if (n > 5 && n % 5 == 0)
		return 0;
	if (n > 7 && n % 7 == 0)
		return 0;
	if (suspect(61, t, k, n) && suspect(7, t, k, n) && suspect(2, t, k, n))
		return 1;
	return 0;
}

LL pollard_rho(LL n) {
    if(n % 2 == 0)
        return 2;
    LL x = rand() % n + 1;
    LL c = rand()%n+1;
    LL y = x;
    LL g = 1;

    //fn is f(x) = x*x + c
    while(g==1)
    {
        x = ((x*x)%n + c)%n;    
        y = ((y*y)%n + c)%n;
        y = ((y*y)%n + c)%n;
        g = __gcd(abs(x-y),n);
    }
    return g;
}

void sieve() {
	notPrime[0] = notPrime[1] = 1;
	for (LL i = 2; i < N; i++) {
		cnt[i] = 0LL;
		if (!notPrime[i]) {
			prime.pb(i);
			for (LL j = i * i; j < N; j += i)
				notPrime[j] = 1;
		}
	}
}

void solve(LL x) {
	for (int i = 0; prime[i] * prime[i] * prime[i] <= x; i++) {
		int tmp = 0;
		while (x % prime[i] == 0) {
			tmp++;
			x /= prime[i];
		}
		if (cnt.find(prime[i]) != cnt.end())
			cnt[prime[i]] = max(cnt[prime[i]], tmp);
		else cnt[prime[i]] = tmp;
	}
	LL sq = sqrt(x);
	if (x < N && !notPrime[x]) {
		if (cnt.find(x) != cnt.end())
			cnt[x] = max(cnt[x], 1);
		else cnt[x] = 1;
	}	else if (miller(x)) {
		if (cnt.find(x) != cnt.end())
			cnt[x] = max(cnt[x], 1);
		else cnt[x] = 1;
	} else if (x == sq * sq && !notPrime[sq]) {
		if (cnt.find(sq) != cnt.end())
			cnt[sq] = max(cnt[sq], 2);
		else cnt[sq] = 2;
	} else if (x != 1) {
		LL divisor = pollard_rho(x);
		if (cnt.find(divisor) != cnt.end())
			cnt[divisor] = max(cnt[divisor], 1);
		else cnt[divisor] = 1;
		if (cnt.find(x / divisor) != cnt.end())
			cnt[x / divisor] = max(cnt[x / divisor], 1);
		else cnt[x / divisor] = 1;
	}
}


// void factorize(LL n, LL k) {
// 	int tmp = k;
// 	if (n == 1)
// 		return;
// 	if (n < N && !notPrime[n]) {
// 		int tmpcnt = 0;
// 		while (tmp % n == 0) {
// 			tmpcnt++;
// 			tmp = tmp / n;
// 		}
// 		cnt[n] = max(cnt[n], tmpcnt);
// 		return;
// 	} 
// 	if (miller(n)) {
// 		int tmpcnt = 0;
// 		while (tmp % n == 0) {
// 			tmpcnt++;
// 			tmp = tmp / n;
// 		}
// 		cnt[n] = max(cnt[n], tmpcnt);
// 		return;
// 	}
// 	int divisor = pollard_rho(n);
// 	factorize(n / divisor, k);
// 	factorize(divisor, k);
// } 

void precompute() {
	for (int i = 1; i < 35; i++) {
		for (int j = 0; j < prime.size(); j++) {
			if (i == 1)
				power[j][i] = prime[j];
			else power[j][i] = (power[j][i - 1] * prime[j]) % MOD;
		}
	}
}

int main() {
	srand(time(NULL));
	sieve();
	precompute();
	LCM = 1LL;
	LL n;
	scanint(n);
	LL k = 1LL;
	for (int i = 0; i < n; i++) {
		LL a;
		scanint(a);
		solve(a);
			// cout << it.first << " " << it.second << " ";
		// cout << endl;
		// factorize(a, a);
		k = (k * a) % MOD;
	}
	// auto t = clock();
	for (auto it : cnt) {
		if (it.second == 1) {
			LCM = (LCM * it.first) % MOD;
		}
		else if (it.second > 1) {
			LCM = (LCM * modex(it.first, it.second)) % MOD;
		}
	}
	// for (int i = 0; i < prime.size(); i++) {
	// 	if (cnt[prime[i]] == 0)
	// 		continue;	
	// 	LCM = (LCM * power[i][cnt[prime[i]]]) % MOD;
	// }
	// cout << fixed << setprecision(6) << (double)(clock() - t) / CLOCKS_PER_SEC << endl;
	LL ret = (k * inverse(LCM)) % MOD;
	printf("%lld\n", ret);
	return 0;
}
		