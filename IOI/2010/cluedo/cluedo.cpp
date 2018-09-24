#include "grader.h"
#include "cluedo.h"

void Solve() {
	int a = 1, b = 1, c = 1;
	while (1) {
		int r = Theory(a, b, c);
		if (r == 1) a++;
		else if (r == 2) b++;
		else if (r == 3) c++;
		else return;
	}	
}
