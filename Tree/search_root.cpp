#include <bits/stdc++.h>
using namespace std;
// 给定一棵树，输出树的根root，孩子最多的结点max以及他的孩子
int father[1000], son[1000];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        father[y] = x;
        son[x]++;
    }
    int maxson = -1000;
    // 找出root节点
    for (int i = 1; i <= n; i++)
    {
        if (father[i] == 0)
        {
            cout << i << endl;
        }
        maxson = max(son[i], maxson);
    }
    int temp;
    for (int i = 1; i <= n; i++)
    {
        if (son[i] == maxson)
        {
            cout << i << endl;
            temp = i;
            break;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (father[i] == temp)
        {
            cout << i << " ";
        }
    }
    return 0;
}

// 8 7
// 4 1
// 4 2
// 1 3
// 1 5
// 2 6
// 2 7
// 2 8

// 4
// 2
// 6 7 8