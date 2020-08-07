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

typedef pair<int,int >point;
struct event {
  point p1,p2;
  int type;
  event() {};
  event(point p1,point p2, int type) : p1(p1), p2(p2),type(type) {};  
  bool operator<(const event &other) const {
    if (p1.second != other.p1.second)
      return p1.second < other.p1.second;
    return type < other.type;
  }
};

int n, e;
event events[100005];
set<point> s;

ll solve() {
  ll ret = 0ll;
  for (int i = 0;i < e; i++) {
    event c = events[i];
    if (c.type == 0) s.insert(c.p1);
    else if (c.type == 1) s.erase(c.p2);
    else {
      for (auto it = s.lower_bound(make_pair(c.p1.first, -1)); it != s.end() && it->first <= c.p2.first; it++) {
        ret++;
      }
    }
  }
  return ret;
}

int main () {
  cin >> n; 
  e = 0;
  int p1x, p1y, p2x, p2y;
  for (int i = 0;i < n; ++i) {
    cin >> p1x >> p1y >> p2x >> p2y;
    if (p1x > p2x)
      swap(p1x, p2x);
    if (p1y > p2y)
      swap(p1y, p2y);
    if (p1x == p2x) {
        events[e++] = event(make_pair(p1y,p1x), make_pair(p2y,p2x), 2);
    }
    else {
      events[e++] = event(make_pair(p1y,p1x), make_pair(p2y,p2x), 0);
      events[e++] = event(make_pair(p2y,p2x), make_pair(p1y,p1x), 1);
    }
  }
  sort(events, events + e);
  cout << solve() << endl;
  return 0;
}
