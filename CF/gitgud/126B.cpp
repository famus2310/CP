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

vector<int> prefix;

void build(const string &s) {
  int n = s.size();
  prefix.assign(n, 0);
  for (int i = 1; i < n; i++) {
    int j = prefix[i - 1];
    while (j > 0 && s[j] != s[i]) {
      j = prefix[j - 1];
    }
    prefix[i] = j + (s[i] == s[j]);
  }
}

int main() {
  string s;
  cin >> s;
  if (s.size() < 3) {
    cout << "Just a legend" << endl;
    return 0;
  }
  build(s);
  int cur = prefix[s.size() - 1];
  if (cur == 0) {
    cout << "Just a legend" << endl;
    return 0;
  }
  int ans = -1;
  for (int i = 0; i < s.size() - 1; i++) {
    if (cur == prefix[i])
      ans = cur;
  }
  if (ans == -1) {
    cur = prefix[cur - 1];
    if (cur == 0) {
      cout << "Just a legend" << endl;
      return 0;
    }
    for (int i = 0; i < s.size() - 1; i++) {
      if (cur == prefix[i])
        ans = cur;
    }
  }
  if (ans == -1) {
    cout << "Just a legend" << endl;
    return 0;
  }
  cout << s.substr(0, ans) << endl;
  return 0;
}
