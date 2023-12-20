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
inline ll read() {
    ll x=0,f=1;char ch=getchar();
    while (ch>'9' || ch<'0') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0' && ch<='9') {x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
 
const int maxn=1000010;
struct point {double x,y;int flag;}p[maxn];//用结构体数组存储
//并且flag = 1为仓库，2为士兵
int n,tmp[maxn];//暂存序列
 
bool cmpx(point a,point b) {
    return a.x==b.x ? a.y<b.y : a.x<b.x;//按照x顺序排，x一样按y排
}
bool cmpy(int a,int b) {
    return p[a].y==p[b].y ? p[a].x<p[b].x : p[a].y<p[b].y;//下面同理
}
double dis(point a,point b) {
    return sqrt((double)(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));//计算两点之间距离
}
double solve(int l,int r) {
    double res=1e10;
    if (l==r) return res;//单点返回无效值
    if (l+1==r) {
        if (p[l].flag==p[r].flag) return res;//两点之间判断是否为不同类
        return dis(p[l],p[r]);
    }
    int mid=(l+r)>>1;
    res=solve(l,mid);
    res=min(res,solve(mid+1,r));//左右两边取最小值
    int num=0;
    for (int i=l;i<=r;i++)
    {
        if (fabs(p[i].x-p[mid].x)<=res) 
        {
            tmp[++num]=i;//将加x范围内的加入tmp数组
        }
    }
    sort(tmp+1,tmp+num+1,cmpy);//按照y排序
    for (int i=1;i<=num;i++)
    {
        for (int j=i+1;j<=num;j++) 
        {
            if (fabs(p[tmp[i]].y-p[tmp[j]].y)>=res) 
                break; //大于res减去
            if (p[tmp[i]].flag!=p[tmp[j]].flag) 
                res=min(res,dis(p[tmp[i]],p[tmp[j]]));
        }
    }
        
    return res;
}
int main() {
    int T;
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        for (int i=1;i<=n;i++) 
            scanf("%lf%lf",&p[i].x,&p[i].y),p[i].flag=0;
        for (int i=1;i<=n;i++) 
            scanf("%lf%lf",&p[i+n].x,&p[i+n].y),p[i+n].flag=1;
        n<<=1;
        sort(p+1,p+1+n,cmpx);
        printf("%.3f\n",solve(1,n));
    }
    return 0;
}