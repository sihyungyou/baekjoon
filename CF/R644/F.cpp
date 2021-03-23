#include <iostream>
#include <vector>

using namespace std;

bool isValid(string src, string target) {
    int count = 0;
    int len = src.length();

    for (int i = 0; i < len; i++) {
        if (src[i] != target[i]) count++;
    }

    if (count > 1) return false;
    return true;
}

int main() {

    int t;
    scanf("%d", &t);

    while(t--) {
        int n, m;
        cin >> n >> m;

        vector<string> v;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            v.push_back(s);
        }

        bool flag = false;
        int len = v.size();
        string src;

        for (int i = 0; i < m; i++) {
            src = v[0];
            // i번째 index를 a~z 중 하나를 넣는다
            for (int c = 97; c <= 122; c++) {
                int validCount = 0;
                src[i] = c;

                // 그렇게 만들어진 새로운 string을 나머지 n-1개와 비교하며 조건에 만족하는지 검사한다 -> 모두 만족하면 즉시 출력
                for (int j = 1; j < len; j++) {
                    if (isValid(src, v[j])) validCount++;
                }
                if (validCount == n - 1) {
                    flag = true;
                    break;
                }
            }
            if (flag) break;
        }

        if (flag) cout << src << endl;
        else cout << "-1\n";
    }

    return 0;
}
