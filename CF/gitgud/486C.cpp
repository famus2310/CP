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
  int n, c;
  cin >> n >> c;
  c--;
  cin >> s;
  if (c < n / 2) {
    int leftmost = n;
    int rightmost = -1;
    int change = 0;
    for (int i = 0; i < n / 2; i++) {
      if (s[i] != s[n - i - 1]) {
        leftmost = min(leftmost, i);
        rightmost = max(rightmost, i);
        int cur = abs(s[i] - s[n - i - 1]);
        change += min(cur, 26 - cur);
      }
    }
    int ans;
    if (leftmost == n)
      ans = 0;
    else if (c <= leftmost)
      ans = change + (rightmost - c);
    else if (c >= rightmost)
      ans = change + (c - leftmost);
    else ans = min((c - leftmost) * 2 + rightmost - c, (rightmost - c) * 2 + c - leftmost) + change;
    cout << ans << endl;
  } else {
    int leftmost = n;
    int rightmost = -1;
    int change = 0;
    for (int i = n / 2; i < n; i++) {
      if (s[i] != s[n - i - 1]) {
        leftmost = min(leftmost, i);
        rightmost = max(rightmost, i);
        int cur = abs(s[i] - s[n - i - 1]);
        change += min(cur, 26 - cur);
      }
    }
    int ans;
    if (leftmost == n)
      ans = 0;
    else if (c <= leftmost)
      ans = change + (rightmost - c);
    else if (c >= rightmost)
      ans = change + (c - leftmost);
    else ans = min((c - leftmost) * 2 + rightmost - c, (rightmost - c) * 2 + c - leftmost) + change;
    cout << ans << endl;
  }
  return 0;
}
