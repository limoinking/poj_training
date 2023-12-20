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
#include <cstring>
using namespace std;
//应该用spfa判断有无能一直增大的正环
//而不是判断一次增大之后就输出yes
//并且，当当前值已经大于最开始的v的时候，就可以停止去接着搜索了
//因为找到了一条扩大的路线
#define maxn 110
double rate[maxn][maxn];//比率
double Dec[maxn][maxn];//佣金
int n, m, s;
double v;
double dis[maxn];
bool vis[maxn];
int nums[maxn];
bool spfa(int start)
{
    queue<int> q;
    memset(dis, 0, sizeof(dis));//最长路，初始化为0
    q.push(start);
    vis[start] = true;
    dis[start] = v;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = false;
        for (int i = 1; i <= n; i++)
        {

            if (dis[i] < (dis[u] - Dec[u][i]) * rate[u][i])
            {
                dis[i] = (dis[u] - Dec[u][i]) * rate[u][i];//更新最长路
                if (!vis[i])//松弛操作之后，看看是否可以更新别的点
                {
                    vis[i] = true;
                    nums[i]++;
                    if(nums[i] >= n)//最多访问n-1次，如果超过n次，就说明有正环
						return true;
                    q.push(i);
                }
            }

            //如果有正环，就返回true
            //di的那个算法是有误的
            //因为他只是判断了一次，而不是判断有无正环
        }
        if (dis[start] > v) return true;
    }
    return false;

}
int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m >> s >> v;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                rate[i][j] = 1;
            else
                rate[i][j] = 0;//防止自环的出现
        }
    }
    while (m--)
    {
        int a, b;
        double rab, dab, rba, dba;
        cin >> a >> b >> rab >> dab >> rba >> dba;
        rate[a][b] = rab;
        Dec[a][b] = dab;
        rate[b][a] = rba;
        Dec[b][a] = dba;
    }
    if (spfa(s))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}