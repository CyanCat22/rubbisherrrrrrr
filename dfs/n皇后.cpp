#include <bits/stdc++.h>
using namespace std;
int n;
int sum = 0;
// 棋盘
int a[1000];
// int a[1000][1000];
int Chess[100] = {0};
// 此布局皇后能否互相吃到
bool is_ok(int i){
    for(int k = i-1; k >= 0; k--){
        if(a[i] == a[k] || abs(a[i] - a[k]) == i-k){
            return false;
        }
    }
    return true;
}

void search(int n, int i){
    //若i大于行数，布局完成，打印结果
    if(i >= n){
        sum++;
        for(int j = 0; j < n; j++){
            cout<<a[j]<<" ";
        }
        cout<<endl;
        
    }
    else{
        for(int j = 0; j < n; j++){
            a[i] = j+1;
            if(is_ok(i)){
                search(n, i+1);
            }
            a[i] = 0;
        }
    }
}

int main()
{
    cin>>n;
    search(n, 0);
    cout<<sum;
    return 0;
}
