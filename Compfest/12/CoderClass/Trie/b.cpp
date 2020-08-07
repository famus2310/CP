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

struct Node {
  int next[26];
  int cnt = 0;
  bool is_leaf = false;
  
  Node() {
    for (int i = 0; i < 26; i++)
      next[i] = -1;
  }
};

vector<Node> trie(1);

void add(const string& s) {
  int v = 0;
  stack<int> st;
  for (char c : s) {
    int cur = c - 'a';  
    if (trie[v].next[cur] == -1) {
      trie[v].next[cur] = trie.size();
      trie.emplace_back();
    }
    trie[v].cnt++;
    st.push(v);
    v = trie[v].next[cur];
  }
  if (trie[v].is_leaf) {
    while (!st.empty()) {
      int now = st.top(); st.pop();
      trie[now].cnt--;
      v = now; 
    }
  } else {
    trie[v].cnt++;
    trie[v].is_leaf = true;
  }
}

int query(const string& s) {
  int v = 0;
  for (char c : s) {
    int cur = c - 'a';
    if (trie[v].next[cur] == -1)
      return 0;
    v = trie[v].next[cur];
  }
  return trie[v].cnt;
}

string s;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int type;
    cin >> type >> s;
    if (type == 1)
      add(s);
    else cout << query(s) << endl;
  } 
  return 0;
}
