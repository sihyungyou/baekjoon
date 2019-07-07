/*
문제
초기에 {0}, {1}, {2}, ... {n} 이 각각 n+1개의 집합을 이루고 있다. 여기에 합집합 연산과, 두 원소가 같은 집합에 포함되어 있는지를 확인하는 연산을 수행하려고 한다.

집합을 표현하는 프로그램을 작성하시오.

입력
첫째 줄에 n(1≤n≤1,000,000), m(1≤m≤100,000)이 주어진다. m은 입력으로 주어지는 연산의 개수이다. 다음 m개의 줄에는 각각의 연산이 주어진다.
합집합은 0 a b의 형태로 입력이 주어진다. 이는 a가 포함되어 있는 집합과, b가 포함되어 있는 집합을 합친다는 의미이다.
두 원소가 같은 집합에 포함되어 있는지를 확인하는 연산은 1 a b의 형태로 입력이 주어진다. 이는 a와 b가 같은 집합에 포함되어 있는지를 확인하는 연산이다.
a와 b는 n 이하의 자연수또는 0이며 같을 수도 있다.

출력
1로 시작하는 입력에 대해서 한 줄에 하나씩 YES/NO로 결과를 출력한다. (yes/no 를 출력해도 된다)
*/

#include <cstdio>

using namespace std;

int p[1000001];

int find(int x) {
    if (x == p[x]) return x;
    else return p[x] = find(p[x]);
}

int main () {
    int n, m, i, a, b, op;

    scanf("%d %d", &n, &m);

    for (i = 0; i <= n; i++) p[i] = i;

    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &op, &a, &b);

        if (op == 0) {
            a = find(a);
            b = find(b);
            if (a > b) p[a] = b;
            else if (a < b) p[b] = a;
        }

        else if (op == 1) {
            a = find(a);
            b = find(b);
            if (a == b) printf("YES\n");
            else printf("NO\n");
        }
    }

    return 0;
}