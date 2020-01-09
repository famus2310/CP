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

const int N = 1e5 + 5;

priority_queue<pair<ll, ll> > pq; //cost, idx
ll cost[N];
ll filled[N];
ll maxCap[N];

int main() {
    NeedForSpeed;
    int t;
    cin >> t;
    while (t--) {
        ll n, c, d;
        cin >> n >> c >> d;
        ll ans = 0ll;
        for (int i = 0; i < n; i++) {
            cin >> cost[i];
            ans += d * cost[i];
            filled[i] = d;
            pq.push({cost[i], i});
        }

        while (!pq.empty()) {
            pair<ll, ll> now = pq.top(); pq.pop();
            if (filled[now.second] == c)
                continue;
            for (int i = now.second + 1; i < n && filled[now.second] < c; i++) {
                if (cost[i] > now.first)
                    break;
                ll added = min(c - filled[now.second], filled[i]);
                filled[now.second] += added;
                ans += now.first * added;
                ans -= cost[i] * added;
            }
            // cout << ans << endl;
        }
        while (!pq.empty()) 
            pq.pop();
        cout << ans << endl;
    }
    return 0;
}