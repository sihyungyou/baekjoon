#include <cstdio>

using namespace std;

int main () {
    
    int hr, min, temp;
    
    scanf("%d %d", &hr, &min);
    
    temp = min - 45;
    if (temp < 0) {
        if (hr-1 < 0) hr = 23;
        else hr--;
        temp *= -1;
        min = 60-temp;
    }
    else if (temp == 0) min = 0;
    else min = temp;
    
    printf("%d %d\n", hr, min);
    
    
    return 0;
}