/*

greedy 문제로, O(n)에 풀 수 있다.
처음부터 끝까지 순회하면서 이미 있는 음계라면 무조건 한 음계 올려서 set에 넣는다.

*/

#include <cstdio>
#include <set>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        int n;

        scanf("%d", &n);
        int notes[n];
        for (int i = 0; i < n; i++) scanf("%d", &notes[i]);

        set<int> s;
        for (int i = 0; i < n; i++) {
            s.insert(s.count(notes[i]) ? notes[i] + 1 : notes[i]);
        }

        printf("%lu\n", s.size());
    }

    return 0;
}
