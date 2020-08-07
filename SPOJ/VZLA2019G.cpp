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
ll arr[42] = {
	0,
    1,
		2,
		3,
		4,
		5,
		6,
		7,
		8,
		9,
		153,
		370,
		371,
		407,
		1634,
		8208,
		9474,
		54748,
		92727,
		93084,
		548834,
		1741725,
		4210818,
		9800817,
		9926315,
		24678050,
		24678051,
		88593477,
		146511208,
		472335975,
		534494836,
		912985153,
		4679307774,
		32164049650,
		32164049651,
		40028394225,
		42678290603,
		44708635679, 
		49388550606,
		82693916578,
		94204591914,
		28116440335967
};

int main() {
	NeedForSpeed;
	ll t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		ll n;
		cin >> n;
		ll lb = lower_bound(arr, arr + 42, n) - arr;
		cout << "Case #" << tc << ": " << arr[lb] << endl;
	}
	return 0;
}
		