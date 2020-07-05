#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX 200001

class ball {
    public:
      int id;
      int size;
      int color;
};

bool cmp(ball &a, ball &b) {
    return a.size < b.size;
}

int main() {

      int n, i, j, accumulate = 0;
      scanf("%d", &n);

      ball balls[n];
      int colors[MAX] = { 0, };
      int result[n];

      for (i = 0; i < n; i++) {
          scanf("%d %d", &balls[i].color, &balls[i].size);
          balls[i].id = i;
          result[i] = 0;
      }

      // 크기 기준 오름차순으로 정렬
      sort(balls, balls+n, cmp);

      for (i = 0, j = 0; i < n; i++) {
          // 여기서 중요한 점은 j = 0이 첫번째 for문에 있음으로써 매번 초기화 되지 않아 O(n^2)가 아니라는 것
          for (; balls[i].size > balls[j].size; j++) {
              // 잡혔으면, colors 배열에 기록을 해서 추후에 누적값에서 같은 색깔의 크기를 뺴줄 수 있도록 함
              colors[balls[j].color] += balls[j].size;
              // 누적값을 더해나감
              accumulate += balls[j].size;
          }
          // 현재까지 누적값 - 나와 같은 색을 가지면서 이미 다른 공에게 잡힌 공들의 크기
          result[balls[i].id] = accumulate - colors[balls[i].color];
      }


      for (i = 0; i < n; i++) {
          printf("%d\n", result[i]);
      }

      return 0;
}
