#include <bits/stdc++.h>
using namespace std;
int mp[1000][1000];
int n, m;
int cnt = 1e9;
int vis[1000][1000];
// 存储每个格子的金币消费（递推）
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void dfs(int x, int y, int sum, bool flag)
{
    if (sum > vis[x][y])
        return;
    // if (x < 1 || y < 1 || x > m || y > m)
    //     return;
    // 对上述两种情况剪枝
    vis[x][y] = min(vis[x][y], sum);

    for (int i = 0; i < 4; i++)
    {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if (xx > 0 && yy > 0 && xx <= m && yy <= m)
        {
            if (mp[xx][yy])
            {
                // 此格子有颜色
                if (mp[xx][yy] == mp[x][y])
                {
                    // 颜色相同,不花费金币
                    dfs(xx, yy, sum, false);
                }
                else
                {
                    // 颜色不同,话费金币
                    dfs(xx, yy, sum + 1, false);
                }
            }
            else
            {
                if (!flag)
                {
                    // 无颜色，但使用魔法
                    mp[xx][yy] = mp[x][y];
                    dfs(xx, yy, sum + 2, true);
                    mp[xx][yy] = 0; // 回溯
                }
            }
        }
    }
}
int main()
{
    cin >> m >> n;

    // m是棋盘大小,n是有颜色的格子数量
    for (int i = 1; i <= n; i++)
    {
        int x, y, c;
        cin >> x >> y >> c;
        mp[x][y] = c + 1;
    }
    memset(vis, 1e9, sizeof(vis));
    dfs(1, 1, 0, false);

    if (vis[m][m] == 1e9)
        cout << -1;
    else
        cout << vis[m][m];
}
