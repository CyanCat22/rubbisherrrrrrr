#include <bits/stdc++.h>
using namespace std;
// 每个食品只能使用一次
int n, m;
int v[1001], c[1001], w[1001];
int dp[10001][10001];
int main()
{
    cin >> n >> m;
    // 体积最大值、质量最大值,两个维度
    int num;
    cin >> num;
    // 食品总数
    for (int i = 1; i <= num; i++)
    {
        cin >> v[i] >> w[i] >> c[i];
        // 体积，质量，所含卡路里
    }
    for (int i = 1; i <= num; i++)
    {
        for (int j = n; j >= v[i]; j--)
        {
            for (int k = m; k >= w[i]; k--)
            {
                dp[j][k] = max(dp[j][k], dp[j - v[i]][k - w[i]] + c[i]);
            }
        }
    }
    cout << dp[n][m];
    return 0;
}
