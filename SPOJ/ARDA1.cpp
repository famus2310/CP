#include <bits/stdc++.h>
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

ll n1, n2;
ll m1, m2;

string pat[305];
string text[2005];

ll prefix[2005][305];

void build() {
	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < m1; j++) {
			int len1 = pat[i].size();
			int len2 = text[j].size();
			int len = len1 + len2;
			
		}
	}
}

int main() {
	NeedForSpeed;

	return 0;
}
		