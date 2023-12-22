#include <bits/stdc++.h>
using namespace std;
int dp[1000];
int main()
{
    int n, m, a, b;
    cin>>n>>m>>a>>b;
    if(n < m){
            cout<<min(n*a, b);
            return 0;
    }
    else{
        for(int i = 1; i <= n; i++){
            dp[i] = min(dp[i-1]+a, dp[i-m]+b);
        }
        cout<<dp[n];
    }
    
    
    return 0;
}
