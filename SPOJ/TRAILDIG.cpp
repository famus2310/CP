#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
#define pb push_back
#define debug(x) cout << x << endl
#define NeedForSpeed ios_base::sync_with_stdio(0), cin.tie(0)
#define PI acos(-1)
#define all(c) c.begin(), c.end()
#define SET(x, y) memset((x), y, sizeof(x))
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll INF64 = 1e18;

const int N = 2e6 + 5;
ll two, five;

void factorize(ll x) {
  while (x % 2 == 0) {
    two++;
    x /= 2;
  }
  while (x % 5 == 0) {
    five++;
    x /= 5;
  }
}

ll powmod(ll a, ll b, ll m) {
  ll ret = 1ll;
  while (b) {
    if (b & 1) ret = (ret * a) % m;
    b = b / 2;
    a = (a * a) % m;
  }
  return ret;
}

ll binpow(ll a, ll b) {
  return powmod(a, b, 10000000000ll);
}

void output(ll a, ll b) {
  string ret;
  for (int i = 0; i < b; i++) {
    ret.pb('0' + a % 10);
    a /= 10;
  }
  for (int i = ret.size() - 1; i >= 0; i--)
    cout << ret[i];
  cout << endl;
}

int main() {
  NeedForSpeed;
  int t;
  cin >> t;
  while (t--) {
    two = five = 0;
    ll a, b, c;
    cin >> a >> b >> c;
    factorize(a);
    five *= b;
    two *= b;
    ll mx = max(five, two);
    five -= mx;
    two -= mx;
    ll ten = binpow(10ll, c);
    ll ret = (powmod(2ll, two, ten) * powmod(5ll, five, ten)) % ten;
    output(ret, c);
  }
  return 0;
}