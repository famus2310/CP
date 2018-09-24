#include "grader.h"
#include "memory.h"

void play() {
	bool vis[55];
	int isOpened[256];
	for (int i = 0; i < 55; i++)
		vis[i] = 0;
	for (int i = 0; i < 256; i++)
		isOpened[i] = 0;
	int opened = 0;
	int matched = 0;
	while (opened < 50) {
		int a = 1;
		while (vis[a])
			a++;
		vis[a] = 1;
		opened++;
		int y;
		int x = faceup(a);
		if (isOpened[x]) {
			y = faceup(isOpened[x]);
			vis[isOpened[x]] = 2;
			vis[a] = 2;
			isOpened[x] = 0;
			matched += 2;
			continue;
		} 
		int b = 1;
		while (vis[b])
			b++;
		vis[b] = 1;
		opened++;
		y = faceup(b);
		if (x == y) {
			vis[a] = 2;
			vis[b] = 2;
			matched += 2;
		} else {
			isOpened[x] = a;
			isOpened[y] = b;
		}
	}
	while (matched < 50) {
		int a = 1;
		while (vis[a] == 1) 
			a++;
		vis[a] = 2;
		int x = faceup(a);
		vis[isOpened[x]] = 2;
		matched += 2;
	}
}