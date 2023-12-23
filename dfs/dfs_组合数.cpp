#include <bits/stdc++.h>
using namespace std;
// n个数字里取m个
int n, m;
int a[1000], b[1000];
void dfs(int k)
{
    for (int i = a[k - 1]; i <= n; i++)
    {
        if (b[i] == 0)
        {
            a[k] = i;
            b[i] = 1;
            if (k == m)
            {
                for (int i = 1; i <= m; i++)
                {
                    printf("%d ", a[i]);
                }
                printf("\n");
            }
            else
                dfs(k + 1);
            b[i] = 0;
        }
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    a[0] = 1;
    dfs(1);
}