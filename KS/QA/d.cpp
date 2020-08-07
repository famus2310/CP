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
    node* child[26];
    int cnt;
    node() {
        cnt = 1;
        for (int i = 0; i < 26; i++)
            child[i] = NULL;
    }
};

node* ins(node* root, const string& s, int index) {
    if (index == s.size())
        return NULL;
    if (root != NULL)
        root->cnt++;
    else 
        root = new node();
    root->child[s[index] - 'A'] = ins(root->child[s[index] - 'A'], s, index + 1);
    return root;
}

//ans, used
pair<int, int> solve(node* root, int len) {
    if (root == NULL)
        return {0, 0};
    pair<int, int> cur = {0, 0};
    for (int i = 0; i < 26; i++) {
        pair<int, int> tmp = solve(root->child[i], len + 1);
        cur.first += tmp.first;
        cur.second += tmp.second;
    }
    

}

int main() {
    int t;
    cin >> t;
    while (t--) {

    }
    return 0;
}