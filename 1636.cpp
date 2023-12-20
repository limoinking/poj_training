#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<vector>
#define inf 2147483640
#define ll long long
using namespace std;
//由于相互之间不能在一块的犯罪者
//是不能呆在一块的
//所以考虑用整体去思考，先用并查集给他连起来
#define MAXN 410
int cnt1[MAXN];
int cnt2[MAXN];
int dp[MAXN/2][MAXN/2];
int f[MAXN];
int m,r;
struct P
{
    int a;
    int b;
}p[MAXN];
int cnt;//记录连通的集合个数
void init()//每次更新并初始化并查集
{
    memset(cnt1,0,sizeof(cnt1));
    memset(cnt2,0,sizeof(cnt2));
    memset(dp,0,sizeof(dp));
    cnt = 0;
    for(int i = 0;i < MAXN;i++)
    {
        f[i] = i;
    }
}
//并查集模板
int find(int a)
{
    return a == f[a] ? a : f[a] = find(f[a]);
}

void merge(int a,int b)
{
    int fa = find(a);
    int fb = find(b);
    if(fa != fb)
        f[fa] = fb;
}
int main()
{
    int n;
    int a,b;
    cin >> n;
    while(n--)
    {
        cin >> m >> r;
        init();
        for(int i = 0;i < r;i++)
        {
            cin >> a >> b;
            merge(a,b + m);//将两个有相同属性的合并
        }
        for(int i = 1;i <= m;i++)
        {
            cnt1[find(i)]++;//看看这个连通分量，在左边有多少个
            //因为需要交换一个连通分量的两边的，所以这里需要考虑左右各自的值
        }
        for(int i = m + 1;i <= m * 2;i++)
        {
            cnt2[find(i)]++;//再看看右边
        }
        for(int i = 1;i <= m * 2;i++)
        {
            if(cnt1[i] || cnt2[i])
            {
                //两边只要一遍有
                p[cnt].a = cnt1[i];
                p[cnt].b = cnt2[i];
                cnt++;
            }
        }

        //到此初始化完成，接下来如何进行算交换的最多人数呢
        dp[0][0] = 1;//初值条件设置
        //可以转化问题为
        //左右两个盒子
        //同时放入一个规定了左右的pair，每个pair中有相应的数目
        //现在往里放东西
        for(int i = 0;i < cnt;i++)
        {
            for(int j = m/2;j >= p[i].a;j--)
            {
                for(int k = m/2;k >= p[i].b;k--)
                {
                    if(dp[j - p[i].a][k - p[i].b])
                    {
                        dp[j][k] = 1;
                    }
                }
            }
        }
        int i = m/2;//最多换一半
        while(!dp[i][i]) i--;
        cout << i << endl;
    }
    return 0;
}
