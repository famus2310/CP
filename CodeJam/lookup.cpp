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

set<vector<int> > s;

int n = 4;

bool check(int a, int b, int c) {
    return a != b && a != c && b != c;
}

bool check(vector<int> v) {
    return v[0] != v[1] && v[0] != v[2] && v[1] != v[2];
}

vector<vector<int> > perm(n, vector<int>(n));

void solve(int rec) {
    if (rec == n) {
        bool test = true;
        for (int i = 0; i < n; i++) {
            vector<int> tmp;
            for (int j = 0; j < n; j++) {
                tmp.pb(perm[i][j]);
            }
            if (!check(tmp))
                test = false;
        }
        for (int j = 0; j < n; j++) {
            vector<int> tmp;
            for (int i = 0; i < n; i++) {
                tmp.pb(perm[i][j]);
            }
            if (!check(tmp))
                test = false;
        }
        if (test) {
            vector<int> tmp;
            for (int i = 0; i < perm.size(); i++) {
                for (int j = 0; j < perm[i].size(); j++) {
                    if (i == j)
                        tmp.pb(perm[i][j]);
                    // cout << perm[i][j] << " ";
                }
                // cout << endl;
            }
            sort(all(tmp));
            // debug(tmp);
            s.insert(tmp);
            // cout << endl;
        }
    } else {
        do {
            solve(rec + 1);
        } while (next_permutation(all(perm[rec])));
    }
}

int main() {
    for (int i = 0; i < perm.size(); i++) {
        for (int j = 0; j < perm[i].size(); j++) {
            perm[i][j] = j + 1;
        }
    }
    solve(0);
    for (auto it : s) {
        debug(it);
        cout << endl;
    }
    return 0;
}