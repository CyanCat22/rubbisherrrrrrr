#include <bits/stdc++.h>
using namespace std;
int dp[100001][3];
// 第i个瓶子涂第j种颜色所花费和最小代价
int a[100001][3];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i][0];
    for (int i = 1; i <= n; i++)
        cin >> a[i][1];
    for (int i = 1; i <= n; i++)
        cin >> a[i][2];
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = min(dp[i - 1][1] + a[i][0], dp[i - 1][2] + a[i][0]);
        dp[i][1] = min(dp[i - 1][0] + a[i][1], dp[i - 1][2] + a[i][1]);
        dp[i][2] = min(dp[i - 1][0] + a[i][2], dp[i - 1][1] + a[i][2]);
    }
    cout << min(dp[n][0], min(dp[n][1], dp[n][2]));
}
