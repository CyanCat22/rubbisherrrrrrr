#include <bits/stdc++.h>
using namespace std;
// 输入二叉树的先序序列
// 输出有两行：
// 第一行是二叉树的中序遍历序列；
// 第二行是二叉树的叶子结点个数。
typedef struct tree
{
    char data;
    struct tree *left, *right;
} *Node;
string str;
int i = 0, cnt = 0;
Node Creat()
{
    char ch = str[i++];
    if (ch == '#')
    {
        return NULL;
    }
    Node root = new tree();
    root->data = ch;
    root->left = Creat();
    root->right = Creat();
    if (!root->left && !root->right)
    {
        cnt++;
        // 叶子结点
    }
    return root;
}
void dfs(Node r)
{
    if (r != NULL)
    {
        dfs(r->left);
        cout << r->data;
        dfs(r->right);
    }
}
int main()
{

    cin >> str;
    Node root = Creat();
    dfs(root);
    cout << endl;
    cout << cnt;
    return 0;
}
// ABC##DE#G##F###
// CBEGDFA
// 3