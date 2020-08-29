using namespace std;

int solution(int n) {
    int answer = 0;
    int i, j, half = n/2;

    for (i = 1; i <= half; i++) {
        int temp = 0;
        for (j = i; j <= half + 1; j++) {
            temp += j;
            if (temp == n) {
                answer++;
                break;
            }
            // 이 break이 없다면 효율성 테스트 시간초과
            else if (temp > n) break;
        }
    }

    return answer + 1;
}
