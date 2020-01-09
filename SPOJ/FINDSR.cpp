#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
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
const LL INF64 = 1e18;

const int N = 1e5 + 5;

string text;
int prefix[N];

int build() {
	prefix[0] = -1;
	for (int i = 1, j = -1; i < text.size(); i++) {
		while (j != -1 && text[j + 1] != text[i])
			j = prefix[j];
		if (text[j + 1] == text[i])
			j++;
		prefix[i] = j;
		// cout << prefix[i] << endl;
	}
	if (text.size() % (text.size() - prefix[text.size() - 1] - 1) == 0)
		return text.size() / (text.size() - prefix[text.size() - 1] - 1);
	return 1;
}

int main() {
	NeedForSpeed;
	while (cin >> text) {
		if (text == "*")
			break;
		cout << build() << endl;
	}
	return 0;
}
		