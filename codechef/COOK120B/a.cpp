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
vector<int> cnt;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n >> s;
    cnt.assign(26, 0);
    for (int i = 0; i < n; i++) {
      cnt[s[i] - 'a']++;
    }
    bool odd = false;
    for (auto it : cnt)
      if (it & 1)
        odd = true;
    if (odd)
      cout << "NO" << endl;
    else cout << "YES" << endl; 
  }
  return 0;
}
