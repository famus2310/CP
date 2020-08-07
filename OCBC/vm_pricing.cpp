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

double interpolate(double x, double y1, double y2, double x1, double x2) {
  return y1 + (x - x1) * (y2 - y1) / (x2 - x1);
}

string solve(int n, int m, const vector<double>& price, const vector<double>& instance) {
  stringstream ss;
  if (m == 1)
    ss << fixed << setprecision(2) << price[0] << endl;
  else if (n < instance[0]) 
    ss << fixed << setprecision(2) << interpolate(n, price[0], price[1], instance[0], instance[1]) << endl;
  else if (n > instance.back())
    ss << fixed << setprecision(2) << interpolate(n, price[m - 2], price[m - 1], instance[m - 2], instance[m - 1]) << endl;
  else {
    int idx = lower_bound(all(instance), n) - instance.begin();
    if (instance[idx] == n)
      ss << fixed << setprecision(2) << price[idx] << endl;
    else ss << fixed << setprecision(2) << interpolate(n, price[idx - 1], price[idx], instance[idx - 1], instance[idx]) << endl;
  }
  return ss.str();
}
  

int main() {
  int n, m;
  cin >> n >> m;
  vector<double> instanceTemp(m), priceTemp(m);
  vector<double> instance, price;
  for (double &i : instanceTemp)
    cin >> i;
  cin >> m;
  for (double &i : priceTemp)
    cin >> i;
  for (int i = 0; i < m; i++) {
    if (priceTemp[i] <= 0)
      continue;
    instance.pb(instanceTemp[i]);
    price.pb(priceTemp[i]);
  }
  m = instance.size();
  cout << solve(n, m, price, instance) << endl;
  return 0;
}
