#include <vector>

using namespace std;

vector<vector<int> > globalKey;
vector<vector<int> > globalMapWithLock;
vector<vector<int> > globalMapWithKey;
int m; // key
int n; // lock
int lock_cnt; // 자물쇠 홈의 개수 (0의 개수)

void initGlobalMapWithLock(vector<vector<int> > lock) {
    int globalMapLength = 2 * n + (n - 2);
    for (int i = 0; i < globalMapLength; i++) {
        vector<int> v;
        for (int j = 0; j < globalMapLength; j++) {
            v.push_back(0);
        }
        globalMapWithLock.push_back(v);
    }

    for (int i = n - 1; i <= 2 * n - 2; i++) {
        for (int j = n - 1; j <= 2 * n - 2; j++) {
            globalMapWithLock[i][j] = lock[i - (n - 1)][j - (n - 1)];
            if (globalMapWithLock[i][j] == 0) lock_cnt++;
        }
    }
}

void initGlobalMapWithKey() {
    globalMapWithKey.clear();
    int globalMapLength = 2 * n + (n - 2);
    for (int i = 0; i < globalMapLength; i++) {
        vector<int> v;
        for (int j = 0; j < globalMapLength; j++) {
            v.push_back(0);
        }
        globalMapWithKey.push_back(v);
    }
}

void initGlobalKeyWith(vector<vector<int> > key) {
    globalKey.clear();
    for (int i = 0; i < m; i++) {
        vector<int> v;
        for (int j = 0; j < m; j++) {
            v.push_back(key[i][j]);
        }
        globalKey.push_back(v);
    }
}

void rotate() {
    vector<vector<int> > tempKey;
    for (int j = 0; j < m; j++) {
        vector<int> v;
        for (int i = m - 1; i >= 0; i--) {
            v.push_back(globalKey[i][j]);
        }
        tempKey.push_back(v);
    }
    initGlobalKeyWith(tempKey);
}

// key & lock 비교
bool compareKeyAndLock() {
    // 아래 동작을 반복한다
    int maplen = 2 * n + (n - 2);
    int cnt;
    bool flag;

    // 위치를 옮겨가며
    for (int i = 0; i <= maplen - n; i++) {
        for (int j = 0; j <= maplen - n; j++) {
            initGlobalMapWithKey();
            cnt = 0;
            flag = true;
            // key를 그린다
            for (int k = 0; k < m; k++) {
                for (int l = 0; l < m; l++) {
                    globalMapWithKey[i+k][j+l] = globalKey[k][l];
                }
            }
            // 검사를 한다
            for (int y = n - 1; y <= maplen - n; y++) {
                for (int x = n - 1; x <= maplen - n; x++) {
                    // n-1부터 Maplen - n까지 보면서 모든 홈이 메워져야 true를 반환할 수 있다
                    // 돌기와 돌기가 만나면 안된다 <- 예외처리!!
                    if (globalMapWithLock[y][x] == 0 && globalMapWithKey[y][x] == 1) cnt++;
                    if (globalMapWithLock[y][x] == 1 && globalMapWithKey[y][x] == 1) flag = false;
                }
            }
            if (cnt == lock_cnt && flag) {
                return true;
            }
        }
    }
    return false;
}

bool solution(vector<vector<int> > key, vector<vector<int>> lock) {
    bool answer = false;
    lock_cnt = 0;
    m = key.size();
    n = lock.size();

    initGlobalMapWithLock(lock);
    initGlobalMapWithKey();
    initGlobalKeyWith(key);

    if (lock_cnt == 0) {
        answer = true;
    } else {
        for (int i = 0; i < 4; i++) {
            if (compareKeyAndLock()) {
                answer = true;
                break;
            }
            rotate();
        }
    }

    return answer;
}
