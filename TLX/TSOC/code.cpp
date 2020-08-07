#include <cstdio>
#include <iostream>

using namespace std;
 
const int MOD = 1000000007;

int k(int x) {
    return ((x % MOD) + MOD) % MOD;
}

int j(int x, int y) {
    int z = y;
    return k(z - x);
}

int i(int x, int y) {
    int z = y;
    return k(z + x);
}

int h(int x, int y) {
    int z = 0;
    return k((1ll * k(y) * k(x)) % MOD);
}

int g(int x, int y, int z) {
    int w = 0;
    w = h(x, y); //x * y
    w = i(h(y, y), w); //(yy + xy) = (x + y)y
    w = j(h(i(x, y), z), w); //(x + y)y - (x + y)z = (x + y)(y - z)ore
    return h(i(x, y), j(z, y));

}

int f(int x, int y) {
    int z = 0;
    if (x > y)
      x = y;
    while (x --> 0) {
        z = g(z, x, y);
    }
    return z;
}

int main() {
    int t, n, m;
    scanf("%d", &t);
    while (t --> 0) {
        scanf("%d %d", &n, &m);
        printf("%d\n", f(n, m));
    }
    return 0;
}
