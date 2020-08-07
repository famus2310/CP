#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	while (cin >> n && n) {
		int now = 1;
		queue<int> q;
		for (int i = 0; i < n; i++) {
			int a;
			scanf("%d", &a);
			q.push(a);
		}
		stack<int> st;
		while (!q.empty()) {
			while (!st.empty() && st.top() == now) {
				st.pop();
				now++;
			}
			if (now != q.front()) {
				st.push(q.front());
			} else {
				now++;
			}
			q.pop();
		}
		while (!st.empty()) {
			if (st.top() != now)
				break;
			st.pop();
			now++;
		}
		if (now == n + 1)
			cout << "yes" << endl;
		else cout << "no" << endl;
	}
	return 0;
}