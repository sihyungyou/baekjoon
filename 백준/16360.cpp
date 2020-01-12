/*
문제
There are English words that you want to translate them into pseudo-Latin. To change an English word into pseudo-Latin word, you simply change the end of the English word like the following table.

English	pseudo-Latin
-a	-as
-i, -y	-ios
-l	-les
-n, -ne	-anes
-o	-os
-r	-res
-t	-tas
-u	-us
-v	-ves
-w	-was
If a word is not ended as it stated in the table, put ‘-us’ at the end of the word. For example, a word “cup” is translated into “cupus” and a word “water” is translated into “wateres”.

Write a program that translates English words into pseudo-Latin words.

입력
Your program is to read from standard input. The input starts with a line containing an integer, n (1 ≤ n ≤ 20), where n is the number of English words. In the following n lines, each line contains an English word. Words use only lowercase alphabet letters and each word contains at least 3 and at most 30 letters.

출력
Your program is to write to standard output. For an English word, print exactly one pseudo-Latin word in a line.
*/

#include <cstdio>
#include <string.h>

using namespace std;

int main() {

    char arr[20][35];
    int N, i, len;

    scanf("%d", &N);

    for (i = 0; i < N; i++) {
        scanf("%s", arr[i]);
        len = strlen(arr[i]) - 1;
        if (arr[i][len] == 'a') strcat(arr[i], "s");
        else if (arr[i][len] == 'i') strcat(arr[i], "os");
        else if (arr[i][len] == 'y') {
            arr[i][len] = 'i';
            strcat(arr[i], "os");
        }
        else if (arr[i][len] == 'l') strcat(arr[i], "es");
        else if (arr[i][len] == 'n') {
            arr[i][len] = 'a';
            strcat(arr[i], "nes");
        }
        else if (arr[i][len] == 'e' && arr[i][len-1] == 'n') {
            arr[i][len] = 'n';
            arr[i][len-1] = 'a';
            strcat(arr[i], "es");
        }
        else if (arr[i][len] == 'o') strcat(arr[i], "s");
        else if (arr[i][len] == 'r') strcat(arr[i], "es");
        else if (arr[i][len] == 't') strcat(arr[i], "as");
        else if (arr[i][len] == 'u') strcat(arr[i], "s");
        else if (arr[i][len] == 'v') strcat(arr[i], "es");
        else if (arr[i][len] == 'w') strcat(arr[i], "as");
        else strcat(arr[i], "us");

        printf("%s\n", arr[i]);
    }


    return 0;
}