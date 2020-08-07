#include <bits/stdc++.h>
using namespace std;

int main(){
    string a;
    int t;
    cin >> t;
    while(t--){
        cin >> a;
        map<char,int> counter;
        for (int i = 0; i < a.size(); i++){
            counter[a[i]]++;
        }
        int ans = 0;
        int len = a.size();
        for (auto it = counter.begin(); it!=counter.end(); it++){
            if (it->second&1) ans++;
        }
        if (len & 1) {
            if (ans == 1) puts("1");
            else puts("-1");
        } else {
            if (ans == 0) puts("1");
            else puts("-1");
        }
    }
    return 0;
}	