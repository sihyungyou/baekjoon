#include <map>
#include <algorithm>
#include <cstdio>
#include <string>

using namespace std;

map<string, int> idNumbers;
int nodeCount[200000];
int ranks[200000];
int arr[200000];

int do_find(int f1) {
    if (arr[f1] == f1) return f1;
    return arr[f1] = do_find(arr[f1]); // path compression
}

int do_union(int f1, int f2) {
    int p1 = do_find(f1);
    int p2 = do_find(f2);

    if (p1 == p2) return nodeCount[p1];

    if (ranks[p1] > ranks[p2]) swap(p1, p2); // rank를 통해 항상 더 깊은 트리로 붙이도록

    arr[p2] = p1;
    nodeCount[p1] += nodeCount[p2];
    nodeCount[p2] = 1;
    if (ranks[p1] == ranks[p2]) ranks[p1]++;

    return nodeCount[p1];
}

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        int id = 0;
        int f;
        scanf("%d", &f);

        idNumbers.clear();

        for (int i = 0; i < 200000; i++) {
            arr[i] = i;
            nodeCount[i] = 1;
            ranks[i] = 0;
        }

        for (int i = 0; i < f; i++) {
            string f1;
            string f2;
            char f1temp[20];
            char f2temp[20];
            scanf("%s %s", f1temp, f2temp);
            f1 = f1temp;
            f2 = f2temp;

            int f1_id, f2_id;
            // f1, f2 모두에 대해 Map에 없다면 자기자신을 value로 추가
            if (idNumbers.find(f1) == idNumbers.end()) {
                idNumbers.insert(make_pair(f1, id++));
                f1_id = idNumbers[f1];
                nodeCount[f1_id] = 1;
                ranks[f1_id] = 1;
            }

            if (idNumbers.find(f2) == idNumbers.end()) {
                idNumbers.insert(make_pair(f2, id++));
                f2_id = idNumbers[f2];
                nodeCount[f2_id] = 1;
                ranks[f2_id] = 1;
            }

            // 두 friends를 union하며 해당 집합의 노드 수를 반환
            f1_id = idNumbers[f1];
            f2_id = idNumbers[f2];
            printf("%d\n", do_union(f1_id, f2_id));
        }
    }

    return 0;
}
