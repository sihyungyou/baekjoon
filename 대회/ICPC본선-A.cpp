#include <cstdio>
using namespace std;

int main() {

    int n, i, j, k, t1, t2, t3;
    scanf("%d", &n);
    int A[n+1];
    
    A[0] = 1;
    A[1] = 1;

    for (i = 2; i <= n; i++) {
        t1 = 1;
        while(1) {
            for (k = 1; 2*k <= i; k++) { 
                t2 = A[i-k];
                t3 = A[i-2*k];
                if(t1 - t2 == t2 - t3) break;
            }
            if (2*k > i) break;
            t1++;
        }
        A[i] = t1;
    }

    printf("%d\n", A[n]);

    return 0;
}