#include <cstdio>

using namespace std;

#define MAXN 1000000

int n;
int temp[MAXN];
int arr[MAXN];

int min(int a, int b) {
    if (a < b) return a;
    return b;
}

void swap(int * a, int * b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void merge_sort_top_down(int * arr, int l, int r) {
    if (l == r) return;

    int mid = (l + r) / 2;

    // divide
    merge_sort_top_down(arr, l, mid);
    merge_sort_top_down(arr, mid + 1, r);

    // conquer
    int x = l, y = mid + 1, k = l;

    while(x <= mid && y <= r) {
        if (arr[x] < arr[y]) temp[k++] = arr[x++];
        else temp[k++] = arr[y++];
    }

    while(x <= mid) temp[k++] = arr[x++];
    while(y <= r) temp[k++] = arr[y++];

    for (int i = l; i <= r; i++) arr[i] = temp[i];
}

void merge_sort_bottom_up() {
    for (int size = 1; size < n; size *= 2) {
        for (int left = 0; left < n; left += size * 2) {
            int mid = min(left + size - 1, n - 1);
            int right = min(left + (size * 2) - 1, n - 1);

            // merge left...mid, mid + 1...right
            int x = left, y = mid + 1, k = left;
            while(x <= mid && y <= right) {
                if (arr[x] < arr[y]) temp[k++] = arr[x++];
                else temp[k++] = arr[y++];
            }

            while(x <= mid) temp[k++] = arr[x++];
            while(y <= right) temp[k++] = arr[y++];

            for (int i = left; i <= right; i++) arr[i] = temp[i];
        }
    }
}

int get_mdeian(int a, int b, int c) {
    if (a > b) {
        if (b > c) return b;
        else if (a > c) return c;
        else return a;
    } else {
        if (a > c) return a;
        else if (b > c) return c;
        else return b;
    }
}

void quick_sort(int * arr, int l, int r) {
    if (l >= r) return;

    // pivot을 잡는다
    int mid = (l + r) / 2;
    int pivot = get_mdeian(l, mid, r);

    // pivot 값을 오른쪽 끝으로 보내놓고 시작하자
    swap(&arr[pivot], &arr[r]);
    pivot = r;

    int x = l;
    for (int i = l; i < r; i++) {
        // pivot 보다 작으면 swap 후 x를 전진시킨다
        // pivot 보다 크다면 아무것도 하지 않는다
        if (arr[i] <= arr[pivot]) swap(&arr[x++], &arr[i]);
    }

    // x - 1까지가 pivot보다 작은 수들, x부터 pivot - 1까지가 pivot보다 큰 수들이므로
    swap(&arr[x], &arr[pivot]);

    quick_sort(arr, l, x - 1);
    quick_sort(arr, x + 1, r);
}

void print_arr() {
    for (int i = 0; i < n; i++) printf("%d\n", arr[i]);
}

int main() {

    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    // merge_sort_top_down(arr, 0, n - 1);
    // merge_sort_bottom_up();

    quick_sort(arr, 0, n - 1);

    print_arr();

    return 0;
}
