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

int main() {
	NeedForSpeed;
	string s;
	cin >> s;
	sort(all(s));
	reverse(all(s));
	deque<char> dq;
	for (int i = 0; i < s.size(); i++) {
		dq.pb(s[i]);
		while (dq.size() >= 2) {
			char now = dq.back();
			if (now == 'z')
				break;
			dq.pop_back();
			// cout << dq.back() << " " << now << endl;
			if (dq.back() == now) {
				dq.pop_back();
				dq.push_back(now + 1);
			}
			else {
				dq.push_back(now);
				break;
			}
		}
	}
	for (auto it : dq)
		cout << it;
	cout << endl;
	return 0;
}
		