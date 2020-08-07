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

const int N = 2e5 + 5;

ll par[N];
ll root[35];

ll findRoot(ll x) {
    return par[x] == x ? x : par[x] = findRoot(par[x]);
}

void uni(ll a, ll b) {
    ll root_a = findRoot(a);
    ll root_b = findRoot(b);
    if (root_a != root_b) {
        par[root_a] = root_b;
    }
}

void init() {
    for (int i = 0; i < N; i++)
        par[i] = i;
}

int main() {
    NeedForSpeed;
    init();
    SET(root, -1);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (char c : s) {
            if (root[c - 'a'] == -1)
                root[c - 'a'] = i;
            else uni(i, root[c - 'a']);
        }
    }
    set<int> s;
    for (int i = 0; i < n; i++) {
        // cout << findRoot(i) << endl;
        s.insert(findRoot(i));
    }
    cout << s.size() << endl;
    return 0;
}