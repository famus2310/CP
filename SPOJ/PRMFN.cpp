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
const int MOD = 1e9 + 7;
const int INF = 1e9;
const LL INF64 = 1e18;

const LL N = 10000 + 5;
LL mulmod(LL a, LL b, LL c) {
  LL x = 0, y = a % c;
  while (b) {
    if (b & 1) x = (x + y) % c;
    y = (y << 1) % c;
    b >>= 1;
  }
  return x % c;
}
 
LL fastPow(LL x, LL n, LL c) {
  LL ret = 1;
  while (n) {
    if (n & 1) ret = mulmod(ret, x, c);
    x = mulmod(x, x, c);
    n >>= 1;
  }
  return ret;
}
 
bool witness(LL n, LL d, LL s, LL a)
{
	LL x = fastPow(a, d, n);
	LL y;
	
	// pass trought aLL a^(d*2^k) mod n ( 0 <= k <= s )
	while (s--) {

		y = mulmod(x, x, n);
	
		// if y is equal to 1 it must have been a square of -1 or 1 mod n to be prime
		// if not the number is composite
		if (y == 1 and x != 1 and x != n-1) return false;

		x = y;
	}
	// if a^(d*2^s) != 1 mod n than n is not prime
	// a^(n-1) = 1 mod n for every n prime (fermats little theorem)
	if (y != 1) return false;
	
	// if the number is not confirmed composite return that it is either a prime
	// or strong pseudoprime in base a
	return true;
}

// all numbers up to 10^18 are confirmed composite if these bases are used
// if numbers are up to 10^9 use primes_small to confirm compositeness
LL primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23};
LL primes_small[] = {2, 3, 5, 7, 11};

// ckeck primality up to 10^18 in O(log(n)*k)
// to numbers up to 10^18, testing all 9 prime numbers smaller or equal to 23 suffices
bool is_prime(LL n)
{
	// trivial cases
	if (n == 2 or n == 3) return true;
	if (n < 2 or n%2 == 0 or n%3 == 0) return false;

	// calculate d = biggest odd number divisor of n-1
	// s = number of the biggest power of two that divides n-1
	// such that n-1 = d*2^s (d odd)
	// __builtin_ctzll returns expoent of biggest power of two that divides n-1
	LL s = __builtin_ctzll(n-1);
	LL d = (n-1)>>s;
	
	// check primality with the 13 bases
	for (LL p : primes) {

		if (p == n) return true;
		
		// if composite returns false
		if (!witness(n, d, s, p)) return false;
	}

	// after the iterations all remaining numbers are prime
	return true;
}

bool isCharPrime(char c) 
{ 
    return (c == '2' || c == '3' || c == '5' || c == '7'); 
} 
  
// replace with previous prime character 
void decrease(string& s, int i) 
{ 
    // if 2 erase s[i] and replace next with 7 
    if (s[i] <= '2') { 
        s.erase(i, 1); 
        s[i] = '7'; 
    } 
  
    else if (s[i] == '3') 
        s[i] = '2'; 
    else if (s[i] <= '5') 
        s[i] = '3'; 
    else if (s[i] <= '7') 
        s[i] = '5'; 
    else
        s[i] = '7'; 
  
    return; 
} 
  
LL primeDigits(string s) 
{ 
    for (int i = 0; i < s.length(); i++) { 
  
        // find first non prime char 
        if (!isCharPrime(s[i])) { 
  
            // find first char greater than 2 
            while (s[i] <= '2' && i >= 0) 
                i--; 
  
            // like 20 
            if (i < 0) { 
                i = 0; 
                decrease(s, i); 
            } 
  
            // like 7721 
            else
                decrease(s, i); 
  
            // replace remaining with 7 
            for (int j = i + 1; j < s.length(); j++)  
                s[j] = '7';             
  
            break; 
        } 
    } 
    LL ret = stoll(s);
    while (!is_prime(ret)) {
    	ret = stoll(s);
    }
    return ret; 
} 
  
int main() {
	fastio;
	LL t;
	cin >> t;
	for (LL i = 1; i <= t; i++) {
		string n;
		cin >> n;
		cout << "Case " << i << ": " << primeDigits(n) << endl;
	}
	return 0;
}
		