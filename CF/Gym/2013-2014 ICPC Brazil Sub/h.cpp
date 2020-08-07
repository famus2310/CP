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
const int MOD = 1e6;
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

ll mulmod(ll a, ll b) {
  return ((a % MOD) * (b % MOD)) % MOD;
}

ll addmod(ll a, ll b) {
  return ((a % MOD) + (b % MOD)) % MOD;
}

void mul(ll A[2][2], ll B[2][2]) {
  ll C[2][2];
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      C[i][j] = 0;
      for (int k = 0; k < 2; k++) {
        C[i][j] = addmod(C[i][j], mulmod(A[i][k], B[k][j]));
      }
    }
  }
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
     A[i][j] = C[i][j]; 
}

ll powmod(ll b, ll k, ll l) {
  ll ret[2][2];
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
      ret[i][j] = i == j;
  ll A[2][2] = {{k, l}, {1, 0}};
  while (b) {
    if (b & 1) mul(ret, A);
    b = b / 2;
    mul(A, A);
  }
  return addmod(mulmod(ret[0][0], k), ret[0][1]);
}

string solve(ll n, ll k, ll l) {
  ll ret;
  if (n == 0)
    ret = 1;
  else if (n == 5)
    ret = k;
  else ret = powmod(n / 5 - 1, k, l);
  string ans = to_string(ret);
  while (ans.size() < 6) {
    ans = "0" + ans;
  }
  return ans;
}

int main() {
  ll n, k, l;
  cin >> n >> k >> l;
  cout << solve(n, k, l) << endl;
  return 0;
}
