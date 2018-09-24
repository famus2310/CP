#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define debug(x) cout << x << endl
#define fastio ios_base::sync_with_stdio(0), cin.tie(0)
#define PI acos(-1)
#define all(c) c.begin(), c.end()
const int MOD = 1e9 + 7;
const int INF = 1e9;
const LL INF64 = 1e18;

const int NMAX = 1e5 + 5;

struct node{
	node* children[256];
	int val;
};

node* getNewNode(int x) {
	node* newNode = new node;
	newNode->val = x;
	for (int i = 0; i < 256; i++) newNode->children[i] = NULL;
	return newNode;
}

node* ins(node* root, string s, int x) {
	node* ret = root;
	for (int i = 0; i < s.size(); i++) {
		if (root->children[s[i]] == NULL) {
			root->children[s[i]] = getNewNode(x);
		}
		root->children[s[i]]->val = max(x, root->children[s[i]]->val);
		//debug(s.substr(0, i + 1)); debug(root->children[s[i]]->val);
		root = root->children[s[i]];
	}
	return ret;
}

int search(node* root, string s){
	int ret = -1;
	for (int i = 0; i < s.size(); i++) {
		if (root->children[s[i]] == NULL) return -1;
		root = root->children[s[i]];
	}
	return root->val;
}

int main() {
	//freopen("input.in", "r", stdin);
	int n, q;
	cin >> n >> q;
	node* root = getNewNode(0);
	while (n--) {
		string k;
		int x;
		cin >> k >> x;
		root = ins(root, k, x);
	}
	while (q--) {
		string k;
		cin >> k;
		cout << search(root, k) << endl;
	}
	return 0;
}
		