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
const int N = 1e6 + 5;

struct node {
  ll val, cur;
  bool operator<(const node& other) const {
    return val > other.val;
  }
};

vector<deque<ll> > arr;
priority_queue<node> pq;
ll dp[N][2];
bool done[N]; //i to i + 1

int main() {
  int n;
  cin >> n;
  vector<pair<ll, ll> > v(n);
  for (auto &it : v) 
    cin >> it.first >> it.second;
  sort(all(v));
  ll idx = 0;
  arr.pb(deque<ll>(v[0].second));
  for (int i = 1; i < v.size(); i++) {
    if (v[i].first != v[i - 1].first) {
      arr.pb(deque<ll>(v[i].second));
    } else {
      arr.back().pb(v[i].second);
    }
  }
  for (int i = 1; i < arr.size(); i++) {
    pq.push({abs(arr[i - 1].back() - arr[i].front()), i - 1});
    pq.push({abs(arr[i - 1].front() - arr[i].back()), i - 1});
  }
  ll ans = 0;
  while (!pq.empty()) {
    node now = pq.top(); pq.pop();
    if (!done[now.cur]) {
      done[now.cur] = true;
      ans += now.val;
    }    
  }
  cout << ans << endl;
  return 0;
}
