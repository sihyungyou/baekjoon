// https://programmers.co.kr/learn/courses/30/lessons/64061
#include <cstdio>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int i = 0;
    int j = 0;
    int m = 0;
    int current = 0;
    int moves_len = moves.size();
    int board_len = board.size();
    int answer = 0;
    stack <int> s;

    for (m = 0; m < moves_len; m++) {
        // 몇 번째 열에 크레인을 내릴 것인지 정보
        int move = moves[m] - 1;
        for (i = 0; i < board_len; i++) {
            // 해당 열을 위에서부터 내려가며 인형을 확인함
            if (board[i][move] != 0) {
                // 빈칸이 아닌 첫 인형을 만나면 인형을 잡음
                current = board[i][move];
                board[i][move] = 0;
                break;
            }
        }
        if (i == board_len) {
            current = 0;
            continue;
        }

        if (current != 0) {
            // 끝까지 내려가본 결과, 인형을 집었음
            // stack의 top과 비교하여 다르면 push, 같으면 pop / answer를 증가시킴
            if (!s.empty() && s.top() == current) {
                s.pop();
                answer+=2;
            }
            else {
                s.push(current);
            }
        }
    }

    return answer;
}
