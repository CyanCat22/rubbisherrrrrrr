#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        if (n == 0)
            return 0;
        // 动态的二维数组
        vector<int> in[105];
        vector<int> out[105];
        while (1)
        {
            int u, v;
            cin >> u >> v;
            if (u == 0 && v == 0)
            {
                break;
            }
            // 入度、出度
            in[u].push_back(v);
            out[v].push_back(u);
        }
        for (int i = 1; i <= n; i++)
        {
            cout << in[i].size() << " ";
        }
        cout << "\n";
        for (int i = 1; i <= n; i++)
        {
            cout << out[i].size() << " ";
        }
        cout << "\n";
    }

    return 0;
}
