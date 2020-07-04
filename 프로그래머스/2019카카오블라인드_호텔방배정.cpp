#include <cstdio>
#include <vector>

using namespace std;

long long do_find(int x, int rooms[]) {
    if (rooms[x] == x) return x;
    else return rooms[x] = do_find(rooms[x], rooms);
}

void do_union(int x, int y, int rooms[]) {
    // printf("union %d and %d\n", x, y);
    // 이 때, x의 parent가 y가 되어야 함
    x = do_find(x, rooms);
    y = do_find(y, rooms);

    rooms[x] = y;
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    int i = 0;
    long long len = room_number.size();
    int rooms[k + 1];

    for (i = 0; i <= k; i++) rooms[i] = i;

    for (i = 0; i < len; i++) {
        // checkin은 parent를 따라 가능한 방을 반환함
        long long want = room_number[i];
        long long checkin = do_find(want, rooms);
        answer.push_back(checkin);
        // checkin 하고 checkin한 방의 parent를 check+1의 parent로 바꾸어야 하므로 union
        long long next = do_find(checkin + 1, rooms);
        do_union(checkin, next, rooms);
    }

    return answer;
}
