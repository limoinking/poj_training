#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int dp[115][70][70], maze[105], status[70], num[70], m, n, len;
char str[111];
int main()
{
 
    while(1);
    while(~scanf("%d%d", &n, &m))
    {
        memset(dp,0,sizeof(dp));
        memset(num,0,sizeof(num));
        memset(maze,0,sizeof(maze));
        memset(status,0,sizeof(status));
        for(int i = 1; i <= n; i++)
        {
            scanf("%s", str);
            for(int j = 0; j < m; j++)
            {
                if(str[j] == 'H')
                {
                    maze[i] += (1<<j);//二进制化地图
                }
            }
        }
        len = 1;
        for(int i = 0;i < (1<<m); i++)//算出每个状态下有几个兵
        {
            if(!(i&(i<<1)) && !(i&(i<<2)))//使用左移的思路，判断在同一行的左右两边是否有炮兵
            {
                int k = i, sum = 0;
                while(k)
                {
                    if(k&1)//计算在这个可行的状态下，我们能有多少个兵
                        sum++;
                    k >>= 1;
                }
                num[len] = sum;//记录下总行兵数
                status[len++] = i;//记录下这个状态下兵是怎么排布了
            }
        }
 
        for(int i = 1; i < len; i++)
        {
            if(!(maze[1]&status[i]))
            {
                dp[1][i][1] = num[i];//初始化第一行的情况
            }
        }
        for(int i = 2; i <= n; i++)
        {
            for(int j = 1; j < len; j++)
            {
                if(status[j]&maze[i]) continue;//判断改行是否和地形冲突
                for(int k = 1; k < len; k++)
                {
                    if(status[j] & status[k]) continue;//分别判断和前一行和地图
                    if(status[k] & maze[i-1]) continue;//是否有冲突
                    for(int t = 1; t < len; t++)
                    {
                        if(status[t]&status[j]) continue;//分别判断上一行，上上一行
                        //是否有冲突
                        if(status[t]&status[k]) continue;
                        if(status[t]&maze[i-2]) continue;//还有和地形是否有冲突
                        //第0行全是空地，也就是随便填
                        dp[i][j][k] = max(dp[i][j][k], dp[i-1][k][t]+num[j]);
                    }
                }
            }
        }
        int ans = 0;
        for(int i = 1;i < len; i++)
            for(int j = 1;j < len; j++)
                 ans = max(ans, dp[n][i][j]);//第几行，本行状态i上一行状态j
        printf("%d\n", ans);
    }
    return 0;
}