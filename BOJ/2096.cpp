#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    // cstdio보다 약 8ms를 절약하는 코드
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int arr[3];
    int dpmin[3];
    int dpmax[3];

    cin >> arr[0] >> arr[1] >> arr[2];

    for (int i = 0; i < 3; i++) {
        dpmin[i] = dpmax[i] = arr[i];
    }

    int tempn = n - 1;

    while(tempn--) {
        cin >> arr[0] >> arr[1] >> arr[2];

        dpmin[0] = min(dpmin[0], dpmin[1]);
        dpmin[2] = min(dpmin[1], dpmin[2]);
        dpmin[1] = min(dpmin[0], dpmin[2]) + arr[1];
        dpmin[0] += arr[0];
        dpmin[2] += arr[2];

        dpmax[0] = max(dpmax[0], dpmax[1]);
        dpmax[2] = max(dpmax[1], dpmax[2]);
        dpmax[1] = max(dpmax[0], dpmax[2]) + arr[1];
        dpmax[0] += arr[0];
        dpmax[2] += arr[2];
    }

    cout << max(max(dpmax[0], dpmax[1]), dpmax[2]) << " " << min(min(dpmin[0], dpmin[1]), dpmin[2]) << "\n";
    return 0;
}
