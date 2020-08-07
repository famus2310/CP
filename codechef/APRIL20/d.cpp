#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
#define pb push_back
#define NeedForSpeed ios_base::sync_with_stdio(0), cin.tie(0)
#define PI acos(-1)
#define all(c) c.begin(), c.end()
#define SET(x, y) memset((x), y, sizeof(x))
const int MOD = 1e9 + 7;
const int INF = 1e9 + 5;
const ll INF64 = 1e18;

template <typename T>
string to_string(const vector<T> &v) {
    string ret = "<";
    for (auto it : v) {
        ret += to_string(it) + ", ";
    }
    ret.pop_back(); ret.pop_back();
    ret += ">";
    return ret;
}

void debug_print() { cerr << endl; }

template <typename T, typename ...U>
void debug_print(T t, U... u) {
    cerr << " " << to_string(t);
    debug_print(u...);
}

#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_print(__VA_ARGS__)
const int N = 1e5 + 5;

ll addmod(ll a, ll b) {
    return (a + b) % MOD;
}

ll mulmod(ll a, ll b) {
    return ((a % MOD) * (b % MOD)) % MOD;
}

ll submod(ll a, ll b) {
    return (MOD + a - b) % MOD;
}

ll powmod(ll a, ll b) {
    ll ret = 1ll;
    while (b) {
        if (b & 1) ret = (ret * a) % MOD;
        b = b >> 1;
        a = (a * a) % MOD;
    }
    return ret;
}

ll inverse(ll a) {
    return powmod(a, MOD - 2);
}

ll prefix(ll n) {
    ll inv = inverse(6);
    ll ret = mulmod(n, n + 1);
    ret = mulmod(ret, 2 * n + 1);
    return mulmod(ret, inv);
}

double evalLog(double x, double base) {
    return log(x) / log(base);
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll bound = pow(n, 1.0/3.0);
        cout << bound << endl;
        ll ans = n % MOD;
        for (ll i = 3; i <= bound; i++) {
            if (i == 4)
                continue;
            ll innerBound = evalLog(n, i);
            ll cur = i;
            for (ll j = 1; j < innerBound; j++) {
                cur = cur * i;
                ans = addmod(ans, mulmod(cur, (n / cur)));
            }
        }

        ans = addmod(ans, submod(prefix(sqrt(n)), prefix(bound)));
        cout << ans << endl;
    }
    return 0;
}