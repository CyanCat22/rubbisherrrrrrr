#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m, n;
    int w[1000], c[1000], dp[10000];
    cin>>m>>n;
    for(int i = 1; i <= n; i++){
        cin>>w[i]>>c[i];
    }
    for(int i = 1; i <= n; i++){
        for(int j = w[i]; j <= m; j++){
            dp[j] = max(dp[j], dp[j-w[i]]+c[i]);
        }
    }
    cout<<"max="<<dp[m];
    return 0;
}
