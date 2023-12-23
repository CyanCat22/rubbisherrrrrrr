#include <iostream>
using namespace std;

// 声明函数
int prime(int);

int main()
{
    int x; // 输入偶数
    cin >> x;

    for (int i = 2; i < x; i++)
    {
        // 判断第一个数是否为素数
        if (prime(i) == 1)
        {
            for (int j = 2; j < x; j++)
            {
                // 判断第二个数是否为素数 且 满足两数之和为偶数x
                if ((prime(j) == 1) && (i + j == x))
                {
                    // 满足，输出两个素数
                    cout << i << "\t" << j << endl;
                }
            }
        }
    }
    return 0;
}

// 判断素数
// 此处也可设置为布尔类型
int prime(int n)
{
    for (int i = 2; i < n; i++) // 可以把 n 换成 sqrt（n） 以减少运算
    {
        if (n % i == 0) // n可以整出除1和本身的数（不为素数）
            return 0;   // 返回 0 函数结束
    }
    return 1; // 循环顺利结束，n为素数，函数结束
}
