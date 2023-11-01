#include <bits/stdc++.h>
using namespace std;
long long int dp[10000]; // 背包结果
long long int a[10000]; // 每种货币的面值
int main()
{
    int n, m; // n种面值组成面值为m的方案
    dp[0] = 1;
    cin>>n>>m;

    for(int i = 1; i <= n; i++){
        cin>>a[i];
    }
    for(int i = 1; i <= n; i++){
        for(int j = a[i]; j <= m; j++){
            dp[j] =  dp[j]+dp[j-a[i]];
        }
    }
    cout<<dp[m];
    return 0;
}
