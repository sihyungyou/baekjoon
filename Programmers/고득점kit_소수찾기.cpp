#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <cstdio>
#include <utility>

using namespace std;

int solution(string numbers) {
    int max_num = 9999999;
    int answer = 0;
    int len = numbers.length();
    int i, j;
    bool check[max_num+1];
    int arr[len];
    set<int> s;

    for (i = 0; i <= max_num; i++) {
        check[i] = true;
    }

    check[0] = false;
    check[1] = false;

    // 에라토스테네스의 체
    for (i = 2; i <= sqrt(max_num); i++) {
      if (check[i]) {
        for (j = i + i; j <= max_num; j += i) {
            if (check[j]) check[j] = false;
        }
      }
    }

    // 문자열 -> array로
    for (i = 0; i < len; i++) arr[i] = numbers[i] - '0';

    // sort array
    sort(arr, arr+len);

    // permutation 돌면서 소수인지 확인
    do {
        int temp = 0;
        int ten = 1;
        int start = 0;

        for (i = len-1; i >= 0; i--) {
            pair<set<int>::iterator, bool> pr;
            temp += arr[i] * ten;
            pr = s.insert(temp);
            ten *= 10;

            if (pr.second == true && check[temp]) answer++;
        }

    } while(next_permutation(arr, arr+len));

    return answer;
}
