#include<bits/stdc++.h>
using namespace std;
int a[1000][1000];
// 定义方向数组
int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
// vis数组标记是否访问该位置
int vis[1000][1000] = {0};
int cnt = 0;
// 终点坐标
int xe, ye;
void dfs(int x, int y){
    // 到达终点
    if(x == xe && y == ye){
        cnt++;
        return;
    }
    for(int i = 0; i < 4; i++){
        // 按照方向数组行进
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if(a[xx][yy] == 0 && vis[xx][yy] == 0){
            // 标记走过了
            vis[xx][yy] = 1;
            dfs(xx, yy);
            vis[xx][yy] = 0;
        }
    }

}
int main(){
    int m, n;
    cin>>m>>n;
    xe = m; ye = n;
    int i, j;
    for(i = 1; i <= m; i++){
        for(j = 1; j <= n; j++){
            cin>>a[i][j];
        }
    }
    // 起点
    vis[1][1]=1; 
    dfs(1, 1);
    cout<<cnt<<endl;


}