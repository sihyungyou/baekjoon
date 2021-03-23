#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    vector<int> distances;
    pair<int, int> coordinates;

    int n;
    scanf("%d", &n);

    char str[n];
    scanf("%s", str);

    for (int t = 0; t < 2; t++) {
        int left = -1;
        int right = 0;
        int distance = 0;

        for (int i = 0; i < n; i++) {
            if (str[i] == '1') {
                if (left != -1 && distance <= i - left) {
                    coordinates = make_pair(left, i);
                    distance = i - left;
                }
                left = i;
            }
        }

        if (left == -1) {
            coordinates = make_pair(0, n - 1);
        } else if (n - left > distance){
            coordinates = make_pair(left, n+1);
        }

        str[coordinates.first + ((coordinates.second - coordinates.first) / 2)] = '1';

        // for (int i = 0; i < n; i++) printf("%c", str[i]);
        // printf("\n");
    }


    // 연속된 0의 개수로 min distance를 구한다.
    int left = -1;
    int distance = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (str[i] == '1') {
            if (left != -1) {
                distance = min(distance, i - left);
            }
            left = i;
        }
    }

    printf("%d\n", distance);

    return 0;
}
