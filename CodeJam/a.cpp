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

int main() { 
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        ll n;
        cin >> n;
        int sum = 0;
        vector<vector<int> > mat(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int a;
                cin >> a;
                if (i == j)
                    sum += a;
                mat[i][j] = a;
            }
        }
        int row = 0;
        int col = 0;
        for (int i = 0; i < n; i++) {
            vector<bool> v(n + 1, false);
            for (int j = 0; j < n; j++) {
                if (v[mat[i][j]]) {
                    row++;
                    break;
                }
                v[mat[i][j]] = true;
            }
        }
        for (int j = 0; j < n; j++) {
            vector<bool> v(n + 1, false);
            for (int i = 0; i < n; i++) {
                if (v[mat[i][j]]) {
                    col++;
                    break;
                }
                v[mat[i][j]] = true;
            }
        }
        cout << "Case #" << tc << ": " << sum << " " << row << " " << col << endl;
    }
    return 0;
}