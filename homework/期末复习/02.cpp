#include <bits/stdc++.h>
using namespace std;
// n皇后
// 皇后可以在横、竖、斜线上不限步数地吃掉其他棋子
int n;
int cnt = 0;
int Chess[100] = {0};
// Chess-棋盘上皇后的分布，每一行的皇后在第几列
void Print(int a[])
{

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
bool isOK(int k)
{
    // 对于第k行i列新放置的皇后 来检验棋盘布局是否合理
    // 1. 同一行、列无皇后
    // 2. 两个斜线上无皇后
    for (int i = k - 1; i >= 0; i--)
    {
        if (Chess[i] == Chess[k] || abs(Chess[i] - Chess[k]) == k - i)
        {
            return false;
        }
    }
    return true;
}
void dfs(int k)
{
    // k为行数
    if (k >= n)
    {
        cnt++;
        Print(Chess);
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            Chess[k] = i; // k行的第i列放置皇后
            if (isOK(k))
            {
                dfs(k + 1);
            }
            Chess[k] = 0;
            // 回溯
        }
    }
}
int main()
{
    cin >> n;
    dfs(0);
    cout << cnt;
}
