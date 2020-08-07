#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
	string k;
	cout << k.max_size() << endl;
    LL t;
    scanf("%lld", &t);
    while (t--) {
        LL n;
        scanf("%lld", &n);
        if (n == 0) {
            puts("now");
        } else if (n < 60){
            if (n == 1) puts("1 second");
            else printf("%lld seconds\n", n);
        } else if (n < 3600) {
            printf("%lld minute", n / 60);
            if (n / 60 != 1) printf("s");
            n %= 60;
            if (n == 0) puts("");
            else if (n == 1) puts(" and 1 second");
            else printf(" and %lld seconds\n", n);
        } else if (n < 86400) {
            printf("%lld hour", n / 3600);
            if (n / 3600 != 1) printf("s");
            n %= 3600;
            if (n >= 60){
            	if (n % 60 == 0) printf(" and ");
            	else printf(", ");
                printf("%lld minute", n / 60);
                if (n / 60 != 1) printf("s");
                n %= 60;
            }
            if (n == 0) puts("");
            else if (n == 1) puts(" and 1 second");
            else printf(" and %lld seconds\n", n);
        } else if (n < 31536000) {
            printf("%lld day", n / 86400);
            if (n / 86400 != 1) printf("s");
            n %= 86400;
            if (n >= 3600){
            	if (n % 3600 == 0) printf(" and ");
            	else printf(", ");
                printf("%lld hour", n / 3600);
                if (n / 3600 != 1) printf("s");
                n %= 3600;
            }
            if (n >= 60){
            	if (n % 60 == 0) printf(" and ");
            	else printf(", ");
                printf("%lld minute", n / 60);
                if (n / 60 != 1) printf("s");
                n %= 60;
            }
            if (n == 0) puts("");
            else if (n == 1) puts(" and 1 second");
            else printf(" and %lld seconds\n", n);
        } else {
            printf("%lld year", n / 31536000);
            if (n / 31536000 != 1) printf("s");
            n %= 31536000;
            if (n >= 86400){
            	if (n % 86400 == 0) printf(" and ");
            	else printf(", ");
                printf("%lld day", n / 86400);
                if (n / 86400 != 1) printf("s");
                n %= 86400;
            }
            if (n >= 3600){
            	if (n % 3600 == 0) printf(" and ");
            	else printf(", ");
                printf("%lld hour", n / 3600);
                if (n / 3600 != 1) printf("s");
                n %= 3600;
            }
            if (n >= 60){
            	if (n % 60 == 0) printf(" and ");
            	else printf(", ");
                printf("%lld minute", n / 60);
                if (n / 60 != 1) printf("s");
                n %= 60;
            }
            if (n == 0) puts("");
            else if (n == 1) puts(" and 1 second");
            else printf(" and %lld seconds\n", n);
        }
    }
    return 0;
}