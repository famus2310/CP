#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
#define pb push_back
#define NeedForSpeed ios_base::sync_with_stdio(0), cin.tie(0)
#define PI acos(-1)
#define all(c) c.begin(), c.end()
#define SET(x, y) memset((x), y, sizeof(x))
const ll MOD = 1e9 + 7;
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

ll addmod(ll a, ll b) {
  a %= MOD;
  b %= MOD;
  return (a + b) % MOD;
}

ll mulmod(ll a, ll b) {
  a %= MOD;
  b %= MOD;
  return (a * b) % MOD;
}

void mulmod(ll A[5][5], ll B[5][5]) {
  ll C[5][5];
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      C[i][j] = 0;
      for (int k = 0; k < 5; k++)
        C[i][j] = addmod(C[i][j], mulmod(A[i][k], B[k][j]));
    }
  }
  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5; j++)
      A[i][j] = C[i][j];
}

ll powmod(ll b, ll rem) {
  ll ret[5][5];
  ll A[5][5];
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      ret[i][j] = i == j;
      A[i][j] = 0;
      if (i == 0) {
        A[i][j] = (4 - j) * (4 - j);
      } 
    }
    if (i > 0)
      A[i][i - 1] = 1;
  }

  while (b) {
    if (b & 1)
      mulmod(ret, A);
    b = b / 2;
    mulmod(A, A);
  }
  ll res = 0ll;
  for (int i = 0; i < 4; i++) {
    res = addmod(res, ret[i][0]);
  }
  if (rem < 5)
    res = addmod(res, ret[4][0]);
  return res;
}

ll solve(ll n, ll rem) {
  return powmod(n, rem);
}

int main() {
  ll n;
  cin >> n;
  ll rem = n % 10;
  n /= 10;
  cout << solve(n, rem) << endl;
  return 0;
}
