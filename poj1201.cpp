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
//很好的一道差分约束系统
//设S[i]表示0 - i这一段区间的前缀和这是一个很典型的差分约束类问题
//这是一个很典型的差分约束类问题
//题目中要求集合最小，因此转换为最长路，将所有的式子写成B- A>= C的形式
//同时题目中还有一个条件0<= S[i] - S[i- 1]<= 1 
//S[i]-S[i-1]≥0
//S[i- 1]- S[i]≥-1
//但是有个细节: S[i - 1]不能表示，因此我们需要将所有下标+1.此时S[i] 表示0to S(i- 1)的前缀和
#include<cstdio>
#include<queue>
#include<cstring>
#define INF 1e8+10
using namespace std;
const int MAXN=1e6+10;
inline int read()
{
    char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
struct node
{
    int u,v,w,to;
}edge[MAXN];
int head[MAXN],total=1;
int maxx=-INF,minn=INF;
int dis[MAXN],vis[MAXN];
inline void add(int x,int y,int z)
{
    edge[total].u=x;
    edge[total].v=y;
    edge[total].w=z;
    edge[total].to=head[x];
    head[x]=total++;
}
int spfa()
{
    queue<int>q;
    memset(dis,-0xf,sizeof(dis));
    dis[minn]=0;q.push(minn); 
    while(q.size()!=0)
    {
        int p=q.front();q.pop();
        vis[p]=0;
        for(int i=head[p];i!=-1;i=edge[i].to)
        {
            if(dis[edge[i].v]<dis[p]+edge[i].w)
            {
                dis[edge[i].v]=dis[p]+edge[i].w;
                if(vis[edge[i].v]==0)
                    vis[edge[i].v]=1,q.push(edge[i].v);
            }
        }
    }
    printf("%d",dis[maxx]);
}
int main()
{
    memset(head,-1,sizeof(head));
    int N=read();
    for(int i=1;i<=N;i++)
    {
        int x=read(),y=read(),z=read();
        add(x,y+1,z); 
        maxx=max(y+1,maxx);
        minn=min(x,minn);
    }
    for(int i=minn;i<=maxx-1;i++)
    {
        //S[i]-S[i-1]≥0
        //S[i- 1]- S[i]≥-1
        add(i+1,i,-1);
        add(i,i+1,0);
    }
    spfa();
    return 0;
}