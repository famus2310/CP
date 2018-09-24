#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define debug(x) cout << x << endl
#define fastio ios_base::sync_with_stdio(0), cin.tie(0)
#define PI acos(-1)
#define all(c) c.begin(), c.end()
#define pii pair<int, int>
#define piii pair<int, int>
const int MOD = 1e9 + 7;
const int INF = 1e9;
const LL INF64 = 1e18;

const int N = 1e5 + 5;

int arr[1005];
int pos[1005];
int tmp[1005];

void rev(int idx) {
	int lo = 1;
	int hi = idx;
	while (hi > lo) {
		swap(arr[hi], arr[lo]);
		hi--;
		lo++;
	}
}

int findMax(int idx) {
	int ret = 1;
	for (int i = 2; i <= idx; i++) {
		if (arr[i] > arr[ret])
			ret = i;
	}
	return ret;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		memset(arr, 0, sizeof arr);
		int flip[1005];
		int step = 0;
		int n, i, j, k, tmp;
		scanf("%d", &n);
		for (i = 0; i < n; i++) {
			scanf("%d", arr + i);
		}
		for(i = 0; i < n; i++) {
      int idx = n-i-1;
      for(j = 0; j < n-i; j++) {
        if(arr[idx] < arr[j])
          idx = j;
      }
      if(idx == n-i-1)
        continue;
      if(idx) {
        flip[step++] = n-idx;
        for(j = 0, k = idx; j < k; j++, k--)
          tmp = arr[j], arr[j] = arr[k], arr[k] = tmp;
      }
      flip[step++] = i+1;
      for(j = 0, k = n-i-1; j < k; j++, k--)
        tmp = arr[j], arr[j] = arr[k], arr[k] = tmp;
		}
		for(i = 0; i < step; i++)
      printf("%d ", flip[i]);
		puts("0");
	}
	return 0;
}
