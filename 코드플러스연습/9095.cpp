/*
문제
정수 4를 1, 2, 3의 합으로 나타내는 방법은 총 7가지가 있다. 합을 나타낼 때는 수를 1개 이상 사용해야 한다.

1+1+1+1
1+1+2
1+2+1
2+1+1
2+2
1+3
3+1
정수 n이 주어졌을 때, n을 1, 2, 3의 합으로 나타내는 방법의 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스는 한 줄로 이루어져 있고, 정수 n이 주어진다. n은 양수이며 11보다 작다.

출력
각 테스트 케이스마다, n을 1, 2, 3의 합으로 나타내는 방법의 수를 출력한다.
*/

#include <cstdio>
using namespace std;

int main() {

  int t, n, i, j;
  int arr[10 + 1];

  arr[1] = 1;
  arr[2] = 2;
  arr[3] = 4;

  for (i = 4; i <= 10; i++) {
    arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
  }

  scanf("%d", &t);

  for (i = 0; i < t; i++) {
    scanf("%d", &n);
    printf("%d\n", arr[n]);
  }

  return 0;
}


/*
#include <cstdio>
int main() {
    int t;
    scanf("%d",&t);
    while (t--) {
        int ans = 0;
        int n;
        scanf("%d",&n);
        for (int l1=1; l1<=3; l1++) {
            if (l1 == n) {
                ans += 1;
            }
            for (int l2=1; l2<=3; l2++) {
                if (l1+l2 == n) {
                    ans += 1;
                }
                for (int l3=1; l3<=3; l3++) {
                    if (l1+l2+l3 == n) {
                        ans += 1;
                    }
                    for (int l4=1; l4<=3; l4++) {
                        if (l1+l2+l3+l4 == n) {
                            ans += 1;
                        }
                        for (int l5=1; l5<=3; l5++) {
                            if (l1+l2+l3+l4+l5 == n) {
                                ans += 1;
                            }
                            for (int l6=1; l6<=3; l6++) {
                                if (l1+l2+l3+l4+l5+l6 == n) {
                                    ans += 1;
                                }
                                for (int l7=1; l7<=3; l7++) {
                                    if (l1+l2+l3+l4+l5+l6+l7 == n) {
                                        ans += 1;
                                    }
                                    for (int l8=1; l8<=3; l8++) {
                                        if (l1+l2+l3+l4+l5+l6+l7+l8 == n) {
                                            ans += 1;
                                        }
                                        for (int l9=1; l9<=3; l9++) {
                                            if (l1+l2+l3+l4+l5+l6+l7+l8+l9 == n) {
                                                ans += 1;
                                            }
                                            for (int l0=1; l0<=3; l0++) {
                                                if (l1+l2+l3+l4+l5+l6+l7+l8+l9+l0 == n) {
                                                    ans += 1;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
*/
