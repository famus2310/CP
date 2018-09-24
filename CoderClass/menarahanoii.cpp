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

int arr[N];
int tail[N];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);
	reverse(arr, arr + n);
	int length = 0;
	tail[0] = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] < tail[0]) 
			tail[0] = arr[i];
		else if (arr[i] > tail[length]) {
			length++;
			tail[length] = arr[i];
		} else {
			int lb = lower_bound(tail, tail + length + 1, arr[i]) - tail;
			// cout << i << " " << lb  - 1	<< endl;
			tail[lb] = arr[i];
		}
	}
	printf("%d\n", length + 1);
	return 0;
}
		