/*
문제
오늘은 스타트링크에 다니는 사람들이 모여서 축구를 해보려고 한다. 축구는 평일 오후에 하고 의무 참석도 아니다. 축구를 하기 위해 모인 사람은 총 N명이고 신기하게도 N은 짝수이다. 이제 N/2명으로 이루어진 스타트 팀과 링크 팀으로 사람들을 나눠야 한다.

BOJ를 운영하는 회사 답게 사람에게 번호를 1부터 N까지로 배정했고, 아래와 같은 능력치를 조사했다. 능력치 Sij는 i번 사람과 j번 사람이 같은 팀에 속했을 때, 팀에 더해지는 능력치이다. 팀의 능력치는 팀에 속한 모든 쌍의 능력치 Sij의 합이다. Sij는 Sji와 다를 수도 있으며, i번 사람과 j번 사람이 같은 팀에 속했을 때, 팀에 더해지는 능력치는 Sij와 Sji이다.

N=4이고, S가 아래와 같은 경우를 살펴보자.

i\j	1	2	3	4
1	 	1	2	3
2	4	 	5	6
3	7	1	 	2
4	3	4	5	 
예를 들어, 1, 2번이 스타트 팀, 3, 4번이 링크 팀에 속한 경우에 두 팀의 능력치는 아래와 같다.

스타트 팀: S12 + S21 = 1 + 4 = 5
링크 팀: S34 + S43 = 2 + 5 = 7
1, 3번이 스타트 팀, 2, 4번이 링크 팀에 속하면, 두 팀의 능력치는 아래와 같다.

스타트 팀: S13 + S31 = 2 + 7 = 9
링크 팀: S24 + S42 = 6 + 4 = 10
축구를 재미있게 하기 위해서 스타트 팀의 능력치와 링크 팀의 능력치의 차이를 최소로 하려고 한다. 위의 예제와 같은 경우에는 1, 4번이 스타트 팀, 2, 3번 팀이 링크 팀에 속하면 스타트 팀의 능력치는 6, 링크 팀의 능력치는 6이 되어서 차이가 0이 되고 이 값이 최소이다.

입력
첫째 줄에 N(4 ≤ N ≤ 20, N은 짝수)이 주어진다. 둘째 줄부터 N개의 줄에 S가 주어진다. 각 줄은 N개의 수로 이루어져 있고, i번 줄의 j번째 수는 Sij 이다. Sii는 항상 0이고, 나머지 Sij는 1보다 크거나 같고, 100보다 작거나 같은 정수이다.

출력
첫째 줄에 스타트 팀과 링크 팀의 능력치의 차이의 최솟값을 출력한다.
*/

#include <cstdio>
#include <climits>
#include <cstdlib>

using namespace std;

int grid[21][21];
int n;
bool check[21] = { false, };
int list[10];
int list2[10];
int ans = INT_MAX;

int get_min(int a, int b) { return a < b ? a : b; }

void dfs(int cur, int cnt) {
    int i;
    if (cnt == n/2) {
        int j, k;
        int start = 0;
        int link = 0;

        k = 0;
        for (i = 1; i <= n; i++) {
            if (!check[i]) {
                list2[k] = i;
                k++;
            }
        }

        for (j = 0; j < n/2; j++) {
            for (k = 1; k <= n; k++) {
                if (list[j] != k && check[k]) {
                    start += grid[list[j]][k];
                }
                if (list2[j] != k && !check[k]) {
                    link += grid[list2[j]][k];
                }
            }
        }
        
        ans = get_min(ans, abs(link - start));
        return ;
    }

    for (i = cur + 1; i <= n; i++) {
        if (!check[i]) {
            check[i] = true;
            list[cnt] = i;
            dfs(i, cnt+1);
            check[i] = false;
        }
    }
}

int main() {
    
    int i, j;
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    dfs(0, 0);
    printf("%d\n", ans);

    return 0;
}