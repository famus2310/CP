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

bool resolved[15];

struct node {
  string s, num;
};

int main() {
  int t;
  cin >> t;
  int poss[35];
  for (int i = 0; i < 35; i++) 
    poss[i] = (1 << 10) - 1;
  queue<node> q;
  for (int tc = 1; tc <= t; tc++) {
    int digit;
    cin >> digit;
    for (int i = 0; i < (int)1e4; i++) {
      node x;
      cin >> x.num >> x.s;
      if (x.num.size() != x.s.size()) {
        x.num = "";
        for (int j = 0; j < x.s.size(); j++)
          x.num.pb('9');
      }  
      q.push(x); 
    }
    //resolve
    while (!q.empty()) {
      node now = q.front();
      cout << now.s << endl;
      q.pop();
      for (int i = 0; i < 10; i++) {
        if (resolved[i]) {
          poss[now.s[0] - 'A'] &= ((1 << 10) - 1) - (1 << i);
        }
      }
      while (now.s.size() && __builtin_popcount(poss[now.s[0] - 'A']) == 1) {
        int cur = 0;
        int mask = poss[now.s[0] - 'A'];
        while (((1 << cur) & mask) == 0)
          cur++;
        now.s = now.s.substr(1, now.s.size() - 1);
        if ((now.num[0] - '0') == cur)
          now.num = now.num.substr(1, now.num.size() - 1);
        else {
          int n = now.num.size();
          now.num = "";
          for (int i = 0; i < n - 1; i++)
            now.num.pb('9');
        }
      } 
      if (now.s.size() == 0)
        continue;
      if (now.num[0] - '0' == 0) {
        poss[now.s[0] - 'A'] = 1;
        resolved[0] = 1;
        continue;
      }
      int mx = now.num[0] - '0';
      poss[now.s[0] - 'A'] &= (1 << (mx + 1)) - 2;
      if (__builtin_popcount(poss[now.s[0] - 'A']) == 1) {
        int cur = 0;
        int mask = poss[now.s[0] - 'A'];
        while (((1 << cur) & mask) == 0)
          cur++;
        resolved[cur] = 1;
      }
      cout << endl;
      cout << endl;
      cout << " NEW " << endl;
      for (int i = 0; i < 35; i++) {
        for (int j = 0; j < 10; j++) {
          if (poss[i] & (1 << j))
            cout << 1;
          else cout << 0;
        }
        cout << endl;
      }
      q.push(now);
    }
  }

  return 0;
}
