#include <cstdio>
#include <cstring>

using namespace std;

int main() {

    int t, i, len, j;
    scanf("%d", &t);

    for (i = 0; i < t; i++) {
        char in[1001];
        scanf("%s", in);
        len = strlen(in);

        j = len-1;
        if (in[j] == 'o' && in[j-1] == 'p') printf("FILIPINO\n");
        else if ( (in[j] == 'u' && in[j-1] == 's' && in[j-2] == 'e' && in[j-3] == 'd') || (in[j] == 'u' && in[j-1] == 's' && in[j-2] == 'a' && in[j-3] == 'm')) printf("JAPANESE\n");
        else if ( in[j] == 'a' && in[j-1] == 'd' && in[j-2] == 'i' && in[j-3] == 'n' && in[j-4] == 'm') printf("KOREAN\n");
    }

    return 0;
}