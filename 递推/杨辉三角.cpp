#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i, j, n;
    int a[100][100];
    cin>>n;
    for(i = 1; i <= n; i++){
        a[i][i] = 1; // 对角线-右边界
        a[i][1] = 1; // 左边界
    }
    for(i = 3; i <= n; i++){
        for(j = 2; j < i; j++){
            a[i][j] = a[i-1][j] + a[i-1][j-1];
        }
    }
    for(i = 1; i <= n; i++){
        for(j = 1; j <= i; j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
