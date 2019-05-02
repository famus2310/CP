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
const int INF = 1e9 + 5;
const LL INF64 = 1e18;

const int N = 1e5 + 5;

int arr1[2 * N];
int arr2[2 * N];
int arr3[2 * N];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;
		arr1[i] = c - 'a';
		// cout << arr1[i] << " ";
	}
	// cout << endl;
	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;
		arr2[i] = c - 'a';
		// cout << arr2[i] << " ";
	}
	// cout << endl;
	int carry = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (carry) {
			arr2[i]--;
			carry = 0;
		}
		if (arr2[i] < arr1[i]) {
			carry = 1;
			arr2[i] += 26;
		}
		arr3[i] = arr2[i] - arr1[i];
		// cout << arr3[i] << endl;
	}
	carry = 0;
	for (int i = 0; i < n; i++) {
		if (carry) {
			arr3[i] = arr3[i] + 26;
			carry = 0;
		}
		// cout << arr3[i] << endl;
		if (arr3[i] & 1)
			carry = 1;
		arr3[i] = arr3[i] / 2;
		// cout << arr3[i] << endl;
	}
	carry = 0;
	for (int i = n - 1; i >= 0; i--) {
		// cout << arr1[i] << " + " << arr3[i] << endl;
		if (carry) {
			arr1[i] = arr1[i] + 1;
			carry = 0;
		}
		arr1[i] = arr1[i] + arr3[i];
		if (arr1[i] > 25) {
			arr1[i] -= 26;
			carry = 1;
		}
		// cout << arr1[i] << endl;
	}
	for (int i = 0; i < n; i++) {
		cout << (char)(arr1[i] + 'a');
	}
	cout << endl;
	return 0;
}
		