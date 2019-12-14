/*
B. Make Them Odd
time limit per test3 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
There are 𝑛 positive integers 𝑎1,𝑎2,…,𝑎𝑛. For the one move you can choose any even value 𝑐 and divide by two all elements that equal 𝑐.

For example, if 𝑎=[6,8,12,6,3,12] and you choose 𝑐=6, and 𝑎 is transformed into 𝑎=[3,8,12,3,3,12] after the move.

You need to find the minimal number of moves for transforming 𝑎 to an array of only odd integers (each element shouldn't be divisible by 2).

Input
The first line of the input contains one integer 𝑡 (1≤𝑡≤104) — the number of test cases in the input. Then 𝑡 test cases follow.

The first line of a test case contains 𝑛 (1≤𝑛≤2⋅105) — the number of integers in the sequence 𝑎. The second line contains positive integers 𝑎1,𝑎2,…,𝑎𝑛 (1≤𝑎𝑖≤109).

The sum of 𝑛 for all test cases in the input doesn't exceed 2⋅105.

Output
For 𝑡 test cases print the answers in the order of test cases in the input. The answer for the test case is the minimal number of moves needed to make all numbers in the test case odd (i.e. not divisible by 2).

Example
inputCopy
4
6
40 6 40 3 20 1
1
1024
4
2 4 8 16
3
3 1 7
outputCopy
4
10
4
0
*/
#include <cstdio>
#include <set>
using namespace std;

int main() {

    set<int> s;
    int t, i, temp;

    scanf("%d", &t);

    for (i = 0; i < t; i++) {

    }

    return 0;
}