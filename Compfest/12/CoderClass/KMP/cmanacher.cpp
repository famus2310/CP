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

int manacher(const string &s, int lo, int hi) {
  int ret = 0;
  int n = s.size();
  vector<int> d1(n);
  for (int i = 0, l = 0, r = -1; i < n; i++) {
    int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
    while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
        k++;
    }
    d1[i] = k--;
    if (i + k > r) {
        l = i - k;
        r = i + k;
    }
    if (l == 0 || r == n - 1) 
      ret = max(ret, r - l + 1);
    if (l <= lo) {
      int rem = lo - l;
      if (r - rem < hi)
        ret = max(ret, 2 * lo + ((r - rem) - (l + rem) + 1));
    }
    if (r >= hi) {
      int rem = r - hi;
      if (l + rem > lo)
        ret = max(ret, 2 * lo + ((r - rem) - (l + rem) + 1));
    }
  }

  vector<int> d2(n);
  for (int i = 0, l = 0, r = -1; i < n; i++) {
    int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
    while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
        k++;
    }
    d2[i] = k--;
    if (i + k > r) {
        l = i - k - 1;
        r = i + k ;
    }
    if (l == 0 || r == n - 1) 
      ret = max(ret, r - l + 1);
    if (l <= lo) {
      int rem = lo - l;
      if (r - rem < hi)
        ret = max(ret, 2 * lo + ((r - rem) - (l + rem) + 1));
    }
    if (r >= hi) {
      int rem = r - hi;
      if (l + rem > lo)
        ret = max(ret, 2 * lo + ((r - rem) - (l + rem) + 1));
    }
  }
  return ret;
}

string s;

int main() {
  int n;
  cin >> n;
  cin >> s;
  int lo = 0;
  int hi = n - 1;
  while (lo <= hi && s[lo] == s[hi]) {
    lo++;
    hi--;
  }
  int ans = 0;
  if (lo > hi) {
    ans = n;
  } else {
    ans = n - (hi - lo + 1) + 1;
    ans = max(ans, manacher(s, lo, hi));
  }
  cout << ans << endl;
  return 0;
}
