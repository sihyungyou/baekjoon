/*
문제
목장 주인인 상배는 양과 염소들을 같이 기르고 있다. 기르는 양과 염소는 각각 한 마리 이상이다. 양과 염소는 같은 사료를 먹고, 양 한 마리는 하루에 사료를 정확히 a 그램 먹고, 염소 한 마리는 하루에 정확히 b 그램을 먹는다고 한다.

상배는 매일 아침 양과 염소가 각각 몇 마리인지를 확인하는 작업을 한다. 양과 염소가 각각 몇 마리인지 확인할 때, 양과 염소들이 돌아 다녀서 정확하게 그 수를 구하는 것이 쉽지 않았다. 대신에 양과 염소가 전체 몇 마리인지를 확인하고, 또 양과 염소가 어제 하루 동안 소비한 전체 사료의 양만 확인해서 양과 염소가 각각 몇 마리 인지를 알려고 한다.

상배가 확인한 양과 염소 전체가 n마리이고, 어제 하루 동안 소비한 전체 사료의 양이 w그램일 때, 양과 염소가 각각 몇 마리인지를 구하는 프로그램을 작성하시오. 

입력
입력은 표준입력을 사용한다. 첫 번째 줄에 네 정수 a, b, n, w가 한 줄에 주어진다. 1 ≤ a ≤ 1,000, 1 ≤ b ≤ 1,000, 2 ≤ n ≤ 1,000, 2 ≤ w ≤ 1,000,000이다.

출력
출력은 표준출력을 사용한다. 첫 번째 줄에 양의 수와 염소의 수를 각각 출력한다. 만약 가능한 해가 두 개 이상 있는 경우 혹은 가능한 해가 없을 경우, -1 을 출력한다. 
*/

#include <cstdio>

using namespace std;

int main() {

    int a, b, n, w, S, G, s, g, cnt = 0;

    scanf("%d %d %d %d", &a, &b, &n, &w);

    for (S = 1; S < n; S++) {
        G = n - S;
        if ((a*S + b*G) == w) {
            cnt++;
            s = S;
            g = G;
        }
    }

    if (cnt == 1) printf("%d %d\n", s, g);
    else printf("-1\n");
    
    return 0;
}