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
//第一行 货币种类 兑换站 刚开始的货币种类 和初始值
//人话  几个点 几条边 从哪个点开始 有多少钱
typedef long long ll;
const int INT = 2147483647;
#define N 510
struct edge
{
    int u,v;//起点重点
    double rate,dec;//转化率和佣金
    edge(int a,int b,double c,double d)
    {
        u=a;v=b;rate=c;dec=d;//初始化
    }
};
vector<edge> e[N];//用vector存储，即邻接表
struct node
{
    int pos;//哪一个点
    double val;//当前价值为多少，也就是dis
    node(int a,double b)
    {
        pos=a;val=b;
    }
    bool operator < (const node &a) const
    {
        return val<a.val;
    }
};
int n,m,s;
double v;
double dis[N];
bool vis[N];
bool dijkstra()
{
    for(int i = 1;i <= n;i++)
    {
        //这里是找最长路，所以初始化为0
        dis[i] = 0;
        vis[i] = false;
    }    
    dis[s] = v;//初始化起点价值
    priority_queue<node> q;//优先队列，找到最长的那条边
    q.push(node(s,dis[s]));
    while(!q.empty())
    {
        node u = q.top();
        q.pop();
        if(vis[u.pos]) continue;//如果已经访问过了，就不用再访问了
        vis[u.pos] = true;
        for(int i = 0;i < e[u.pos].size();i++)
        {
            //从这个点出发的点
            edge tmp = e[u.pos][i];//tmp是指从u.pos出发的边的第i条边
            if(vis[tmp.v]) continue;//如果已经访问过就不用管
            if(dis[tmp.v] < (u.val - tmp.dec)*tmp.rate)//如果当前的总价值，减去当前的佣金乘兑换率更大了的话
            //就更新，然后将这个点放入优先队列中
            //且下次在更新了最大金额的点中寻找下一个可能的值
            {
                dis[tmp.v] = (u.val - tmp.dec)*tmp.rate;
                q.push(node(tmp.v,dis[tmp.v]));
            }
        }
    }
    //接下来就是遍历每一条边，看看有没有能让值变大的边
    for(int i=1;i<=n;i++) {
		for(int j=0;j<e[i].size();j++) {
			edge x=e[i][j];
			//若仍存在一种交易方式x，能够扩大价值，则返回true.
			if((dis[x.u]-x.dec)*x.rate>dis[x.v]) return true;
		}

    

}
return false;
}
int main()
{

    cin>>n>>m>>s>>v;
	for(int i=1;i<=m;i++) {
		int u,v;
        cin>>u>>v;
		double x,y;cin>>x>>y;
		e[u].push_back(edge(u,v,x,y));
		cin>>x>>y;
		e[v].push_back(edge(v,u,x,y));
	}
	if(dijkstra()) {
		cout<<"YES"<<endl;
	} else {
		cout<<"NO"<<endl;
	}
    return 0;
}