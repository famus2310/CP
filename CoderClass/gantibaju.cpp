#include <bits/stdc++.h>
using namespace std;
int main(){
	double P;
	cin >> P;
	double x = P / 100.0;
	double res = x / (1-(1.0 - x) * (1.0 - x));
	if (x == 1) res = 1.0;
	if (x == 0) res = 0;
	cout << setprecision(9) << fixed << res << endl;
	return 0;
}