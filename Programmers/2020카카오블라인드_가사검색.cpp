#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;


bool checkIfMatch(string word, string query, int length) {
    int i = 0;
    for (i = 0; i < length; i++) {
        if (query[i] != '?' && query[i] != word[i]) return false;
    }
    return true;
}

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;

    std::map<int,vector<string> >::iterator it;
    int queriesLen = queries.size();
    int wordsLen = words.size();
    int countingArray[queriesLen];

    // 1. map을 만든다 -> [length : vector<string>]
    // 2. queries의 배열을 순회하며 length에 맞는 dictionary value의 vector에 추가한다
    map <int, vector<string> > m;
    for (int i = 0; i < queriesLen; i++) {
        countingArray[i] = 0;
        int temp = queries[i].length();
        it = m.find(temp);
        if (it != m.end()) {
            m[temp].push_back(queries[i]);
        } else {
            vector<string> v;
            v.push_back(queries[i]);
            m[temp] = v;
        }
    }


    // 3. words 배열을 순회하며 length를 보고 해당 length를 key로 갖는 vector에 대해서만 검사를 한다.
    for (int i = 0; i < wordsLen; i++) {
        int singleWordLen = words[i].length();
        vector<string> tempVector;

        it = m.find(singleWordLen);
        if (it != m.end()) {
            tempVector = m[singleWordLen];
            int tempVectorSize = tempVector.size();

            for (int j = 0; j < tempVectorSize; j++) {
                // 4. 검사를 하고 맞으면 true, 틀리면 false를 return 하는 함수를 구현한다.
                if (checkIfMatch(words[i], tempVector[j], singleWordLen)) {
                    // 5. 만약 true라면 map vector의 string을 queries 배열에서 몇 번째인지 찾고 카운팅 배열의 그 인덱스 값을 올려준다.
                    cout << words[i] << " == " << tempVector[j] << endl;
                    for (int k = 0; k < queriesLen; k++) {
                        if (tempVector[j] == queries[k]) countingArray[k]++;
                    }
                } else {
                    break;
                }
            }
        }
    }

    for (int i = 0; i < queriesLen; i++) answer.push_back(countingArray[i]);
    return answer;
}
