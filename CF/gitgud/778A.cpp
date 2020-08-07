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

string s, t;
vector<int> pos;

bool can(int k) {
  int curt = 0;
  for (int i = 0; i < s.size(); i++) {
    if (pos[i] <= k)
      continue;
    if (t[curt] == s[i])
      curt++;
    if (curt == t.size())
      return true;
  }
  return false;
}

int main() {
  cin >> s >> t;
  pos.resize(s.size());
  for (int i = 0; i < s.size(); i++) {
    int a;
    cin >> a; pos[a - 1] = i + 1;
  }
  int lo = 0;
  int hi = s.size();
  while (lo < hi) {
    int mid = lo + (hi - lo + 1) / 2;
    debug(hi, lo);
    if (can(mid))
      lo = mid;
    else hi = mid - 1;
  }
  cout << lo << endl;
  return 0;
}
