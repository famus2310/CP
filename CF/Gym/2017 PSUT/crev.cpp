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
int dp[3][3];
int smile[2 * N];
int sad[2 * N];
const int pos[] = {':', '(', ')'};

int main() {
  cin >> s; s += "$";
  int n = s.size();
  smile[n - 1] = sad[0] = 0;
  for (int i = n - 2; i >= 0; i--)
    smile[i] = smile[i + 1] + (int)(s[i] == ':' && s[i + 1] == ')');
  for (int i = 1; i < n; i++) 
    sad[i] = sad[i - 1] + (int)(s[i] == ':' && s[i - 1] == '(');

  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      dp[i][j] = -INF;
  int ans = smile[0];
  for (int i = 0; i < n; i++) {
    ans = max(ans, sad[i] + smile[i + 1]);
    if (i == 0) {
      for (int j = 0; j < 3; j++) {
        for (int k = 0; k < 3; k++) {
          dp[j][k] = -INF;
        }
      }
    } else {
      for (int j = 0; j < 3; j++) {
        for (int k = 0; k < 3; k++) {
          if (s[i - 1] == '(' && s[i] == ':')
            dp[j][k]++;
          if (s[i - 1] == pos[j] && s[i] == pos[k])
            dp[j][k] = max(dp[j][k], smile[0] - smile[i - 1]);
        }
      }
    }
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 3; k++) {
        int adder = dp[j][k] + smile[i + 1];
        if (j == 0 && s[i] == '(')
          adder++;
        if (k == 0 && s[i + 1] == ')')
          adder++;
        ans = max(ans, adder);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
