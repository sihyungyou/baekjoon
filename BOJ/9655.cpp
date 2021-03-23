 #include <cstdio>
 using namespace std;

 int main() {

     int n;
     scanf("%d", &n);

     // 1개 또는 3개씩 가져가므로 돌의 개수는 반드시 짝수 -> 홀수 -> 짝수 -> 홀수 패턴을 갖게 된다.
     // 마지막 돌을 가져갈 수 있는 경우는 마지막에 1개 혹은 3개, 즉 홀수개 남았을 때 이므로 N이 홀수라면 먼저 시작한사람이, 짝수라면 두번째 시작한 사람이 반드시 이긴다.
     n % 2 == 0 ? printf("CY\n") : printf("SK\n");
     return 0;
 }
