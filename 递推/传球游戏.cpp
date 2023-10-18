#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, i, j;
    int sum = 0;
    int f[100][100];
    cin>>n>>m;
    f[1][0] = 1; // 初始化
    // 外循环是传球次数j，内循环是人第一次传球
    for(j = 1; j <= m; j++){
        for(i = 1; i <= n; i++){
            if(i == 1){
                f[i][j] = f[n][j-1]+f[2][j-1];
            }
            else if(i == n){
                f[i][j] = f[1][j-1]+f[n-1][j-1];
            }
            else{
                f[i][j] = f[i-1][j-1]+f[i+1][j-1];
            }
        }
    }
    cout<<f[1][m];
    return 0;
}
