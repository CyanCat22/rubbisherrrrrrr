#include <bits/stdc++.h>
using namespace std;

int main()
{
	int m, n; 
	cin>>m;
	cin>>n;
	int dp[1000][1000];
	// 前i个物品放入容量为j的购物车
	int w[1000], c[1000];
	// w[i]为物品重量，c[i]为物品价值
	for(int i = 1; i <= m; i++){
		cin>>w[i]>>c[i];
	}
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){
			if(j<w[i]){
				// 空间不够，不选
				dp[i][j] = dp[i-1][j];
			}
			else{
				// 可选，可不选
				dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]]+c[i]);

			}
		}
	}
	cout<<dp[m][n];
	return 0;
}
