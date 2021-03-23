/*
소요시간 : 90분
오래걸린 원인 : Trie라는 자료구조를 몰라서 학습하는데 시간을 써야했다.
*/

#include <cstdio>

using namespace std;

struct Trie {

    bool finish;
    Trie * nextNode[10];

    ~Trie() {
		for(int i = 0; i < 10; ++i) {
			if(nextNode[i]) {
                delete nextNode[i];
            }
		}
	}

    void insert(const char * key) {
        if (*key == '\0') {
            // 만약 끝까지 왔다면 여기가 finish 노드이다
            finish = true;
        } else {
            // 아직 문자열이 남았다면,
            int index = *key - '0';
            // 현재 문자에 달린 노드가 있는지 확인한다
            if (nextNode[index] == NULL) {
                // 없다면 새로 할당하고
                nextNode[index] = new Trie();
            }
            // 있다면 그 노드에 현재 위치 다음의 문자부터 insert를 재귀적으로 수행한다
            nextNode[index]->insert(key + 1);
        }
        return;
    }

    bool find (const char * key) {
        if (*key == '\0') {
            // 문자열의 끝까지 오는 중에 finish 노드를 만나지 않았다면 prefix가 아님으로 true를 반환한다
            return true;
        }

        if (finish) {
            // 주어진 문자열을 하나씩 보는데 이미 finish 노드로 체크되어있다면 현재 문자열보다 짧은 어떤 문자열이 이 위치에서 끝났음을 의미한다
            // 그러므로 prefix를 발견한 것이다
            return false;
        }

        // 문자열의 끝도 아니고 finish 노드를 발견한 것도 아니라면 계속해서 다음위치부터 find를 수행한다
        int index = *key - '0';
        return nextNode[index]->find(key + 1);
    }

};

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        int n;
        scanf("%d", &n);

        // 마지막에 null을 붙여야 하므로 문자열의 길이가 주어진 조건 +1인 11이어야한다
        char strs[n][11];

        // 트라이 자료구조 루트를 생성한다
        Trie * root = new Trie();

        for (int i = 0; i < n; i++) {
            scanf("%s", strs[i]);
            // 트라이 자료구조에 입력되는 문자열을 모두 insert 한다
            root->insert(strs[i]);
        }

        bool flag = true;
        for (int i = 0; i < n; i++) {
            // 입력된 문자열들을 root로부터 찾아 내려간다
            if (!root->find(strs[i])) {
                // 만약 찾으면 prefix로 존재한다는 뜻이므로 valid 하지 않다
                flag = false;
                break;
            }
        }

        if (flag) printf("YES\n");
        else printf("NO\n");

        delete root;
    }

    return 0;
}
