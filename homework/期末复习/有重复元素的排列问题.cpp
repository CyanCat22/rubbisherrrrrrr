#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int cnt = 0;
char a[1000];
int b[1000]; // b[i]---字母i出现的次数
int vis[1000];
void dfs(int k)
{
    if (k == n)
    {
        for (int i = 0; i < n; i++)
        {
            printf("%c", a[i]);
        }
        cout << endl;
        cnt++;
        return;
    }
    // !将i(char)从a-z遍历
    for (char i = 'a'; i < 'z'; i++)
    {
        if (b[i])
        {
            a[k] = i;
            b[i]--;
            dfs(k + 1);
            b[i]++;
        }
    }
}
int main()
{
    cin >> n;
    cin >> s;

    for (int i = 0; i < s.length(); i++)
    {
        b[s[i]]++;
        // 记录字母出现的次数
    }

    dfs(0);
    cout << cnt;
}
