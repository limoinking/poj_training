#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int MAXN = 1010, MAXM = 50010;
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


struct node
{
    int dis;
    int pos;
    bool operator <(const node& x)const
    {
        return x.dis < dis;
    }
};

std::priority_queue<node> q;

inline void dijkstra()
{
    dis[s] = 0;
    node a;
    a.dis = 0;
    a.pos = s;
    q.push(a);
    while (!q.empty())
    {
        node tmp = q.top();
        q.pop();
        int x = tmp.pos, d = tmp.dis;
        if (vis[x])
            continue;
        vis[x] = 1;
        for (int i = head[x]; i; i = e[i].next)
        {
            int y = e[i].to;
            if (dis[y] > dis[x] + e[i].dis)
            {
                dis[y] = dis[x] + e[i].dis;
                if (!vis[y])//如果有没有处理过的并且长度短的边
                    //那么就将这个处理过的边和节点加入到其中
                    //并且由于使用了最小堆
                    //所以每一次只需要取头部最小元素作为下一个要搜索的
                {
                    a.dis = dis[y];
                    a.pos = y;
                    q.push(a);
                }
            }
        }
    }
}
int main()
{
    s = 1;
    cin >> n >> en;
    for(int i = 0;i < n;i++)
    {
        int u,v,dis;
        cin >> u >> v >> dis;
        add(u,v,dis);
        add(v,u,dis);
    }
    memset(dis,0x7070707f,sizeof(dis));
    dijkstra();
    cout << dis[en] << endl;
    return 0;

}

