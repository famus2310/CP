#include "memory.h"
#include "grader.h"
#include <stdio.h>
#include <stdlib.h>

static char card[51];
static int up[2], is_up[51], candy[25], candies, moves;

char faceup(int C){
   int c0, c1;
   if (C < 1 || C > 50 || is_up[C]) {
      exit(92);
   }
   is_up[C] = 1;
   up[moves%2] = C;
   moves++;
   if (moves%2 == 0) {
      c0 = card[ up[0] ] - 'A';
      c1 = card[ up[1] ] - 'A';
      if (c0==c1 && !candy[c0]) {
         candy[c0] = 1;
         ++candies;
      }
      is_up[ up[0] ] = is_up[ up[1] ] = 0;
   }
   return card[C];
}

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

void playgame(){
   int i;
   for (i=1;i<=50;i++) {
      card[i] = getchar();
   }
   moves = candies = 0;
   play();
   if (candies != 25) {
      exit(91);
   }
}

int main(){
   playgame();
   printf("OK %d\n",moves);
   return 0;
}
