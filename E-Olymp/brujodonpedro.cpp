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

const int NMAX = 1e5 + 5;

int arr[105];

int main() {
arr[1] = 0;
arr[2] = 1;
arr[3] = 2;
arr[4] = 2;
arr[5] = 3;
arr[6] = 3;
arr[7] = 4;
arr[8] = 3;
arr[9] = 4;
arr[10] = 4;
arr[11] = 5;
arr[12] = 4;
arr[13] = 5;
arr[14] = 5;
arr[15] = 5;
arr[16] = 4;
arr[17] = 5;
arr[18] = 5;
arr[19] = 6;
arr[20] = 5;
arr[21] = 6;
arr[22] = 6;
arr[23] = 6;
arr[24] = 5;
arr[25] = 6;
arr[26] = 6;
arr[27] = 6;
arr[28] = 6;
arr[29] = 7;
arr[30] = 6;
arr[31] = 7;
arr[32] = 5;
arr[33] = 6;
arr[34] = 6;
arr[35] = 7;
arr[36] = 6;
arr[37] = 7;
arr[38] = 7;
arr[39] = 7;
arr[40] = 6;
arr[41] = 7;
arr[42] = 7;
arr[43] = 7;
arr[44] = 7;
arr[45] = 7;
arr[46] = 7;
arr[47] = 8;
arr[48] = 6;
arr[49] = 7;
arr[50] = 7;
arr[51] = 7;
arr[52] = 7;
arr[53] = 8;
arr[54] = 7;
arr[55] = 8;
arr[56] = 7;
arr[57] = 8;
arr[58] = 8;
arr[59] = 8;
arr[60] = 7;
arr[61] = 8;
arr[62] = 8;
arr[63] = 8;
arr[64] = 6;
arr[65] = 7;
arr[66] = 7;
arr[67] = 8;
arr[68] = 7;
arr[69] = 8;
arr[70] = 8;
arr[71] = 9;
arr[72] = 7;
arr[73] = 8;
arr[74] = 8;
arr[75] = 8;
arr[76] = 8;
arr[77] = 8;
arr[78] = 8;
arr[79] = 9;
arr[80] = 7;
arr[81] = 8;
arr[82] = 8;
arr[83] = 8;
arr[84] = 8;
arr[85] = 8;
arr[86] = 8;
arr[87] = 9;
arr[88] = 8;
arr[89] = 9;
arr[90] = 8;
arr[91] = 9;
arr[92] = 8;
arr[93] = 9;
arr[94] = 9;
arr[95] = 9;
arr[96] = 7;
arr[97] = 8;
arr[98] = 8;
arr[99] = 8;
arr[100] = 8;
	int n;
	//freopen("output.out", "w", stdout);
	cin >> n;
	while (n--) {
		int m;
		cin >> m;
		cout << arr[m] * 3 << endl;
	}
	return 0;
}