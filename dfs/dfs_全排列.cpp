#include<bits/stdc++.h>
using namespace std;
// 全排列
int n;
// a[]->盒子 b[]->手里的卡片
int a[20], b[20] = {0};
void dfs(int k){
    // 边界值
    if(k == n+1){
        for(int i = 1; i <= n; i++){
            printf("%d ", a[i]);
        }
        printf("\n");
        return;
    }
    for(int i = 1; i <= n; i++){
        // b[i]=0，手里有卡片
        if(b[i] == 0){
            // 塞卡片
            a[k] = i;
            b[i] = 1;
            // 向后走
            dfs(k+1);
            // 向后走完塞完卡片又回溯过来啦，在初始化
            b[i] = 0;
        }
    }
}
int main(){
    int i;
    scanf("%d", &n);
    dfs(1);
}

