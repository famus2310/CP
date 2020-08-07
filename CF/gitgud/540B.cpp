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

vector<int> v;
vector<int> o;

int main() {
  int n, k, p, x, y;
  cin >> n >> k >> p >> x >> y;
  if (k == 0) {
    ll sum = y * ((n + 1) / 2) + n / 2;
    if (sum > x) {
      cout << -1 << endl;
      return 0;
    }
    for (int i = 0; i < (n + 1) / 2; i++) {
      cout << y << " ";
    }
    for (int i = 0; i < n / 2; i++)
      cout << 1 << " ";
    cout << endl;
    return 0;
  }
  int persist_n = n;
  int sum = 0;
  for (int i = 0; i < k; i++) {
    int a;
    cin >> a;
    sum += a;
    v.pb(min(a, y));
  }
  sort(all(v));
  int addy = 0;
  int add1 = 0;
  int leftmost = v.size();
  for (int i = v.size() - 1; i >= 0; i--) 
    if (v[i] == y) leftmost = i;
  n -= k;
  while (n--) {
    int sz = v.size();
    int med;
    if (sz & 1) {
      med = v[(sz - 1) / 2];
    } else med = (v[(sz - 1) / 2] +  v[sz / 2]) / 2;
    if (med < y) {
      v.pb(y);
      sum += y; 
      addy++;
    } else {
      v.pb(y);
      sum++;
      add1++;
      v[leftmost++] = 1;
    }
  }
  if (sum > x) {
    cout << -1 << endl;
    return 0;
  }
  int left = sum - x;
  for (int i = leftmost - 1; i >= 0 && left >= y && add1 > 0; i--) {
    v[i] = y;
    left -= y;
    add1--;
    addy++;
  }
  int sz = v.size();
  int med;
  if (sz & 1) {
    med = v[(sz - 1) / 2];
  } else med = (v[(sz - 1) / 2] +  v[sz / 2]) / 2;
  if (med < y) {
    cout << -1 << endl;
    return 0;
  }
  if (v.size() != persist_n) {
    cout << -1 << endl;
    return 0;
  }
  if (sum > x) {
    cout << -1 << endl;
    return 0;
  }
  for (int i = 0; i < addy; i++) {
    cout << y << " ";
  }
  for (int i = 0; i < add1; i++)
    cout << 1 << " " ;
  cout << endl;
  return 0;
}
