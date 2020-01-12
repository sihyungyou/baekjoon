/*
문제  
두 개의 자연수를 입력받아 최대 공약수와 최소 공배수를 출력하는 프로그램을 작성하시오.  

입력  
첫째 줄에는 두 개의 자연수가 주어진다. 이 둘은 10,000이하의 자연수이며 사이에 한 칸의 공백이 주어진다.  

출력  
첫째 줄에는 입력으로 주어진 두 수의 최대공약수를,둘째 줄에는 입력으로 주어진 두 수의 최소 공배수를 출력한다.  
*/

#include <cstdio>

using namespace std;

int get_gcd(int a, int b) {
        while(b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int get_lcm(int a, int b, int c){
    return a*b/c;
}

int main() {

    int a, b, gcd, lcm;

    scanf("%d %d", &a, &b);

    gcd = get_gcd(a, b);
    lcm = get_lcm(a, b, gcd);

    printf("%d\n%d\n", gcd, lcm);

    return 0;
}