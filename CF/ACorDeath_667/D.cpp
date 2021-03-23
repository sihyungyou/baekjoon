#include <iostream>
#include <cstdlib>

using namespace std;

int main(){

    //입력
    int t, s;
    long long ans;
    string n;

    cin >> t;


    // 시작해보자!
    for(int i = 0 ; i < t ; i++){
        long long temp = 0;
        int check = 0;
        int cnt = 0;
        cin >> n >> s;
        for(int j = 0 ; j < n.length() ; j++){
            if(check == 0){
                if((n[j] - '0') <= s){
                    temp = temp*10 + (n[j] - '0');
                    s -= (n[j] - '0');
                }
                else {
                    // 맨 뒷자리 바꿔준다.
                    if(s == 0){
                        while(temp%10 == 0){
                            temp /= 10;
                            cnt++;
                        }
                        temp /= 10;
                        cnt++;
                    }
                    temp++;
                    temp *= 10;
                    if(s == 0){
                        while(cnt-- > 0){
                            temp *= 10;
                        }
                    }
                    check = 1;
                }
            }
            else temp *= 10;
        }
        ans = temp - stoll(n);
        cout << ans << endl;
    }


    return 0;
}
