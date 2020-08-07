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
int n, k;
vector<vector<int> > prefix;

bool can(int x) {
  int ans = 0;
  for (int i = 0; i < 26; i++) {
    ans += (prefix[x - 1][i] > 0);
  }
  for (int i = x; i < s.size(); i++) {
    int ret = 0;
    for (int j = 0; j < 26; j++)
      ret += (prefix[i][j] - prefix[i - x][j] > 0);
    ans = min(ans, ret);
  }
  return ans <= (n - k);
}

int main() {
  int t;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    cout << "Case #" << tc << ": ";
    cin >> k;
    cin >> s;
    n = 0;
    s += s;
    prefix.assign(s.size(), vector<int>(26, 0));
    for (int i = 0; i < s.size(); i++) {
      if (i > 0) {
        for (int j = 0; j < 26; j++)
          prefix[i][j] = prefix[i - 1][j];
      }
      prefix[i][s[i] - 'A']++;
    }
    for (int i = 0; i < 26; i++)
      n += prefix[s.size() - 1][i] > 0;
    int lo = 0;
    int hi = s.size() / 2;
    while (lo < hi) {
      int mid = lo + (hi - lo + 1) / 2;
      if (can(mid))
        lo = mid;
      else hi = mid - 1;
    }
    cout << lo << endl;
  }
  return 0;
}
