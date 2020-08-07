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
vector<char> in;
vector<char> out;

bool valid(int i, int j) {
  return out[i] == 'Y' && in[j] == 'Y';
}

int main() {
  int t;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    int n;
    cin >> n;
    vector<vector<char> > can(n, vector<char>(n, 'N'));
    in.resize(n); out.resize(n);
    for (auto &it : in)
      cin >> it;
    for (auto &it : out)
      cin >> it;
    for (int i = 0; i < n; i++) {
      can[i][i] = 'Y';
      for (int j = i - 1; j >= 0; j--) {
        if (valid(j + 1, j))
          can[i][j] = 'Y';
        else break;
      }
      for (int j = i + 1; j < n; j++) {
        if (valid(j - 1, j))
          can[i][j] = 'Y';
        else break;
      }
    }
    cout << "Case #" << tc << ":" << endl;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) 
        cout << can[i][j];
      cout << endl;
    }
  }
  return 0;
}
