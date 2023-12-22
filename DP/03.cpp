#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[100][100] = {0};
    for (int i = 1; i <= n * n; i++)
    { // 进行4天
        int x, y;
        cin >> x >> y;
        int flag = 0;
        for (int j = 1; j <= n; j++)
        {
            if (a[x][j] == 1 || a[j][y] == 1)
            {
                flag = 1;
            }
        }
        if (!flag)
        {
            cout << i << " ";
            a[x][y] = 1;
        }
    }
}