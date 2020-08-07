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

int main() {
    NeedForSpeed;
    int t;
    cin >> t;
    while (t--) {
        vector<int> v(3);
        for (int i = 0; i < 3; i++)
            cin >> v[i];
        sort(all(v), [](int a, int b) {
            return a > b;
        });
        int ans = 0;
        int add = min(v[0] - v[1], v[2]);
        ans += add;
        v[0] -= add;
        v[2] -= add;
        if (v[2] == 0) {
            ans += min(v[1], v[0]);
        } else {
            add = v[0] - v[2];
            ans += add;
            v[0] -= add;
            if (v[0] & 1) {
                ans += (v[0] / 2)* 3 + 1;
            } else ans += (v[0] / 2) * 3;
        }
        cout << ans << endl;
    }
    
    return 0;
}