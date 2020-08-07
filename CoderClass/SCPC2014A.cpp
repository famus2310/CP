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

string arr[10005];

int editDistDP(string str1, string str2, int m, int n, int r, int ins, int d)
{
    // Create a table to store results of subproblems
    int dp[m+1][n+1];
 
    // Fill d[][] in bottom up manner
    for (int i=0; i<=m; i++)
    {
        for (int 	j=0; j<=n; j++)
        {
            // If first string is empty, only option is to
            // isnert all characters of second string
            if (i==0)
                dp[i][j] = j;  // Min. operations = j
 
            // If second string is empty, only option is to
            // remove all characters of second string
            else if (j==0)
                dp[i][j] = i; // Min. operations = i
 
            // If last characters are same, ignore last char
            // and recur for remaining string
            else if (str1[i-1] == str2[j-1])
                dp[i][j] = dp[i-1][j-1];
 
            // If the last character is different, consider all
            // possibilities and find the minimum
            else
            {	
            	int mn1 = INF, mn2 = INF, mn3 = INF;
            	if (r > 0) mn1 = dp[i - 1][j] + 2;
            	if (ins > 0) mn2 = dp[i][j - 1] + 1;
            	if (d > 0) mn3 = dp[i - 1][j] + 1;
            	dp[i][j] = min(mn1, min(mn2, mn3));
                // dp[i][j] = min(dp[i][j-1] + 2,  // Insert
                //                    dp[i-1][j] + 1,  // Remove
                //                    dp[i-1][j-1] + 1); // Replace
            }
        }
    }
 
    return dp[m][n];
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		string s1;
		cin >> s1;
		int q;
		scanf("%d", &q);
		int mn = INF;
		string ans;
		for (int i = 0; i < q; i++) {
			cin >> s2;
			arr[i] = s2;
		}
		int c, r, ins, d;
		scanf("%d %d %d %d", &c, &r, &ins, &d);
		for 
	}
	return 0;
}
		