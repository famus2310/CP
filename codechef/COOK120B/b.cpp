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

struct node {
  node* left;
  node* right;
  bool leaf;
  node () {
    this->left = NULL;
    this->right = NULL;
    this->leaf = false;
  }
};

bool check(ll val, node* now, int bit) {
  if (bit == -1)
    return false;
  if (now == NULL)
    return false;
  if (now->leaf)
    return true;
  bool cur_ans = false;
  if ((1 << bit) & val) {
    cur_ans |= check(val, now->right, bit - 1);
  }
  cur_ans |= check(val, now->left, bit - 1);
  return cur_ans;
}

node* insert(ll val, node* now, int bit) {
  if (now == NULL) {
    now = new node();
  }
  if (bit == 0)
    now->leaf = 1;
  else if ((1 << (bit)) & val) {
    now->right = insert(val, now->right, bit - 1);
  } else now->left = insert(val, now->left, bit - 1);
  return now;  
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    node* root = NULL;
    int n;
    cin >> n;
    bool fnd = false;
    for (int i = 0; i < n; i++) {
      ll a;
      cin >> a;
      if (check(a, root, 62)) {
        fnd = true;
      }
      root = insert(a, root, 62);
    }
    if (!fnd)
      cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}
