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

string ans;

int main() {
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        ans.clear();
        
        int n;
        cin >> n;
        ans.resize(n);
        vector<pair<int, pair<int, int> > > act(n);
        for (int i = 0; i < n; i++) {
            act[i].first = i;
            cin >> act[i].second.first >> act[i].second.second;
        }
        sort(all(act), [](pair<int, pair<int, int> > p1, pair<int, pair<int, int> > p2) {
            if (p1.second.first != p2.second.first)
                return p1.second.first < p2.second.first;
            return p1.second.second < p2.second.second;
        });
        int c = -1;
        int j = -1;
        bool pos = true;
        for (pair<int, pair<int, int> > p : act) {
            if (p.second.first >= c) {
                c = p.second.second;
                ans[p.first] = 'C';
            }
            else if (p.second.first >= j) {
                j = p.second.second;
                ans[p.first] = 'J';
            } else {
                pos = false;
                break;
            }
        }
        cout << "Case #" << tc << ": ";
        if (!pos) 
            cout << "IMPOSSIBLE";
        else cout << ans;
        cout << endl;
    }
    return 0;
}