/*
문제
세준이는 양수와 +, -, 그리고 괄호를 가지고 길이가 최대 50인 식을 만들었다. 그리고 나서 세준이는 괄호를 모두 지웠다.

그리고 나서 세준이는 괄호를 적절히 쳐서 이 식의 값을 최소로 만들려고 한다.

괄호를 적절히 쳐서 이 식의 값을 최소로 만드는 프로그램을 작성하시오.

입력
첫째 줄에 식이 주어진다. 식은 ‘0’~‘9’, ‘+’, 그리고 ‘-’만으로 이루어져 있고, 가장 처음과 마지막 문자는 숫자이다. 그리고 연속해서 두 개 이상의 연산자가 나타나지 않고, 5자리보다 많이 연속되는 숫자는 없다. 수는 0으로 시작할 수 있다.

출력
첫째 줄에 정답을 출력한다.
*/

#include <cstdio>
#include <cstring>

using namespace std;

int main() {
    int i, ans;
    int j = 0;
    int sum = 0;
    int temp = 0;
    int arr[25] = {0, };
    char str[51];

    scanf("%s", str);

    int len = strlen(str);

    for (i = 0; i < len; i++) {
        if (str[i] == '-') {
            sum += temp;
            arr[j] = sum;
            j++;
            temp = 0;
            sum = 0;
        }
        else if (str[i] == '+') {
            sum += temp;
            temp = 0;
        }
        else {
            temp *= 10;
            temp += (str[i] - '0');
        }
    }

    sum += temp;
    arr[j] = sum;

    ans = arr[0];
    for (i = 1; i < 25; i++) {
        ans -= arr[i];
    }
    printf("%d\n", ans);

    return 0;
}