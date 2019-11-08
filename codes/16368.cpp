/*
문제
ICPC manager plans a new project which is to be carried out for n days. In this project, m persons numbered from 1 to m are supposed to work. Each day j (1 ≤ j ≤ n) requires dj persons, and each person i (1 ≤ i ≤ m) wants to work wi days.

To increase the efficiency in performing the project, the following two conditions should be satisfied:

each person works for only consecutive w days when he/she works, and
each person can work again after he/she has a rest for at least h days.
ICPC manager wants to find a working plan to assign the working days for all persons such that the number of working days of each person i (1 ≤ i ≤ m) is equal to wi and the number of persons who work for each day j (1 ≤ j ≤ n) is equal to dj, and above two conditions are also satisfied.

For example, assume the project is carried out for n = 9 days, and m = 4 persons participate in the project. Let w = 2 and h = 1. Also, assume (w1, w2, w3, w4) = (4, 4, 6, 2) and (d1, d2, d3, d4, d5, d6, d7, d8, d9) = (1, 3, 2, 1, 2, 1, 1, 3, 2). The table below shows a feasible solution where the i-th row corresponds to person i, and the j-th column corresponds to day j. If person i works or has a rest in day j, the value of the table element with row i and column j is 1 or 0, respectively.
Given m, n, w, h, wi (1 ≤ i ≤ m) which is a multiple of w, and dj (1 ≤ j ≤ n), write a program to find a feasible solution as a working plan.

입력
Your program is to read from standard input. The input starts with a line containing four integers, m, n, w, h (1 ≤ m ≤ 2,000, 1 ≤ n ≤ 2,000, 1 ≤ w, h ≤ n). The following line contains m integers where the i-th (1 ≤ i ≤ m) integer represents wi (1 ≤ wi ≤ n) which is a multiple of w. The next line contains n integers where the j-th (1 ≤ j ≤ n) integer represents dj (0 ≤ dj ≤ m).

출력
Your program is to write to standard output. If there is a feasible working plan, print 1 in the first line followed by m lines, each i-th (1 ≤ i ≤ m) line should contain wi/w integers. These integers form an increasing sequence of first days that person i works in the feasible plan. If there is no feasible working plan, print only -1 in the first line. The first sample below corresponds to the example given in the table above.
*/

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(int a, int b) 
{ 
    return (a > b); 
} 

int main() {

    int m, n, w, h, i, j, cntw = 0;
    scanf("%d %d %d %d", &n, &m, &w, &h);

    int d[m];
    int p[n];
    int table[n][m];
    vector <int> v[n];

    for (i = 0; i < n; i++) scanf("%d", &p[i]);
    for (i = 0; i < m; i++) scanf("%d", &d[i]);
    for (i = 0; i < n; i++) for (j = 0; j < m; j++) table[i][j] = 0;

    sort(p, p+n, compare);


    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (cntw == w) {
                cntw = 0;
                j += h-1;
                continue;
            }
            if (d[j] > 0 && p[i] > 0) {
                if (cntw == 0) {
                    // printf("%d ", j+1);
                    v[i].push_back(j+1);
                }
                table[i][j] = 1;
                d[j]--;
                p[i]--;
                cntw++;
            }
            if (d[j] == 0) continue;
        }
        // printf("\n");
    }
    
    // for (i = 0; i < n; i++) {
    //     for (j = 0; j < m; j++) {
    //         printf("%d ", table[i][j]);
    //     }
    //     printf("\n");
    // }
    
    for (i = 0; i < m; i++) if (d[i] > 0) break;
    for (j = 0; j < n; j++) if (p[j] > 0) break;
    
    if (i == m && j == n) {
        // success
        printf("1\n");
        for (i = 0; i < n; i++) {
            for (j = 0; j < v[i].size(); j++) {
                printf("%d ", v[i][j]);
            }
            printf("\n");
        }
    } else {
        // fail
        printf("-1\n");
    }


    return 0;
}