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

set<int> s;

int main() {
    NeedForSpeed;
    int t;
    cin >> t;
    while (t--) {
        s.clear();
        ll n;
        cin >> n;
        s.insert(0);
        for (int i = 1; i <= sqrt(n); i++) {
            s.insert(n / i);
            s.insert(i);
        }
        bool first = 1;
        cout << s.size() << endl;
        for (auto it : s) {
            if (!first)
                cout << " ";
            first = 0;
            cout << it;
        }
        cout << endl;
    }
    return 0;
}