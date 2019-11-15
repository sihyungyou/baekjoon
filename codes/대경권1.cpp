// #include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main(void) {
    int i, j, n, temp, ans = 0, cnt = 1, tempi;
    // vector<vector<int> > v(2, vector<int>(1000, 0));
    vector <vector<int> > v(2);

    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        scanf("%d", &temp);
        v[1].push_back(temp);
    }
    
    i = 1;
    bool flag = true;
    
    while(1) {
        // printf("log2\n");
        if ( (v[0].size() == 1 && v[0][0] == 1) || (v[1].size() == 1 && v[1][0] == 1) ) break;

        cnt = 1;
        flag = true;
        tempi = i+1;
        
        for (j = 0; j < v[i%2].size(); j++) {
            if (j == v[i%2].size()-1) {
                v[tempi%2].push_back(cnt);
                break;
            }
            if (v[i%2][j] == v[i%2][j+1]) cnt++;
            else {
                v[tempi%2].push_back(cnt);
                cnt = 1;
                // if (j == v[i%2].size()-1) flag = false;
            }
        }
        
        // if(!flag) {
        //     v[tempi%2].push_back(1);
        // }
        // printf("size : %d\n", v[tempi%2].size());
        // for (int t = 0; t < v[tempi%2].size(); t++) printf("%d ", v[tempi%2][t]);
        // printf("\n");
        v[i%2].clear();
        i++;
        ans++;
        // printf("ans : %d\n", ans);
    }
    
    printf("%d\n", ans++);
    
    return 0;
}