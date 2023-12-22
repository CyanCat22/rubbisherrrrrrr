#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, i, j;
    int w[105], c[105];
    int dp[1000001] = {0};
    // 一维数组实现,背包结果
    cin>>m>>n;
    for(i = 1; i <= n; i++){
        cin>>w[i]>>c[i];
    }
    for(i = 1; i <= n; i++){ // 遍历样品种类
        for(j = m; j >= w[i]; j-- ){
            dp[j] = max(dp[j], dp[j-w[i]]+c[i]);
        }
    }
    cout<<dp[m];
    return 0;
}
