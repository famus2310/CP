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

string s;
vector<bool> changed;

int main() {
  int n, k;
  cin >> n >> k;
  cin >> s;
  changed.assign(n, false);
  int change = 0;
  for (int i = 0; i < n / 2; i++) {
    if (s[i] != s[n - i - 1]) {
      s[i] = s[n - i - 1] = max(s[i], s[n - i - 1]);
      change++;
      changed[i] = true;
    }
  }
  if (change > k) {
    cout << -1 << endl;
    return 0;
  }
  k -= change;
  for (int i = 0; i < n / 2 && k > 0; i++) {
    if (s[i] == '9')
      continue;
    if (!changed[i] && k > 1) {
      s[i] = s[n - i - 1] = '9';
      k -= 2;
    } else if (changed[i]) {
      s[i] = s[n - i - 1] = '9';
      k--;
    }
  }
  if ((n & 1) && k > 0) {
    s[n / 2] = '9';
  }
  cout << s << endl;
  return 0;
}
