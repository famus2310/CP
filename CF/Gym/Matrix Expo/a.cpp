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
const ll MOD = 1ll << 32;
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


void mulmod(ll A[65][65], ll B[65][65]) {
  ll C[65][65];
  for (int i = 0; i < 65; i++) {
    for (int j = 0; j < 65; j++) {
      C[i][j] = 0;
      for (int k = 0; k < 65; k++)
        C[i][j] = addmod(C[i][j], mulmod(A[i][k], B[k][j]));
    }
  }
  for (int i = 0; i < 65; i++)
    for (int j = 0; j < 65; j++)
      A[i][j] = C[i][j];
}

bool isBound(ll x, ll y) {
  return 0 <= x && 0 <= y && x < 8 && y < 8;
}

ll powmod(ll b) {
  ll ret[65][65];
  ll A[65][65];
  for (int i = 0; i <= 64; i++) {
    for (int j = 0; j <= 64; j++) {
      ret[i][j] = i == j;
      A[i][j] = i == 0;
    }
  }

  const int dx[] = {-2, -2, -1, 1, -1, 1, 2, 2};
  const int dy[] = {-1, 1, -2, -2, 2, 2, -1, 1}; 
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      for (int k = 0; k < 8; k++) {
        int next_x = i + dx[k];
        int next_y = j + dy[k];
        A[i * 8 + j + 1][next_x * 8 + next_y + 1] += (ll)isBound(next_x, next_y);
      }
    }
  }

  while (b) {
    if (b & 1)
      mulmod(ret, A);
    b = b / 2;
    mulmod(A, A);
  }
  ll res = 0ll;
  return ret[0][1];
}

ll solve(ll k) {
  return powmod(k + 1);
}

int main() {
  ll k;
  cin >> k;
  cout << solve(k) << endl; 
  return 0;
}
