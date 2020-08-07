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
const int N = 100 + 5;

map<pii, bool> mp;

int main() {
  vector<vector<int> > matrix;
  matrix.assign(N, vector<int>(N, 0));
  for (int i = 1; i < N; i++) {
    for (int j = i; j < N; j++) {
      int g = __gcd(i, j);
      int a = i / g;
      int b = j / g;
      debug(a, b);
      if (mp.find({a, b}) == mp.end())
        matrix[i][j] = 1;
      mp[{a, b}] = 1;
    }
  }
  for (int i = 1; i < N; i++) {
    for (int j = 1; j < N; j++) {
      cout << matrix[i][j];
    }
    cout << endl;
  }
  return 0;
}
