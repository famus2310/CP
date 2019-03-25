#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int n;
        scanf("%d", &n);
        const int INF = INT_MAX - (n<<1);
        int arr[n];
        for(int i = 0; i < n; i++){
            scanf("%d", arr + i);
        }
        if (n==2){
            if(arr[0]!=arr[1]) puts("0");
            else puts("-1");
            continue;
        }
        int dp[n][2][2];
        dp[0][0][0] = 0;
        dp[0][0][1] = 0;
        dp[0][1][0] = 1;
        dp[0][1][1] = 1;
        if(n&1){
            for(int i = 1; i < (n+1)/2; i++){
	            	dp[i][0][0] = INF;
		            dp[i][0][1] = INF;
		            dp[i][1][0] = INF;
		            dp[i][1][1] = INF;
                if(arr[i-1] < arr[i] && arr[n-i] < arr[n-i-1]){
                    dp[i][0][1] = min(dp[i][0][1], dp[i-1][0][0]);
                    dp[i][1][1] = min(dp[i][1][1], dp[i-1][1][0] + 1);
                }
                if(arr[i-1] > arr[i] && arr[n-i] > arr[n-i-1]){
                    dp[i][0][0] = min(dp[i][0][0], dp[i-1][0][1]);
                    dp[i][1][0] = min(dp[i][1][0], dp[i-1][1][1] + 1);
                }
                if(arr[i-1] < arr[n-i-1] && arr[n-i] < arr[i]){
                    dp[i][0][1] = min(dp[i][0][1], dp[i-1][1][0]);
                    dp[i][1][1] = min(dp[i][1][1], dp[i-1][0][0] + 1);
                }
                if(arr[i-1] > arr[n-i-1] && arr[n-i] > arr[i]){
                    dp[i][0][0] = min(dp[i][0][0], dp[i-1][1][1]);
                    dp[i][1][0] = min(dp[i][1][0], dp[i-1][0][1] + 1);
                }
            }
        } else {
            for(int i = 1; i < (n+1)/2; i++){
	            	dp[i][0][0] = INF;
		            dp[i][0][1] = INF;
		            dp[i][1][0] = INF;
		            dp[i][1][1] = INF;
                if(arr[i-1] < arr[i] && arr[n-i] > arr[n-i-1] && (arr[i] > arr[i+1] || i != (n+1)/2-1)){
                    dp[i][0][1] = min(dp[i][0][1], dp[i-1][0][0]);
                    dp[i][1][0] = min(dp[i][1][0], dp[i-1][1][1] + 1);
                }
                if(arr[i-1] > arr[i] && arr[n-i] < arr[n-i-1] && (arr[i] < arr[i+1] || i != (n+1)/2-1)){
                    dp[i][0][0] = min(dp[i][0][0], dp[i-1][0][1]);
                    dp[i][1][1] = min(dp[i][1][1], dp[i-1][1][0] + 1);
                }
                if(arr[i-1] < arr[n-i-1] && arr[n-i] > arr[i] && (arr[i] < arr[i+1] || i != (n+1)/2-1)){
                    dp[i][0][0] = min(dp[i][0][0], dp[i-1][1][1]);
                    dp[i][1][1] = min(dp[i][1][1], dp[i-1][0][0] + 1);
                }
                if(arr[i-1] > arr[n-i-1] && arr[n-i] < arr[i] && (arr[i] > arr[i+1] || i != (n+1)/2-1)){
                    dp[i][0][1] = min(dp[i][0][1], dp[i-1][1][0]);
                    dp[i][1][0] = min(dp[i][1][0], dp[i-1][0][1] + 1);
                }
            }
        }
        int ans = INF;
        ans = min(ans, dp[(n+1)/2-1][0][0]);
        ans = min(ans, dp[(n+1)/2-1][0][1]);
        ans = min(ans, dp[(n+1)/2-1][1][0]);
        ans = min(ans, dp[(n+1)/2-1][1][1]);
        if(ans == INF) ans = -1;
        printf("%d\n",ans);
    }
}