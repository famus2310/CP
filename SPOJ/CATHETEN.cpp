#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
#define pb push_back
#define debug(x) cout << x << endl
#define NeedForSpeed ios_base::sync_with_stdio(0), cin.tie(0)
#define PI acos(-1)
#define all(c) c.begin(), c.end()
#define SET(x, y) memset((x), y, sizeof(x))
const int MOD = 1e9 + 7;
const int INF = 1e9 + 5;
const LL INF64 = 1e18;
 
const int N = 1e5 + 5;
 
LL two;
 
#include <bits/stdc++.h>
 
using namespace std;
 
#define abs_val(a)       (((a)>0)?(a):-(a))
 
LL mulMod(LL a, LL b, LL c)
{
    LL x = 0, y = a%c;
    while (b > 0)
    {
        if (b%2 == 1)
            x = (x+y)%c;
        y = (y*2)%c;
        b /= 2;
    }
    return x%c;
}
 
LL gcd(LL a, LL b)
{
     return !b ? a : gcd(b, a%b);
}
 
LL Mod(LL a, LL b, LL p)
{
    LL res = 1;
    LL x = a%p;
 
    while (b)
    {
        if (b&1)
        {
            res = mulMod(res, x, p);
        }
        x = mulMod(x, x, p);
        b /= 2;
    }
    return res%p;
}
 
 
bool millerTest(LL d, LL s, LL n)
{
    LL a = rand() % (n-4) + 2;
    LL x = Mod(a, s, n);
 
    if (x==1 or x==n-1)
        return true;
 
    for (int r = 1; r < d; r++)
    {
        x = mulMod(x, x, n);
 
        if (x==1)
            return false;
        if (x==n-1)
            return true;
    }
    return false;
}
 
 
 
bool isPrime(LL n, int k = 20)
{
    if (n <= 1 || n==4)
        return false;
    if (n<=3)
        return true;
    if (n%2==0)
        return false;
 
    LL s = n-1, d = 0;
    while (s%2==0)
    {
        s/=2;
        d++;
    }
    for (int i = 0; i < k; i++)
    {
        if (millerTest(d, s, n)==false)
            return false;
    }
    return true;
}
 
map <LL, LL> MAP;
 
LL pollard_rho(LL n)  //pollard rho implementation
{
    if(n%2==0)
        return 2;
 
    LL x = rand()%n+1;
    LL c = rand()%n+1;
    LL y = x;
    LL g = 1;
 
    //fn is f(x) = x*x + c
    while(g==1)
    {
        x = (mulMod(x, x, n) + c)%n;
        y = (mulMod(y, y, n) + c)%n;
        y = (mulMod(y, y, n) + c)%n;
        g = gcd(abs_val(x-y),n);
    }
    return g;
}
 
void factorize(LL n)   //fn to factorize the number
{
    if(n == 1)
        return;
 
    if(isPrime(n))      //if n is prime,store it
    {
        MAP[n]++;
        return;
    }
    LL divisor = pollard_rho(n);   //get a divisor of n
    factorize(divisor);
    factorize(n/divisor);
}
 
 
 
int main() {
	NeedForSpeed;
	int t;
	cin >> t;
	while (t--) {
		two = 0;
		MAP.clear();
		LL n;
		cin >> n;
		while (n % 2 == 0) {
			two += 2;
			n = n / 2;
		}
		factorize(n);
		LL ret = 1LL;
		for (auto it : MAP) {
			ret = ret * (2 * it.second + 1);
		}
		LL ans;
		if (two) {
			ans = ret * (two - 1);
			
		} else {
			ans = ret;
		}
		LL sq = sqrt(n);
		if (sq * sq == n) {
			ans--;
		}
		cout << ans / 2 << endl;
	}
	return 0;
}