#include <cstdio>
using namespace std;

int get_min(int a, int b) { return a < b ? a : b; } 
int main() {

    int a, b, c, d, e, f, type = 1, ans = 0, amt = 0;
    scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);

    if (e < f) type = 2;

    if (type == 1) {
        amt = get_min(a, d);
        ans += amt * e;
        d -= amt;
        
        amt = get_min(b, c);
        amt = get_min(amt, d);
        ans += amt * f;
    }
    else {
        amt = get_min(b, c);
        amt = get_min(amt, d);
        ans += amt * f;
        d -= amt;

        amt = get_min(a, d);
        ans += amt * e;
    }

    printf("%d\n", ans);

    return 0;
}