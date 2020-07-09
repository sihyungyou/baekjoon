#include <cstdio>
using namespace std;

#define MAX 100000
int gates[MAX+1];

int do_find(int x) {
    if (x == gates[x]) return gates[x];
    else return gates[x] = do_find(gates[x]);
}

void do_union(int a, int b) {
    int x = do_find(a);
    int y = do_find(b);

    gates[x] = y;

}

int main() {

    int g, p, gi, i, cnt = 0;

    scanf("%d", &g);
    scanf("%d", &p);

    for (i = 0; i <= g; i++) gates[i] = i;

    for (i = 0; i < p; i++) {
        scanf("%d", &gi);
        // 도킹 시도
        int parent = do_find(gi);

        if (parent == 0) {
            // 0까지 갔다는 것은 도킹 가능한 게이트가 없다는 것을 의미
            break;
        }
        else {
            // 도킹하려는 게이트의 부모 노드가 0이 아니라면 해당 게이트는 도킹되었지만 아직 그보다 숫자가 작은 게이트에 도킹할 여유가 있음을 의미
            cnt++;
            do_union(parent, parent - 1);
        }
    }

    printf("%d\n", cnt);

    return 0;
}
