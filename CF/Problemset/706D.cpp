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

struct node {
	node* arr[2];
	LL cnt;
	LL last;
};

node* newNode(LL val) {
	node* cur = new node;
	cur->arr[0] = cur->arr[1] = NULL;
	cur->cnt = 0;
	cur->last = val;
	return cur;
}

void insNode(node* root, int xorVal) {
	node* now = root;
	LL cur = 0;
	for (int i = 32; i >= 0; i--) {
		bool val = xorVal & (1LL << i);
		cur = cur + (int)(val) * (1LL << i);
		if (now->arr[val] == NULL)
			now->arr[val] = newNode(cur);
		now->arr[val]->cnt++;
		now = now->arr[val];
	}
}
 
int query(node* root, int xorVal) {
	node* now = root;
	for (int i = 32; i >= 0; i--) {
		bool val = xorVal & (1LL << i);
		if (now->arr[1 - val] != NULL && now->arr[1 - val]->cnt != 0)
			now = now->arr[1 - val];
		else if(now->arr[val] != NULL)
			now = now->arr[val];
	}
	return xorVal ^ (now->last);
}

void del(node* root, LL xorVal) {
	node* now = root;
	for (int i = 32; i >= 0; i--) {
		bool val = xorVal & (1LL << i);
		now->arr[val]->cnt--;
		now = now->arr[val];
	}
}

int main() {
	int q;
	scanf("%d", &q);
	node* root = newNode(-1);
	insNode(root, 0);
	while (q--) {
		char c;
		LL x;
		cin >> c >> x;
		if (c == '+')
			insNode(root, x);
		else if (c == '-')
			del(root, x);
		else cout << query(root, x) << endl;
	}
	return 0;
}
		