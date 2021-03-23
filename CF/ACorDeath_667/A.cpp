#include <iostream>
#include <cstdlib>

using namespace std;

int main(){

    //입력
    int t, A, B, ans;

    cin >> t;


    // 시작해보자!
    for(int i = 0 ; i < t ; i++){
        ans = 0;
        cin >> A >> B;
        int temp = abs(A - B);
        if(temp % 10 != 0){
            ans++;
        }
        ans += temp/10;
        cout << ans << endl;
    }


    return 0;
}
