#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define debug(x) cout << x << endl
#define fastio ios_base::sync_with_stdio(0), cin.tie(0)
#define PI acos(-1)
#define all(c) c.begin(), c.end()
#define pii pair<int, int>
#define piii pair<int, int>
const int MOD = 1e9 + 7;
const int INF = 1e9;
const LL INF64 = 1e18;

const int N = 1e5 + 5;

struct node {
	node* children[256];
}

node* getNewNode() {
	node* newnode = new node;
	for (int i = 0; i < 256; i++)
		newnode->children[i] = NULL;
	return newnode;
}

void ins(string s, node* root) {
	node* now = root;
	for (int i = 0; i < s.size(); i++) {
		if (now->children[s[i]] != NULL) 
			now = now->children[s[i]];
		else {
			now->children[s[i]] = getNewNode();
		}
		now = now->children[s[i]];
	}
}

int main() {

	return 0;
}
		