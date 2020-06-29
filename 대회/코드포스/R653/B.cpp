/*
B. Multiply by 2, divide by 6
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given an integer 𝑛. In one move, you can either multiply 𝑛 by two or divide 𝑛 by 6 (if it is divisible by 6 without the remainder).

Your task is to find the minimum number of moves needed to obtain 1 from 𝑛 or determine if it's impossible to do that.

You have to answer 𝑡 independent test cases.

Input
The first line of the input contains one integer 𝑡 (1≤𝑡≤2⋅104) — the number of test cases. Then 𝑡 test cases follow.

The only line of the test case contains one integer 𝑛 (1≤𝑛≤109).

Output
For each test case, print the answer — the minimum number of moves needed to obtain 1 from 𝑛 if it's possible to do that or -1 if it's impossible to obtain 1 from 𝑛.

Example
inputCopy
7
1
2
3
12
12345
15116544
387420489
outputCopy
0
-1
2
-1
-1
12
36
*/

#include <cstdio>
using namespace std;

#define MAX 1000000000

int main () {
    int t, i, n, ans;

    scanf("%d", &t);
    for (i = 0; i < t; i++) {
        scanf("%d", &n);

        ans = 0;
        while(1) {
            if (n == 1) {
                break;
            }
            else if (n > MAX) {
                ans = -1;
                break;
            }
            else if (n % 6 == 0) {
                n /= 6;
                ans++;
            }
            else {
                n *= 2;
                ans++;
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}
