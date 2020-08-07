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

int le[N], ri[N];

int main() {
  int n;
  cin >> n;
  vector<int> stock(n);  
  for (int &i : stock)
    cin >> i;
  stack<int> st;
  for (int i = 0; i < n; i++) {
    while (!st.empty() && stock[st.top()] >= stock[i])
      st.pop();
    if (st.empty())
      le[i] = -1;
    else le[i] = st.top();
    st.push(i);
  } 

  while (!st.empty())
    st.pop();

  for (int i = n - 1; i >= 0; i--) {
    while (!st.empty() && stock[st.top()] >= stock[i])
      st.pop();
    if (st.empty())
      ri[i] = -1;
    else ri[i] = st.top();
    st.push(i);
  }

  int q;
  cin >> q;
  while (q--) {
    int a;
    cin >> a;
    a--;
    int lo = le[a];
    int hi = ri[a];
    if (lo == -1 && hi == -1)
      cout << -1 << endl;
    else if (lo == -1)
      cout << hi + 1 << endl;
    else if (hi == -1)
      cout << lo + 1 << endl;
    else if (hi - a < a - lo)
      cout << hi + 1 << endl;
    else cout << lo + 1 << endl;
  }

  return 0;
}
