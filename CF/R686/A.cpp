#include <cstdio>

using namespace std;

int main() {

    int t;
    scanf("%d", &t);

    while (t--) {
        int num;
        int arr[num + 1];
        scanf("%d", &num);

        printf("%d ", num);
        for (int i = 1; i < num; i++) printf("%d ", i);
        printf("\n");
    }

    return 0;
}
