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

void do_flip(vector<int>& v) {
    for (auto &it : v) {
        it = 1 - it;
    }
}

int main() {
    int t, b;
    cin >> t >> b;
    for (int tc = 1; tc <= t; tc++) {
        vector<int> bits(b);
        int qno = 1;
        pair<int, int> same;
        pair<int, int> rev;
        bool fnd_same = false;
        bool fnd_rev = false;
        cout << "1" << endl;
        cin >> bits[0];
        qno++;
        cout << b << endl;
        cin >> bits[b - 1];
        if (bits[b - 1] == bits[0]) {
            same = {1, b};
            fnd_same = true;
        } else {
            rev = {1, b};
            fnd_rev = true;
        }
        int cur = 2; //compl b - cur + 1
        qno++;
        while (cur < b - cur + 1) {
            if ((qno % 10) == 1) {
                bool flipped = false;
                bool reversed = false;
                if (fnd_same) {
                    cout << same.first << endl;
                    int tmp;
                    cin >> tmp;
                    qno++;
                    if (tmp != bits[same.first - 1])
                        do_flip(bits);
                }
                if (fnd_rev) {
                    cout << rev.first << endl;
                    int tmp;
                    cin >> tmp;
                    qno++;
                    if (tmp != bits[rev.first - 1]) 
                        reverse(all(bits));
                }
                if (!fnd_rev || !fnd_same) {
                    cout << 1 << endl;
                    cin >> bits[0];
                    qno++;
                }
            } 
            cout << cur << endl;
            cin >> bits[cur - 1];
            cout << b - cur + 1 << endl;
            cin >> bits[b - cur];
            qno += 2;
            if (!fnd_rev && bits[cur - 1] != bits[b - cur]) {
                fnd_rev = true;
                rev.first = cur;
            }
            if (!fnd_same && bits[cur - 1] == bits[b - cur]) {
                fnd_same = true;
                same.first = cur;
            }
            cur++;
        }
        for (auto it : bits) {
            cout << it;
        }
        cout << endl;
        char c;
        cin >> c;
        if (c == 'Y')
            continue;
        else break;

    }
    return 0;
}