#include <bits/stdc++.h>
using namespace std;
int map1[1000][1000], f[1000];
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
                f[i] = min(f[i], f[j]+map1[i][j]);
            }
        }
    }
    cout<<f[n];
    return 0;
}
