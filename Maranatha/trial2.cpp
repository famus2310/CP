#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back

double x[105], y[105];
int n;
double adjList[105][105];
bool connected[105];


double prim() {
	priority_queue<pair<double, int>, vector<pair<double, int> >, greater<pair<double, int> > > pq;
	pq.push(make_pair(0, 0));
	double ans = 0;
	while (!pq.empty()) {
		double distnow = pq.top().first;
		// cout << distnow << endl;
		int now = pq.top().second;
		pq.pop();
		if (connected[now]) continue;
		ans += distnow;
		connected[now] = 1;
		for (int i = 0; i < n; i++) {
			if (connected[i]) continue;
			// cout << it.first << " "  << it.second <<  endl;
			pq.push(make_pair(adjList[now][i], i));
		}
	}
	return ans;
}

double dist(double xi, double yi, double xj, double yj) {
	double x = xi - xj;
	double y = yi - yj;
	return sqrt(x * x + y * y);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		memset(connected, 0, sizeof connected);
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%lf %lf", x + i, y + i);
		}
		for (int i = 0 ; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				double tmp = dist(x[i], y[i], x[j], y[j]);
				adjList[i][j] = tmp;
				adjList[j][i] = tmp;
			}
		}
		printf("%.2lf\n", prim());
	}
	return 0;
}
		