#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <climits>
#include <iostream>

using namespace std;

vector<string> w;
string t;
int answer = INT_MAX;
int vec_len;
int word_len;
bool visit[51] = { false, };

void dfs(int idx, int n) {

    int i, j;
    string s = w[idx];
    visit[idx] = true;

    if (s.compare(t) == 0) {
        // found target
        answer = min(answer, n);
        visit[idx] = false;
        return;
    }

    for (i = 0; i < vec_len; i++) {
        string word = w[i];
        int difference = 0;

        for (j = 0; j < word_len; j++) {
            if (s[j] != word[j]) {
                difference++;
            }
        }

        if (difference == 1 && !visit[i]) {
            dfs(i, n + 1);
        }
    }

    visit[idx] = false;
    return;
}

int solution(string begin, string target, vector<string> words) {
    int i;
    t = target;

    word_len = target.length();

    w.push_back(begin);
    for (i = 0; i < words.size(); i++) {
        w.push_back(words[i]);
    }

    vec_len = w.size();

    if (find(words.begin(), words.end(), target) == words.end()) {
        return 0;
    }
    else {
        dfs(0, 0);
        return answer;
    }
}
