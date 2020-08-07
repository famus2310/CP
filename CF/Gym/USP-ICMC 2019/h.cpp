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

void mul(ll A[9][9], ll B[9][9]) {
  ll C[9][9];
  SET(C, 0);
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      for (int k = 0; k < 9; k++) {
        C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
      }
    }
  }

  for (int i = 0; i < 9 ;i++) 
    for (int j = 0; j < 9; j++)
      A[i][j] = C[i][j];
}

ll powmod(ll b) {
  ll ret[9][9];
  SET(ret, 0);
  for (int i = 0; i < 9; i++)
    ret[i][i] = 1;
  ll B[9][9] = {{1, 0, 0, 1, 0, 0, 1, 0, 0},
                {1, 0, 0, 0, 0, 0, 0, 0, 0},
                {1, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 1, 0, 0, 1, 0, 0, 1, 0},
                {0, 1, 0, 0, 1, 0, 0, 0, 0},
                {0, 1, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 1, 0, 0, 1, 0, 0, 1},
                {0, 0, 1, 0, 0, 1, 0, 0, 1},
                {0, 0, 1, 0, 0, 1, 0, 0, 1}};
  while (b) {
    if (b & 1) 
      mul(ret, B);
    mul(B, B);
    b = b / 2;
  }
  ll arr[9] = {3, 1, 1, 3, 2, 1, 3, 3, 3};
  ll ans = 0ll;
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      ans = (ans + arr[j] * ret[i][j]) % MOD;
      //cout << ret[i][j] << " ";
    }
    //cout << endl;
  }
  return ans;
}

ll solve(ll x) {
  return powmod(x - 3);
}


int main() {
  ll n;
  cin >> n;
  cout << solve(n) << endl;
  return 0;
}
