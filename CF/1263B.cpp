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

bool prefix[1000][10];
int outt[10];
int arr[10];

void output(int x) {
    string ret;
    for (int i = 0; i < 4; i++) {
        ret.pb('0' + x % 10);
        x /= 10;
    }

    reverse(all(ret));
    cout << ret << endl;
}

int main() {
    NeedForSpeed;
    int t;
    cin >> t;
    while (t--) {
        SET(prefix, 0);
        SET(outt, -1);
        int n;
        cin >> n;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            arr[i] = a;
            if (!prefix[a / 10][a % 10]) {
                outt[i] = arr[i];
                prefix[a / 10][a % 10] = 1;
            } else {
                ans++;
            }
        }
        cout << ans << endl;
        for (int i = 0; i < n; i++) {
            int a = arr[i];
            if (outt[i] == -1) {
                for (int j = 0; j < 10; j++) {
                    if (!prefix[a / 10][j]) {
                        outt[i] = (a / 10) * 10 + j;
                        prefix[a / 10][j] = 1;
                        break;
                    }     
                }
            }
            output(outt[i]);
        }
    }
    return 0;
}