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
vector<int> prefix;

int kmp(const string& t) {
  int n = t.size();
  prefix.assign(n, 0);
  int ret = 0;
  for (int i = 1; i < n; i++) {
    int j = prefix[i - 1];
    while (j > 0 && t[i] != t[j])
      j = prefix[j - 1];
    if (t[i] == t[j])
      j++;
    prefix[i] = j;
    if (i > s.size()) {
      int lo = i - s.size() - prefix[i];
      int orig = (n - i - 1);
      int hi = orig + prefix[i] - 1;
      if (lo == 0) {
        int mn = min((int)s.size(), prefix[i] * 2 + (prefix[i] + 1 != orig));
        ret = max(ret, mn);
      }
      if (orig <= prefix[i] - 1) {
        ret = max(ret, hi);
      }
    }
  }
  return ret;
}

int main() {
  int n;
  cin >> n;
  cin >> s;
  string text = s + "#";
  reverse(all(s));
  text += s; 
  int ans = kmp(text);
  text = s + "#";
  reverse(all(s));
  text += s;
  ans = max(ans, kmp(text));
  cout << ans << endl;
  return 0;
}
