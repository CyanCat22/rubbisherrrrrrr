#include <bits/stdc++.h>
using namespace std;
const int N=1e2+7;
int t, n, m, price[N][N];
int f[10001], dis[N];
void solve(int x){
    memset(f, 0, sizeof(f));
    int today=x, yesterday=x-1;
    for(int i = 1; i <= n; i++){
        dis[i] = price[today][i] - price[yesterday][i];
    }
    for(int i = 1; i <= n; i++){
        for(int j = price[yesterday][i]; j <= m; j++){
            if(f[j-price[yesterday][i]]+dis[i]>=f[j]){
                f[j]=f[j-price[yesterday][i]]+dis[i];
            }
        }
    }
    m+=f[m];
}
int main()
{
    cin>>t>>n>>m;
    for(int i = 1; i <= t; i++){
        for(int k = 1; k <= n; k++){
            cin>>price[i][k];
        }
    }
    for(int i = 2; i <= t; i++){
        solve(i);
    }
    cout<<m<<endl;

}
