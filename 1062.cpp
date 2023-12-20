//思路还是不对
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
const int MAXN = 100010, MAXM = 500010;
struct edge
{
    int to, dis, next;
}e[MAXM];
int head[MAXN], dis[MAXN], cnt;
bool vis[MAXN];
int n, m, s;
int M, N, P, L, X, wau, w;

int forstand,lastand;//表示两个区间

void add(int u, int v, int d)
{
    e[++cnt].dis = d;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;//链式前向星处理图的存储问题
}

struct person
{
    int val;//这个点的总价值
    int stand;//这个点的地位，如果地位大于k，那就不能搜下去
}persons[MAXN];
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

inline void dijkstra(int initdis)
{
    dis[s] = initdis;
    node a;
    a.dis = initdis;
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
            if(persons[y].stand < forstand || persons[y].stand > lastand)
            {
                continue;
            }
            if (dis[y] > dis[x] + e[i].dis)
            {

                dis[y] = dis[x] + e[i].dis;
                if (!vis[y])
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
    int res = 0x70707070;
    cin >> M >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> P >> L >> X;
        persons[i].val = P;
        persons[i].stand = L;
        for (int j = 0; j < X; j++)
        {
            cin >> wau >> w;
            add(wau, i, w);//反向建立边，然后得到最后的结果
        }
    }
    for (int i = 1; i <= N; i++)
    {
        memset(dis, 0x70707070, sizeof(dis));
        memset(vis, 0, sizeof(vis));
        s = i;//初始化节点
        forstand = persons[i].stand - M;//看看这个区间
        lastand = persons[i].stand + M;
        dijkstra(persons[i].val);

        res = min(res, dis[1]);//每个到大酋长的路径长度
    }
    cout << res << endl;
    return 0;
}