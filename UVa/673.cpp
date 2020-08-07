#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
#define pb push_back
#define debug(x) cout << x << endl
#define fastio ios_base::sync_with_stdio(0), cin.tie(0)
#define PI acos(-1)
#define all(c) c.begin(), c.end()
#define SET(x, y) memset((x), y, sizeof(x))
const int MOD = 1e9 + 7;
const int INF = 1e9;
const LL INF64 = 1e18;

const int N = 1e5 + 5;

stack<char> st;

int main() {
	int t;
	scanf("%d", &t);
	cin.ignore();
	while (t--) {
		while (!st.empty()) st.pop();
		string s;
		getline(cin, s);
		bool error = 0;
		for (char c : s) {
			if (c == '(' || c == '[') st.push(c);
			else if (c == ')') {
				if (st.empty() || st.top() == '[') {
					error = 1;
					break;
				} else st.pop();
			} else if (c == ']') {
				if (st.empty() || st.top() == '(') {
					error = 1;
					break;
				} else st.pop();
			}
		}
		if (!st.empty()) error = 1;
		printf("%s\n", error == 1 ? "No" : "Yes");
	}
	return 0;
}
		