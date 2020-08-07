#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define debug(x) cout << x << endl
#define 	fastio ios_base::sync_with_stdio(0), cin.tie(0)
#define PI acos(-1)
#define all(c) c.begin(), c.end()
const int MOD = 1e9 + 7;
const int INF = 1e9;
const LL INF64 = 1e18;

const int N = 1e5 + 5;

inline void scanint(int &x)
{   register int c = getchar_unlocked();
     x = 0;
     int neg = 0;
     for(;((c<48 || c>57) && c != '-');c = getchar_unlocked());
     if(c=='-') {neg=1;c=getchar_unlocked();}
     for(;c>47 && c<58;c = getchar_unlocked()) {x = (x<<1) + (x<<3) + c - 48;}
     if(neg) x=-x;
 	 if(neg) x=-x;
}

inline void getDouble(double &x) {
    char ch;
    bool seen = false;
    bool sign = false;
    char values[10];
    double result =0.;
    bool beforeDot = true;
    int beforeLength = 0;
    double multiplier;

    while(ch = getchar_unlocked()) {
        if(ch == '-') {
            sign = true;
            continue;
        }
        if(ch == ' ' || ch == '\n') {
            if(seen) break;
            continue;
        }
        if(ch == '.') {
            beforeDot = false;
            multiplier = 1.;
            while(beforeLength) {
                result += (double)(values[--beforeLength] - '0') * multiplier;
                multiplier *= 10.;
            }
            multiplier = 10.;
        }
        else {
            if(!beforeDot)
            {
                result += double(ch - '0') / multiplier;
                multiplier *= 10.;
            } else {
                values[beforeLength++] = ch;
            }
            seen = true;
        }
    }
    if(beforeDot) {
        multiplier = 1;
        while(beforeLength) {
            result += (double)(values[--beforeLength] - '0') * multiplier;
            multiplier *= 10.;
        }
    }

    if(sign) result *= -1.;
    x = result;
}

struct node {
	double val;
	int x, y;
};

struct CustomCompare {
    bool operator()(const node& a, const node& b) {
		if (a.val != b.val) return a.val < b.val;
		else if (a.y != b.y) return a.y > b.y;
		return a.x > b.x;
    }
};

priority_queue<node, vector<node>, CustomCompare> pq;
vector<vector<double> > v;

int main() {
	int t;
	scanint(t);
	while (t--) {
		v.clear();
		int n, m;
		scanint(n); scanint(m);
		for (int i = 0; i < n; i++) {
			v.push_back(vector<double>());
			for (int j = 0; j < m; j++) {
				double a;
				getDouble(a);
				v[i].pb(a);
				if (j == 0) pq.push({v[i][0], i, 0});
			}
		}
		//for (int i = 0; i < n; i++) pq.push({v[i][0], i, 0});
		while (!pq.empty()) {
			node now = pq.top(); pq.pop();
			if (now.y + 1 < m) pq.push({v[now.x][now.y + 1], now.x, now.y + 1}); 
			printf("%d,%d%c", now.x + 1, now.y + 1, pq.empty() ? '\n' : ' ');
		}
	}
	return 0;
}

