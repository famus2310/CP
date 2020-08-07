#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int t, n, x, y;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    for(int tc = 1; tc <= t; tc++){
        unordered_map<int, int> pointx, pointy;
        map<pair<int, int>, int> mp;
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> x >> y;
            pointx[x]++;
            pointy[y]++;
            mp[{x, y}]++;
        }
        int mx = 0;
        for(auto it = mp.begin(); it != mp.end(); it++){
            x = (it->first).first;
            y = (it->first).second;
            int tempx = pointx[x];
            int tempy = pointy[y];
            mx = max(tempx + tempy - 2*(mp[{x,y}]), mx);
            //cout << tempx << " " << tempy << " " << mx << x + y - 2*(mp[{x, y}]) << endl;
        }
        cout << "Case #" << tc << ": " << mx << endl;
    }
    return 0;
