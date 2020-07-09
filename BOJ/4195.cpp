#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

#define MAX 100001

int arr[MAX + 1];
int height[MAX + 1];

int do_find(int x) {
    if (arr[x] == x) {
        return x;
    }
    else {
        return arr[x] = do_find(arr[x]);
    }
}

void do_union(int a, int b) {
    int x = do_find(a);
    int y = do_find(b);

    if (x == y) {
        return;
    }

    if (height[x] < height[y]) {
        arr[x] = y;
        height[y] += height[x];
        height[x] = height[y];
    }
    else {
        arr[y] = x;
        height[x] += height[y];
        height[y] = height[x];
    }
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int i, k, j, t, f, idx;

    cin >> t;

    for (i = 0; i < t; i++) {

        cin >> f;

        for (k = 0; k < MAX + 1; k++) {
              arr[k] = k;
              height[k] = 1;
        }

        idx = 1;
        map<string, int> m;

        for (j = 0; j < f; j++) {

            string first, second;
            cin >> first >> second;

            if (m.count(first) == 0) {
                m[first] = idx++;
            }
            if (m.count(second) == 0) {
                m[second] = idx++;
            }

            // find index of two strings
            int firstidx = m[first];
            int secondidx = m[second];

            // find first and second's parent
            int pf = do_find(firstidx);
            int ps = do_find(secondidx);

            if (pf == ps) {
                // if both are in same tree, just return the height, no need for union
                cout << max(height[pf], height[ps]) << "\n";
            }
            else {
                // if two are not in same tree, do union and return height
                do_union(firstidx, secondidx);
                cout << max(height[pf], height[ps]) << "\n";
            }
        }
    }


    return 0;
}
