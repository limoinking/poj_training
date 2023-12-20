#include<cstdio>
#include<iostream>
#include<cstring>
#define rg register
#define go(i,a,b) for(rg int i=a;i<=b;i++)
#define back(i,a,b) for(rg int i=a;i>=b;i--)
#define mem(a) memset(a,128,sizeof(a));
using namespace std;
const int N=3832;
const int INF=1e9+9;
int n,b,u[N],f[N][2],ans=-INF;
int main(){
    scanf("%d%d",&n,&b);
    go(i,1,n) scanf("%d",&u[i]);
    mem(f);f[0][0]=f[1][1]=0;
    go(i,2,n) back(j,min(i,b),1){
        f[j][0]=max(f[j][0],f[j][1]);
        f[j][1]=max(f[j-1][0],f[j-1][1]+u[i]);
    }
    ans=max(f[b][1],f[b][0]);
    mem(f);f[1][1]=u[1];
    go(i,2,n) back(j,min(i,b),1){
        f[j][0]=max(f[j][0],f[j][1]);
        f[j][1]=max(f[j-1][0],f[j-1][1]+u[i]);
    }
    ans=max(ans,f[b][1]);
    printf("%d\n",ans);
    return 0;
}
