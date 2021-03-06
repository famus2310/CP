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

int main() {
  int t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    vector<int> v(n);
    for (auto &it : v)
      cin >> it;
    int ptr1 = 1;
    int ptr2 = n - 2;
    int good1 = 0;
    int good2 = n - 1;
    while (ptr1 <= ptr2) {
      if (v[ptr1] >= v[ptr1 - 1])
        ptr1++;
      else if (v[ptr2] >= v[ptr2 + 1])
        ptr2--;
      else {
        good1 = ptr1; 
        ptr1++;
      }
    }
    cout << good1 << endl;
  }
  return 0;
}
