#include <bits/stdc++.h>
using namespace std;
int map1[1000][1000], f[1000];
// map1为输入的邻接矩阵
int main()
{
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin>>map1[i][j];
        }
        if(i!=1)
            f[i] = 10000;
    }
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(map1[i][j]){
                // 一个是直接从1到i
                // 另一个是先1->j->i
                f[i] = min(f[i], f[j]+map1[i][j]);
            }
        }
    }
    cout<<f[n];
    return 0;
}
