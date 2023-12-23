#include <bits/stdc++.h>
using namespace std;
// 题目类型：分类
// 题目大意：
// 给2*n个队员，如果分成两队  那么一队肯定可以赢二队
// 分完一二队后还是分成两队，两队各抽一人rating大的会赢得比赛,问能否让每个人都赢一遍
// 思路：一开始将所有弱的放到一队中，那么一半的队员就已经赢得一次比赛。再比时不用再分了，只有原来一队中最大的比原来二队中最小的还小。
int main()
{
    int n;
    // 共2*n的队员
    scanf("%d", &n);
    // a：每个队员的rating
    int a[100001];

    for (int i = 1; i <= 2 * n; i++)
    {
        scanf("%d", &a[i]);
    }
    // 按队员rating大小进行排序
    sort(a + 1, a + 2 * n + 1);

    if (a[n] != a[n + 1])
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
