#include<bits/stdc++.h>
using namespace std;
typedef struct Stu
{
    int score;
    int num;

}Com[10000];
int cmp(Stu a, Stu b){
    if(a.score == b.score){
        return a.num<b.num;
    }
    return a.score > b.score;
}
int main(){
    int m, n;
    cin>>m>>n;
    Com com;
    for(int i = 0; i < m; i++){
        cin>>com[i].num>>com[i].score;
    }

    sort(com, com+m+1, cmp);
    
    int temp = n * 1.5;
    // 卡在这里了，取分数线注意开始是否含0
    int line = com[temp-1].score;
    int cnt = 0;
    for(int i = 0; i < m; i++){
        if(com[i].score >= line){
            cnt++;
        }
        else break;
    }

    for(int i = 0; i < m; i++){
        cout<<com[i].num<<" "<<com[i].score<<"\n";
    }

    // 分数线
    // cout<<line<<" "<<cnt<<"\n";
    // for(int i = 0; i < cnt; i++){
    //     cout<<com[i].num<<" "<<com[i].score<<"\n";
    // }
}

// 7 4
// 3239 88
// 2390 95
// 7231 84
// 1005 95
// 1001 88
// 1006 99
// 2002 96

// 88 6
// 1006 99
// 2002 96
// 1005 95
// 2390 95
// 1001 88
// 3239 88

