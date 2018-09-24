#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define debug(x) cout << x << endl
#define fastio ios_base::sync_with_stdio(0), cin.tie(0)
#define PI acos(-1)
#define all(c) c.begin(), c.end()
const int MOD = 1e9 + 7;
const int INF = 1e9;
const LL INF64 = 1e18;

const int N = 1e5 + 5;

string now, title, author, journal, volume, pages, year, publisher, number, ans;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			cin.ignore();
			for (int j = 0; j < 10; j++) {
				getline(cin, now);
				cout << now << endl;
				int fi = now.find('{');
				int se = now.find('}');
				string tmp = now.substr(fi + 1, se - fi);
				if (now[0] == 't') 
					title = tmp;
				else if (now[0] == 'a')
					author = tmp;
				else if (now[0] == 'j')
					journal = tmp;
				else if (now[0] == 'n')
					number = tmp;
				else if (now[0] == 'p') {
					if (now[1] == 'a')
						pages = tmp;
					else if (now[1] == 'u')
						publisher = tmp;
				}
				else if (now[0] == 'v')
					volume = tmp;
				else if (now[0] == 'y')
					year = tmp;
			}
			ans.clear();
			stringstream ss(author);
			string name;
			int cnt = 0;
			while (ss >> name) {
				if (!ans.empty()) ans += ", ";
				if (cnt % 2 == 0) ans += name.substr(0, 2) + ".";
				else ans += name.substr(0, 1);
				cnt++;
			}
			ans += ".";
			ans += " " + title + ".";
			ans += " " + journal + ".";
			ans += " " + year + ";";
			ans += volume + "(" + number +"):" + pages +"."; 
			cout << ans << endl;
		}
	}
	return 0;
}
		