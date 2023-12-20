#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <map>
#include <deque>
#include <queue>
#include <set>
#include <stack>
#include <cmath>
#include <algorithm> 
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
//环形dp,且每一天的状态由前一天的状态转移而来
#define N 3800
#define INF 1e9 + 9
int n, b, u[N], f[N][2], ans = -INF;
//考虑第一天的晚上是否会和第二天连在一块
//刚开始思路其实是
//将第一天晚上休息的情况，放到里面
int main()
{
    //f(i,j,k),为前i天花了j小时获得的最多的休息时间
    //k为当前选或者不选

    scanf("%d %d", &n, &b);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &u[i]);
    }
    memset(f, 128, sizeof(f));//初始化为最小值
    //初值条件
    f[0][0] = 0;
    f[1][0] = f[1][1] = 0;//第一个小时休息得到的结果还是0
    //压缩了第i个状态，所以j需要倒叙计算
    for (int i = 2; i <= n; i++)
    {
        for (int j = min(i, b); j >= 1; j--)
        {
            f[j][0] = max(f[j][0], f[j][1]);//由前一个状态转移而来的
            
            f[j][1] = max(f[j - 1][0], f[j - 1][1] + u[i]);
            //倒叙就是为了满足这里的情况
            //不然就不是由i-1的状态推导而来的了
            //
        }
    }
    ans = max(f[b][1], f[b][0]);
    memset(f, 128, sizeof(f));
    f[1][1] = u[1];//选了前一天作为休息
    f[1][0] = 0;
    //那么第一天，前1个小时休息1次为
    for (int i = 2; i <= n; i++)
    {
        for (int j = min(i, b); j >= 1; j--)
        {
            f[j][0] = max(f[j][0], f[j][1]);
            f[j][1] = max(f[j - 1][0], f[j - 1][1] + u[i]);
        }           
    }
    ans = max(ans, f[b][1]);//要求最后一次是要装的
    printf("%d\n", ans);
    return 0;
}