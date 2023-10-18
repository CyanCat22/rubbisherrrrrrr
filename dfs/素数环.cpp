#include<bits/stdc++.h>
using namespace std;
int a[1000], b[1000];
int cnt = 0;
int n;
bool IsPrime(int a, int b){
    int i, c = a+b;
    if(c <= 2)
        return false;
    for(i = 2; i <= sqrt(c); i++){
        if(c%i == 0){
            return false;
        }
    }
    return true;
}

void dfs(int k){
    int i;
    // 到目的地， 输出解
    if(k == n+1 && IsPrime(a[1], a[n])){
        cnt++;
        return;
    }
    for(i = 2; i <= n; i++){
        if(b[i] == 0 && IsPrime(i, a[k-1])){
            b[i] = 1; a[k]=i;
            dfs(k+1);
            b[i] = 0;
        }
    }
}

int main(){
    scanf("%d", &n);
    a[1] = 1;
    b[1] = 1;
    dfs(2);
    cout<<cnt;
}