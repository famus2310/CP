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
const int N = 3e3 + 5;

ll row[N];
ll col[N];
bool used[N * N];

int main() {
  ll l, c;
  cin >> l >> c;
  bool valid = true;
  vector<vector<ll> > grid(l, vector<ll>(c));
  for (int i = 0; i < l; i++) {
    for (int j = 0; j < c; j++) {
      cin >> grid[i][j];
      if (used[grid[i][j]])
        valid = false;
      used[grid[i][j]] = 1;
    }
  }
  if (!valid) {
    cout << "*" << endl;
    return 0;
  }
  for (int i = 0; i < l; i++) {
    vector<ll> tmp = grid[i];
    sort(all(tmp));
    row[i] = (grid[i][0] - 1) / c;
    if (c > 1 && tmp[0] % c != 1) {
      cout << "*" << endl;
      return 0;
    }
    for (int j = 1; j < c; j++) {
      if (tmp[j] != tmp[j - 1] + 1) {
        cout << "*" << endl;
        return 0;
      }
    }
  }
  for (int j = 0; j < c; j++) {
    vector<ll> tmp;
    for (int i = 0; i < l; i++) {
      tmp.pb(grid[i][j]);
    }
    sort(all(tmp));
    if (tmp[0] <= c) {
      col[j] = tmp[0] - 1;
    }
    for (int i = 1; i < l; i++) {
      if (tmp[i] != tmp[i - 1] + c) {
        cout << "*" << endl;
        return 0;
      }
    }
  }
  ll ans = 0ll;
  for (int i = 0; i < l; i++) {
    while (row[i] != i) {
      swap(row[i], row[row[i]]);
      ans++;
    }
  }
  for (int i = 0; i < c; i++) {
    while (col[i] != i) {
      swap(col[i], col[col[i]]);
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
