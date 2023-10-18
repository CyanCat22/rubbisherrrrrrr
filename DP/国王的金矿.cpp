#include <bits/stdc++.h>
using namespace std;
// 最优子结构，子问题重叠，边界，子问题独立 转移方程
int f[300][300], w[300], c[300];
// f[i][j]---第i个金矿被人挖走后可获得的最大价值
// w[i]---第i个金矿需要的人数 
// c[i]---第i个金矿的价值
int main()
{
    int m, n;
    // m个金矿，n个人
    cin>>m>>n;
    for(int i = 1; i <= m; i++){
        // cin>>w[i]>>c[i];
        scanf("%d %d", &w[i], &c[i]);
    }
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(w[i] <= j){
                // 人数够时
                f[i][j] = max(f[i-1][j], f[i-1][j-w[i]] + c[i]);
            }
            else{
                f[i][j] = f[i-1][j];
            }
        }

    }
    cout<<f[m][n];

    return 0;
}
