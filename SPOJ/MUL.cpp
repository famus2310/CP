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
const int INF = 1e9;
const LL INF64 = 1e18;

const int N = 1e5 + 5;
using cd = complex<double>;

void fft(vector<cd> & a, bool invert) {
  int n = a.size();
  if (n == 1)
    return;

  vector<cd> a0(n / 2), a1(n / 2);
  for (int i = 0; 2 * i < n; i++) {
    a0[i] = a[2*i];
    a1[i] = a[2*i+1];
  }
  fft(a0, invert);
  fft(a1, invert);

  double ang = 2 * PI / n * (invert ? -1 : 1);
  cd w(1), wn(cos(ang), sin(ang));
  for (int i = 0; 2 * i < n; i++) {
    a[i] = a0[i] + w * a1[i];
    a[i + n/2] = a0[i] - w * a1[i];
    if (invert) {
        a[i] /= 2;
        a[i + n/2] /= 2;
    }
    w *= wn;
  }
}

vector<int> multiply(vector<int> const& a, vector<int> const& b) {
  vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
  int n = 1;
  while (n < a.size() + b.size()) 
    n <<= 1;
  reverse(all(fa));
  reverse(all(fb));
  fa.resize(n);
  fb.resize(n);
  reverse(all(fa));
  reverse(all(fb));
  fft(fa, false);
  fft(fb, false);
  for (int i = 0; i < n; i++)
    fa[i] *= fb[i];
  fft(fa, true);

  vector<int> result(n);
  for (int i = 0; i < n; i++)
    result[i] = round(fa[i].real());
  return result;
}

vector<int> op1;
vector<int> op2;
string s;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		op1.clear();
		op2.clear();
		cin >> s;
		for (char c : s) {
			op1.pb(c - '0');
		}
		cin >> s;
		for (char c : s) {
			op2.pb(c - '0');
		}
		vector<int> ans = multiply(op1, op2);
		// reverse(all(ans));
		// for (auto it : ans)
		// 	cout << it << " ";
		// cout <<endl;
		ans.pop_back();
		int carry = 0;
		reverse(all(ans));
		for (int i = 0; i < ans.size(); i++) {
			int tmp = (ans[i] + carry) / 10;
			ans[i] = (ans[i] + carry) % 10;
			carry = tmp;
		}
		if (carry)
			ans.pb(carry);
		while (ans.size() > 1 && ans.back() == 0)
			ans.pop_back();
		reverse(all(ans));
		for (int it : ans)
			cout << it;
		cout << endl;
	}
	return 0;
}
		