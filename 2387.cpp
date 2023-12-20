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
using namespace std;
const int MAXN = 1020, MAXM = 50010;
struct edge
{
	int to, dis, next;
}e[MAXM];
int head[MAXN], dis[MAXN], cnt;
bool vis[MAXN];
int n, m, s,en;
void add(int u,int v,int d)
{
	e[++cnt].dis = d;
	e[cnt].to = v;
	e[cnt].next = head[u];
	head[u] = cnt;//链式前向星处理图的存储问题
}
bool spfa(int start)
{
    queue<int> q;
    memset(dis, 0x70707070, sizeof(dis));//最长路，初始化为0
    q.push(start);
    vis[start] = true;
    dis[start] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = false;
        for (int i = head[u]; i; i = e[i].next)
        {
            int y = e[i].to;
            if (dis[y] > dis[u] + e[i].dis)
            {
                dis[y] = dis[u] + e[i].dis;
                if (!vis[y])//松弛操作之后，看看是否可以更新别的点
                {
                    vis[y] = true;
                    q.push(y);
                }
            }

            //如果有正环，就返回true
            //di的那个算法是有误的
            //因为他只是判断了一次，而不是判断有无正环
        }
    }
    return false;

}
int main()
{

    cin >> n >> en;
    for(int i = 0;i < n;i++)
    {
        int u,v,dis;
        cin >> u >> v >> dis;
        add(u,v,dis);
        add(v,u,dis);
    }
    spfa(1);
    cout << dis[en] << endl;
    return 0;
}