// https://programmers.co.kr/learn/courses/30/lessons/64063#
#include <vector>
#include <map>

using namespace std;

map <long long, long long> m;

long long do_find(long long x) {
    if (m.find(x) == m.end()) {
        // 만약 x가 map의 key로 존재하지 않는다면 -> return x
        return x;
    }
    // 존재한다면 -> 그 key의 value를 인자로 do_find를 다시 진행
    return m[x] = do_find(m[x]);
}

void do_union(long long x, long long y) {
    // map에 추가
    x = do_find(x);
    y = do_find(y);
    m[x] = y;
}

vector<long long> solution(long long k, vector<long long> room_number) {
    long long want, checkin;
    vector<long long> answer;
    int i, len = room_number.size();

    for (i = 0; i < len; i++) {
        want = room_number[i];
        checkin = do_find(want);
        answer.push_back(checkin);
        do_union(checkin, checkin + 1);
    }

    return answer;
}
