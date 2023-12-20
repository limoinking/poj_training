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
#include <cstdio>
#include <string>
using namespace std;
//对应ml条信息：
//牛A和牛B的距离不想超过D，那么建立不等式：posA-posB<=D;加入到图中直接add（A，B，D）即可、
//对应md条信息：
//牛A和牛B的距离至少要为D，那么建立不等式：posA-posB>=D，那么我们左右两边同乘-1有：posB-posA<=-D，那么加入到图中add（B，A，-D）即可。
//https://blog.csdn.net/mengxiang000000/article/details/52613328 参考此文
struct node
{
    int from;
    int to;
    int w;
    int next;
}e[200000];
int head[10000];
int vis[10000];
int out[10000];
int dis[10000];
int n,ml,dl,cont;
void add(int from,int to,int w)//链式前向星进行边的加入
{
    e[cont].to=to;
    e[cont].w=w;
    e[cont].next=head[from];
    head[from]=cont++;
}
void spfa()
{
    for(int i=1;i<=n;i++)dis[i]=0x3f3f3f3f;
    dis[1]=0;
    memset(vis,0,sizeof(vis));
    memset(out,0,sizeof(out));
    queue<int >s;
    s.push(1);
    int flag=0;
    while(!s.empty())
    {
        int u=s.front();
        out[u]++;//检测每一个点的访问次数，如果有负环，就跳出
        if(out[u]>n)
        {
            flag=1;
            break;
        }
        s.pop();
        vis[u]=0;
        for(int i=head[u];i!=-1;i=e[i].next)
        {
            int v=e[i].to;
            int w=e[i].w;
            if(dis[v]>dis[u]+w)
            {
                dis[v]=dis[u]+w;
                if(vis[v]==0)
                {
                    vis[v]=1;
                    s.push(v);
                }
            }
        }
    }
    if(flag==1)
    {
        printf("-1\n");//检测到负环，也就是永远无法到达
    }
    else if(dis[n]==0x3f3f3f3f)printf("-2\n");
    else printf("%d\n",dis[n]);
}
int main()
{
    while(~scanf("%d%d%d",&n,&ml,&dl))
    {
        cont=0;
        memset(head,-1,sizeof(head));
        for(int i=0;i<ml;i++)
        {
            int x,y,w;
            scanf("%d%d%d",&x,&y,&w);//加入到图中直接add（A，B，D）即可、
            add(x,y,w);
        }
        for(int i=0;i<dl;i++)
        {
            int x,y,w;
            scanf("%d%d%d",&x,&y,&w);
            add(y,x,-w);//加入到图中直接add（B，A，-D）即可、
        }
        spfa();
    }
    return 0;
}

