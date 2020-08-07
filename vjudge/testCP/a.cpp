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

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> cnt(35, 0);
  vector<int> state(35, 0);
  cin >> s;
  for (char c : s) {
    cnt[c - 'A']++;
  }
  int open = 0;
  bool valid = 1;
  for (char c : s) {
    if (state[c - 'A'] == 0)
      open++;
    if (open > k)
      valid = false;
    state[c - 'A'] = 1;
    cnt[c - 'A']--;
    if (cnt[c - 'A'] == 0) {
      open--;
      state[c - 'A'] = 0;
    }
  }
  if (!valid)
    cout << "YES" << endl;
  else cout << "NO" << endl; 
  return 0;
}
