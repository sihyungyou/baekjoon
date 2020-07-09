#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdio>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    int i = 0, j = 0;
    int size = skill_trees.size();
    map<char, char> m;

    m[skill[0]] = 'x';
    for (i = 1; i < skill.length(); i++) {
      m[skill[i]] = skill[i-1];
    }

    printf("map[skill[0]] : %c\n", m[skill[0]]);

    for (i = 0; i < size; i++) {
      vector<char> already;
      already.push_back('x');
      string temp = skill_trees[i];
      int temp_length = temp.length();

      for (j = 0; j < temp_length; j++) {
        // if temp[j]'s value is in already, it can be learned
        // if temp[j] is not a key of map at all, it can be learned
        char key = temp[j];
        printf("key : %c\n", key);
        if (m.find(key) != m.end()) {
          // it's in the map
          char value = m[key];
          printf("value : %c\n", value);
          if (find(already.begin(), already.end(), value) == already.end()) {
            // can't learn!
            printf("can't learn %c because haven't leanred %c\n", key, value);
            break;
          } else {
            // can learn
            printf("can learn %c\n", key);
            already.push_back(key);
          }
        }
      }

      if (j == temp_length) answer++;

    }

    return answer;
}
