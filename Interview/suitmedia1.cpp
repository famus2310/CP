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

int countBits(int number, int bitNumber) {
    int zero = 0, one = 0;
    if (bitNumber > 1)
        return NULL;
    if (number == 0) {
        if (bitNumber == zero)
            return 1;
        else return 0;
    }
    while (number) {
        if (number & 1)
            one++;
        else zero++;
        number = number >> 1;
    }
    if (bitNumber == 0)
        return zero;
    return one;
}

void output(int x) {
    if (x == NULL) 
        cout << "null" << endl;
    else cout << x << endl;
}

int main() {
    output(countBits(13, 0));
    output(countBits(13, 1));
    output(countBits(13, 2));
    return 0;
}