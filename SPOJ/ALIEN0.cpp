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

pair<ll, ll> countTwoFive(ll x) {
    ll two = 0, five = 0;
    while (x % 2 == 0) {
        two++;
        x /= 2;
    }
    while (x % 5 == 0) {
        five++;
        x /= 5;
    }
    return {two, five};
}

void output(ll x, ll base) {
    stack<int> s;
    while (x) {
        s.push(x % base);
        x /= base;
    }
    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
    cout << endl;
}

ll arr[N][2]; //2 and 5

int main() {
    ll n, q;
    cin >> n >> q;
    arr[0][0] = arr[0][1] = 0;
    for (int i = 1; i <= n; i++) {
        ll a;
        cin >> a;
        pair<ll, ll> cnt = countTwoFive(a);
        arr[i][0] = arr[i - 1][0] + cnt.first;
        arr[i][1] = arr[i - 1][1] + cnt.second;
    }
    while (q--) {
        ll a, b, base;
        cin >> a >> b >> base;
        output(max(arr[b][0] - arr[a - 1][0], arr[b][1] - arr[a - 1][1]), base);
    }
    return 0;
}