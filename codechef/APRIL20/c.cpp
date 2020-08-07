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
const int MOD = 998244353;
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

ll mulmod(ll a, ll b) {
    return ((a % MOD) * (b % MOD)) % MOD;
}

ll addmod(ll a, ll b) {
    return (a + b) % MOD;
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

pair<ll, ll> eval(pair<ll, ll> x, pair<ll, ll> y, ll val) {
    if (val == -1) {
        return {addmod(addmod(mulmod(x.first, y.first), mulmod(x.first, y.second)), mulmod(x.second, y.first)), mulmod(x.second, y.second)};
    } else if (val == -2) {
        return {mulmod(x.first, y.first), addmod(addmod(mulmod(x.first, y.second), mulmod(x.second, y.first)), mulmod(x.second, y.second))};
    } else {
        return {addmod(mulmod(x.first, y.first), mulmod(x.second, y.second)), addmod(mulmod(x.second, y.first), mulmod(x.first, y.second))};
    }
}

void output(ll a, ll b, ll inv) {
    cout << mulmod(mulmod(a, a), inv) << " " << mulmod(mulmod(b, b), inv) << " " << mulmod(mulmod(a, b), inv) << " " << mulmod(mulmod(a, b), inv) << endl;
}


string s;
stack<pair<ll, ll> > st; //-1 = &, -2 = |, -3 = ^, -4 = (

int main() {
    // cout << mulmod(3, inverse(16)) << endl;
    int t;
    cin >> t;
    while (t--) {
        ll cnt = 0;
        cin >> s;
        for (char c : s) {
            if (c == '(') {
                st.push({-4, -4});
            } else if (c == '#') {
                st.push({1, 1});
                cnt++;
            } else if (c == '&') {
                st.push({-1, -1});
            } else if (c == '|') {
                st.push({-2, -2});
            } else if (c == '^') {
                st.push({-3, -3});
            } else {
                pair<ll, ll> cur = st.top();
                st.pop();
                ll op = st.top().first;
                st.pop();
                pair<ll, ll> tmp = st.top();
                st.pop();
                pair<ll, ll> ans = eval(cur, tmp, op);
                st.pop();
                st.push(ans);
            }
        }
        ll a = st.top().first;
        ll b = st.top().second;
        ll inv = inverse(powmod(4, cnt));
        output(a, b, inv);
        st.pop();
    }
    return 0;
}