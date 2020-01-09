#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
#define pb push_back
#define debug(x) cout << x << endl
#define NeedForSpeed ios_base::sync_with_stdio(0), cin.tie(0)
#define PI acos(-1)
#define all(c) c.begin(), c.end()
#define SET(x, y) memset((x), y, sizeof(x))
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll INF64 = 1e18;

const int N = 2e6 + 5;

struct node {
    ll cnt;
    node* nextChar[27];
    node () {
        cnt = 0;
        for (int i = 0; i < 27; i++) 
            nextChar[i] = NULL;
    };
};

node* root;

void add(const string& s) {
    node* now = root;
    for (int i = 0; i < s.size(); i++) {
        if (now->nextChar[s[i] - 'a'] == NULL) {
            node* cur = new node();
            now->nextChar[s[i] - 'a'] = cur;
            now = cur;
        } else {
            now = now->nextChar[s[i] - 'a'];
        }
        now->cnt++;
    }
}

ll query(const string& s, ll now, node* cur) {
    
    if (now == s.size()) {
        return cur->cnt;
    }
    if (cur->nextChar[s[now] - 'a'] == NULL)
        return 0;
    return query(s, now + 1, cur->nextChar[s[now] - 'a']);
}

string inp;

int main() {
    NeedForSpeed;
    root = new node();
    ll n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> inp;
        add(inp);
    }
    while (m--) {
        cin >> inp;
        cout << query(inp, 0, root) << endl;
    }
    return 0;
}