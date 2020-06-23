/*
문제
오늘은 2007년 1월 1일 월요일이다. 그렇다면 2007년 x월 y일은 무슨 요일일까? 이를 알아내는 프로그램을 작성하시오.

입력
첫째 줄에 빈 칸을 사이에 두고 x(1≤x≤12)와 y(1≤y≤31)이 주어진다. 참고로 2007년에는 1, 3, 5, 7, 8, 10, 12월은 31일까지, 4, 6, 9, 11월은 30일까지, 2월은 28일까지 있다.

출력
첫째 줄에 x월 y일이 무슨 요일인지에 따라 SUN, MON, TUE, WED, THU, FRI, SAT중 하나를 출력한다.
 */

#include <string>
#include <iostream>

using namespace std;

int main() {

    string week[7] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };
    int x, y, month, day, cnt = 0;
    cin >> x >> y;

    month = 1;
    day = 1;

    while(1) {
        if (month == x && day == y) break;

        if (month == 2 && day > 28) {
            // up to 28
            day = 1;
            month++;
            continue;
        }
        else if ( (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && (day > 31) ) {
            // up to 31
            day = 1;
            month++;
            continue;
        }
        else if ( (month == 4 || month == 6 || month == 9 || month == 11) && (day > 30) ) {
            // up to 30
            day = 1;
            month++;
            continue;
        }
        day++;
        cnt++;
    }


    int idx = cnt % 7;
    cout << week[idx] << endl;

    return 0;
}
