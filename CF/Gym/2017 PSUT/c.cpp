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
ll dp[2 * N][2][3][3]; //index, mirror state
ll rev[2 * N], cur[2 * N];
ll prefix[2 * N]; 
const string pos = {':', ')', '('};

ll sumPref() {
    SET(rev, 0);
    SET(cur, 0);
    ll ans = 0;
    for(int i = 0; i < s.length() - 1; i++)
    {
        if(s[i] == '(' && s[i + 1] == ':') rev[i + 1]++;
        else if(s[i] == ':' && s[i + 1] == ')') cur[i]++;
    }
    for(int i = 0; i < s.length(); i++)
    {
        if (i == 0)
          cur[0] = rev[0] = 0;
        else {
          rev[i] += rev[i - 1];
          cur[i] += cur[i - 1];
        }
    }
    for(int i = 0; i < s.length(); i++)
    {
        ll temp = rev[i] + (cur[s.length() - 1] - cur[i]);
        if(s[0] == ':' && s[i + 1] == ')') temp++;
        ans = max(ans, temp);
    }
    return ans;
}

ll sumSuff() {
    SET(rev, 0);
    SET(cur, 0);
    ll ans = 0;
    for(int i = 0; i < s.length() - 1; i++)
    {
        if(s[i] == ':' && s[i + 1] == ')') rev[i + 1]++;
        else if(s[i] == '(' && s[i + 1] == ':') cur[i]++;
    }
    for(int i = 0; i < s.length(); i++)
    {
        if (i == 0)
          cur[0] = rev[0] = 0;
        else {
          rev[i] += rev[i - 1];
          cur[i] += cur[i - 1];
        }
    }
    for(int i = 0; i < s.length(); i++)
    {
        ll temp = rev[i] + (cur[s.length() - 1] - cur[i]);
        if(s[0] == '(' && s[i + 1] == ':') temp++;
        ans = max(ans, temp);
    }
    return ans;
}

void mirror() {
  reverse(all(s));
  for (char &c : s) {
    if (c == ')')
      c = '(';
    else if (c == '(')
      c = ')';
  }
}

int main() {
  cin >> s;
  int n = s.size();
  SET(dp, -1);
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      prefix[i] = 0;
      for (int j = 0; j < 3; j++) 
        for (int k = 0; k < 3; k++) 
          dp[i][0][j][k] = dp[i][1][j][k] = -INF;
    } else {
      prefix[i] = prefix[i - 1] + int(s[i] == ')' && s[i - 1] == ':');
      for (int j = 0; j < 3; j++) {
        for (int k = 0; k < 3; k++) {
          dp[i][0][j][k] = dp[i - 1][0][j][k] + int(s[i - 1] == '(' && s[i] == ':');
          if (s[i - 1] == pos[j] && s[i] == pos[k]) {
            dp[i][0][j][k] = max(dp[i][0][j][k], prefix[i - 1]);
          }
          dp[i][1][j][k] = dp[i - 1][1][j][k] + int(s[i] == ')' && s[i - 1] == ':');
          ll adder = dp[i - 1][0][j][k];
          if (j == 0) {
            adder += int(s[i - 1] == '(');
          }
          if (k == 0) {
            adder += int(s[i] == ')');
          }
          dp[i][1][j][k] = max(dp[i][1][j][k], adder);
        }
      }
    }
  }
  ll curans = 0;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      curans = max(curans, dp[n - 1][1][i][j]);
  curans = max(curans, sumPref());
  mirror();
  curans = max(curans, sumSuff());
  cout << curans << endl;
  return 0;

}
