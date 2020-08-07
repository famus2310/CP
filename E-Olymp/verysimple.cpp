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


map<pair<LL, LL>, LL> mp;

vector<LL> arr(3);
LL n, k;

int main() {
	LL tmp0, tmp1;
	cin >> n >> tmp0 >> tmp1 >> k;
	arr[0] = tmp0;
	arr[1] = tmp1;
	arr[2] = ((((arr[0] % n) * (arr[0] % n)) % n) + ((arr[1] % n) * (arr[1] % n)) % n) % n;
	mp[{arr[1], arr[0]}] = 1;
	LL a = 2, b = 1;
	while (mp[{arr[a], arr[b]}] == 0) {
		//cout << arr[a] << " " << arr[b] << endl;
		mp[{arr[a], arr[b]}] = a;
		a++;
		b++;
		arr.pb(((((arr[a - 2] % n) * (arr[a - 2] % n)) % n) + ((arr[a - 1] % n) * (arr[a - 1] % n)) % n) % n);
	}
	//cout << arr[0] << " " << arr[1] << " " << arr[2] << " " << arr[3] << endl;
	//cout <<arr[a] << " " << arr[b] << endl;
	//debug(a);
	if (k <= a) cout << arr[k] << endl;
	else {
		LL lower = mp[{arr[a], arr[b]}];
		LL upper = a;
		//debug(lower); debug(upper);
		k -= upper;
		k %= (upper - lower);
		cout << arr[lower + k] << endl;
	}
	return 0;
}
		