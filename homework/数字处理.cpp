#include <bits/stdc++.h>
using namespace std;
string s;
// 题目类型：暴力
// 题目大意：将输入数字s各个位数相加求和sum，再比较与k的大小关系
// 思路：若sum>k则输出0，若sum<=k，则将s中各个数字依次加至9再判断是否大于k，最后输出所加的次数
int main() {
    // k:max_num
	int k, len, cnt = 0, sum = 0, i, temp;
	cin >> k >> s;
	len = s.length();
	for (i = 0; i < len; i++) {
        // 遍历各个数字来求和sum
		sum += s[i] - '0';
	}
    // 进行排序
	sort(s.begin(), s.end());
	while (sum < k) {
        // 提取各个位数，赋值于temp
		temp = s[cnt++] - '0';
        //替换为9，不是加9，所以是加上（9 - 原有的数）
		sum += (9 - temp);
	}
	printf("%d\n", cnt);
	return 0;
}
