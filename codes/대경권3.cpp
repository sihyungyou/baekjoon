/*
문제 설명
수직선에 빨강, 초록, 파랑 3가지 색 점이 찍혀있습니다. 이때, 3가지 색 점을 모두 포함하는 구간 중 가장 짧은 구간의 길이를 구하려 합니다.

다음은 1, 7 위치에 초록, 3, 10 위치에 빨강, 8, 9, 12 위치에 파란 점이 있는 예시입니다.

three_dot_1.png

이때 아래와 같이 [3, 8] 구간의 경우 빨강, 파랑, 초록 점이 모두 포함되며, 구간의 길이는 5입니다.

three_dot_2.png

그러나 아래와 같이 [7, 10] 구간의 경우 빨강, 파랑, 초록 점이 모두 포함되며, 구간의 길이는 3으로 이때가 가장 짧은 구간이 됩니다.

three_dot_3.png

빨강, 초록, 파랑 3가지 색 점들의 위치가 주어질 때, 3가지 색 점을 모두 포함하는 구간 중 가장 짧은 구간의 길이를 구해주세요.

제한사항
입력 :

표준 입력을 사용해 데이터를 입력받으세요
테스트 케이스 첫째 줄에 점의 개수 N이 주어집니다.
N은 3 이상 300,000 이하인 자연수입니다.
테스트 케이스 둘째 줄부터 N 줄에 걸쳐 점의 위치와 색상이 순서대로 주어집니다.
점의 위치는 1 이상 100,000,000 이하인 자연수입니다.
점의 위치는 모두 다르며, 오름차순 정렬되어 주어집니다.
점의 색상은 1, 2, 3으로 나타내며 1은 빨강, 2는 초록, 3은 파란색입니다.
수직선에는 세 가지 색상의 점이 각각 하나 이상 찍혀있습니다.
출력 :

표준 출력을 사용해 정답을 출력하세요.
첫째 줄에 3가지 색 점을 모두 포함하는 구간 중 가장 짧은 구간의 길이를 출력하세요.
*/
#include <iostream>
#include <climits>

using namespace std;
int get_min(int a, int b) { return a < b ? a : b; }

int main(void) {
    int n, i, j, temp, ans = INT_MAX;
    int flag = 0;
    scanf("%d", &n);
    int arr[2][n];
    bool r = false;
    bool g = false;
    bool b = false;
    
    for (i = 0; i < n; i++) scanf("%d %d", &arr[0][i], &arr[1][i]);
    
    for (i = 0; i < n; i++) {
        for (j = i; j < n; j++) {
            // if (arr[0][j] - arr[0][i] > ans) break;
            
            if (arr[1][j] == 1) r = true;
            if (arr[1][j] == 2) g = true;
            if (arr[1][j] == 3) b = true;   
            
            if (r && g && b) {
                temp = arr[0][j]-arr[0][i];
                ans = get_min(ans, temp);
                r = false;
                g = false;
                b = false;
                break;
            }
        }
    }
    
    printf("%d\n", ans);
    return 0;
}