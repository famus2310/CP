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
const int N = 1e6 + 5;

ll mainDiag[N][2]; //x = 1 atau y = 1
ll auxDiag[2 * N];
ll prefixAux[2 * N][2]; // genap / ganjil
ll n, m;

ll getAttackedMain(ll x) {
    return n + 1 - x;
}

ll getAttackedAux(ll x) {
    return min(x - 1, 2 * n + 1 - x);
}

int main() {
    SET(mainDiag, 0);
    SET(auxDiag, 0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        ll minMain = min(a, b);
        if (a - minMain == 0) { 
            mainDiag[b - minMain + 1][1] = 1;
        } else {
            mainDiag[a - minMain + 1][0] = 1;
        }
        auxDiag[a + b] = 1;
    }
    //hitung prefix paritas genap
    prefixAux[0][0] = 0;
    for (int i = 2; i <= 2 * n + 2; i += 2) {
        prefixAux[i][0] = prefixAux[i - 2][0] + auxDiag[i];
    }
    //hitung prefix paritas ganjil
    prefixAux[1][1] = 0;
    for (int i = 3; i <= 2 * n + 2; i += 2) {
        prefixAux[i][1] = prefixAux[i - 2][1] + auxDiag[i];
    }

    ll ans = n * n;
    //hitung attacked area untuk aux diagonal
    for (int i = 1; i <= 2 * n + 2; i++) {
        if (auxDiag[i])
            ans -= getAttackedAux(i);
    }
    //hitung attacked area sekaligus irisan untuk tiap main diagonal
    for (int i = 1; i <= n; i++) {
        if (mainDiag[i][0]) {
            ans -= getAttackedMain(i);
            if (i & 1) { //main nya ganjil, maka aux = main + 1 sampai 2 * n + 1 - main (genap)
                ans += prefixAux[2 * n + 1 - i][0] - prefixAux[i - 1][0];
            } else { //main nya genap, maka aux ganjil
                ans += prefixAux[2 * n + 1 - i][1] - (i - 1 < 0 ? 0ll : prefixAux[i - 1][1]);
                // debug(prefixAux[2 * n + 1 - i][1], prefixAux[i - 1][1]);
            }
        } 
        if (mainDiag[i][1]) {
            ans -= getAttackedMain(i);
            if (i & 1) { //main nya ganjil, maka aux = main + 1 sampai 2 * n + 1 - main (genap)
                ans += prefixAux[2 * n + 1 - i][0] - prefixAux[i - 1][0];
            } else { //main nya genap, maka aux ganjil
                ans += prefixAux[2 * n + 1 - i][1] - (i - 1 < 0 ? 0ll : prefixAux[i - 1][1]);
                // debug(prefixAux[2 * n + 1 - i][1], prefixAux[i - 1][1]);
            }
        }
        // debug(i, ans);
    }
    cout << ans << endl;


    return 0;
}