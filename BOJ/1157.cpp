/*
문제
알파벳 대소문자로 된 단어가 주어지면, 이 단어에서 가장 많이 사용된 알파벳이 무엇인지 알아내는 프로그램을 작성하시오. 단, 대문자와 소문자를 구분하지 않는다.

입력
첫째 줄에 알파벳 대소문자로 이루어진 단어가 주어진다. 주어지는 단어의 길이는 1,000,000을 넘지 않는다.

출력
첫째 줄에 이 단어에서 가장 많이 사용된 알파벳을 대문자로 출력한다. 단, 가장 많이 사용된 알파벳이 여러 개 존재하는 경우에는 ?를 출력한다.
*/

#include <cstdio>
#include <cstring>

using namespace std;

int main() {
    int i, maxidx, cnt, max = 0;
    int arr[26] = {0, };
    char str[1000001];

    scanf("%s", str);
    int len = strlen(str);

    for (i = 0; i < len; i++) {
        if (str[i] >= 65 && str[i] <= 90) arr[str[i]-65]++;
        else arr[str[i]-97]++;
    }
    
    for (i = 0; i < 26; i++) {
        if (arr[i] > max) {
            max = arr[i];
            maxidx = i;
        }
    }

    cnt = 0; 

    for (i = 0; i < 26; i++) {
        if (i == maxidx) continue;
        else {
            if (arr[i] == max) cnt++;
        }
    }

    if (cnt > 0) printf("?\n");
    else printf("%c\n", maxidx+65);

    return 0;
}