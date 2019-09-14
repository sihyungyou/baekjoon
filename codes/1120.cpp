/*
문제
길이가 N으로 같은 문자열 X와 Y가 있을 때, 두 문자열 X와 Y의 차이는 X[i] ≠ Y[i]인 i의 개수이다. 예를 들어, X=”jimin”, Y=”minji”이면, 둘의 차이는 4이다.

두 문자열 A와 B가 주어진다. 이때, A의 길이는 B의 길이보다 작거나 같다. 이제 A의 길이가 B의 길이와 같아질 때 까지 다음과 같은 연산을 할 수 있다.

A의 앞에 아무 알파벳이나 추가한다.
A의 뒤에 아무 알파벳이나 추가한다.
이때, A와 B의 길이가 같으면서, A와 B의 차이를 최소로 하는 프로그램을 작성하시오.

입력
첫째 줄에 A와 B가 주어진다. A와 B의 길이는 최대 50이고, A의 길이는 B의 길이보다 작거나 같고, 알파벳 소문자로만 이루어져 있다.

출력
A와 B의 길이가 같으면서, A와 B의 차이를 최소가 되도록 했을 때, 그 차이를 출력하시오.
*/

#include <iostream>
#include <cstring>

using namespace std;

int getdiff(char * a, char * b, int start) {
    int t = 0;
    int len = strlen(a);
    int diff = 0;
    for (t = 0; t < len; t++) if (a[t] != b[t+start]) diff++;
    return diff;
}

int main() {
    char A[51];
    char B[51];
    int i, diff, lenA, lenB, pos, temp;

    cin >> A >> B;

    lenA = strlen(A);
    lenB = strlen(B);
    diff = getdiff(A, B, 0);

    for (i = 1; i < lenB - lenA + 1; i++) {
        temp = getdiff(A, B, i);
        if (temp < diff) {
            diff = temp;
            pos = i;
        }
    }

    cout << diff << "\n";
    return 0;   
}