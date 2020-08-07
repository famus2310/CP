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

string s, r;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cin >> s >> r;
    bool valid = true;
    for (int i = 0; i < n; i++) {
      if (s[i] > r[i])
        valid = false;
    } 
    if (!valid) {
      cout << -1 << endl;
      continue;
    }
    vector<vector<int> > matrix(26, vector<int>(26, 0));
    vector<set<int> > cnt(26, set<int>());
    for (int i = 0; i < n; i++) {
      if (s[i] == r[i])
        continue;
      cnt[r[i] - 'a'].insert(s[i] - 'a');
    }
    int ans = 0;
    for (int i = 0; i < 26; i++) {
      if (cnt[i].size() == 0)
        continue;
      vector<int> v;
      for (auto it : cnt[i])
        v.pb(it);
      for (int i = 1; i < v.size(); i++)
        matrix[v[i - 1]][v[i]] = 1;
      matrix[v.back()][i] = 1;
    }
    for (int i = 0; i < 26; i++) {
      for (int j = 0; j < 26; j++) {
        ans += matrix[i][j];
      }
    }
    cout << ans << endl;
  }
  return 0;
}
