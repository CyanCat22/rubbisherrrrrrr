#include <bits/stdc++.h>
using namespace std;
// 题目类型：模拟
// 题目大意：
// 看士兵的移动,首次出现就把士兵挪过去
// 若一扇门连续有很多客人,那士兵就不需要挪
// 如果这扇门没人了，就要跑去帮其他的人

// n：客人数
// k：士兵数
// s: 客人去的门的顺序字符串
// a: 每个门的人数
int n, k, a[26];
string s;
// p：bool 门的状态，是否有士兵把守
bool p[200];

int main()
{
    cin >> n >> k;
    cin >> s;
    for (int i = 0; i < n; ++i)
        ++a[s[i]];
    // 将同一扇门的人数累加
    for (int i = 0; i < n; ++i)
    {
        --a[s[i]];
        // 减掉这扇门的一个人数
        if (!p[s[i]])
        {
            --k;
            // 首次出现要挪士兵，可用士兵数k-=1
            p[s[i]] = true;
            // 表示这扇门有士兵把守
        }
        if (k < 0)
        { // 人数不够用
            cout << "YES" << endl;
            return 0;
            // 直接返回
        }
        if (!a[s[i]])
            ++k;
        // 这扇门该看的人看完了，去帮其他士兵
    }
    cout << "NO" << endl;
    return 0;
}