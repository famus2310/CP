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

vector<int> root;

int findRoot(int now) {
  return root[now] == now ? now : root[now] = findRoot(root[now]);
}

void uni(int a, int b) {
  int root_a = findRoot(a);
  int root_b = findRoot(b);
  if (root_a != root_b) {
    root[root_a] = root_b;
  }
}

bool check(int a, int b) {
  return findRoot(a) == findRoot(b);
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    vector<pii> q;
    int n, k;
    cin >> n >> k;
    root.resize(n + 1);
    iota(all(root), 0);
    int a, b;
    string s;
    for (int i = 0; i < k; i++) {
      cin >> a >> s >> b;
      if (s == "!=")
        q.pb({a, b});
      else uni(a, b);
    }
    bool valid = true;
    for (auto it : q) {
      int x = it.first, y = it.second;
      if (check(x, y))
        valid = false;
    }
    if (valid)
      cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}
