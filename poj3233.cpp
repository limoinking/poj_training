#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
 
typedef long long ll;
 
typedef struct {
    ll m[120][120];
}Matrix;
 
ll  n,k,mod;
 
Matrix Mul(Matrix a, Matrix b)
{
    Matrix c;
    memset(c.m, 0, sizeof(c.m));
    for (int i = 0; i < 2*n; i++)
    {
        for (int j = 0; j < 2*n; j++)
        {
            for (int k = 0; k < 2*n; k++)
            {
                c.m[i][j] = (c.m[i][j] + (a.m[i][k] * b.m[k][j]) % mod ) % mod;
            }
        }
    }
    return c;
}
//矩阵乘法
Matrix solve(Matrix a, Matrix b)
{
    Matrix c;
    memset(c.m, 0, sizeof(c.m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2*n; j++)
        {
            for (int k = 0; k < 2*n; k++)
            {
                c.m[i][j] = (c.m[i][j] + (a.m[i][k] * b.m[k][j]) % mod ) % mod;
            }
        }
    }
    return c;
}
 
Matrix fastm(Matrix a, ll num)
{
    Matrix res;
    memset(res.m, 0, sizeof(res.m));
    //初始化为单位矩阵
    for(int i=0;i<2*n;i++)
        res.m[i][i]=1;
    while (num)
    {
        if (num & 1)
            res = Mul(res, a);
        num >>= 1;
        a = Mul(a, a);
    }
    return res;
}
 
int main()
{
    while(1);
    Matrix a;
    memset(a.m,0,sizeof(a.m));
    scanf("%lld%lld%lld",&n,&k,&mod);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%lld",&a.m[i][j]);
            a.m[i][j]=a.m[i][j]%mod;
        }
    }
    Matrix b;
    memset(b.m,0,sizeof(b.m));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            b.m[i][j]=a.m[i][j];
    for(int i=0;i<n;i++)
        for(int j=n;j<2*n;j++)
            b.m[i][j]=0;
    for(int i=n;i<2*n;i++)
        for(int j=0;j<n;j++)
            b.m[i][j]=a.m[i-n][j];
    //注意：矩阵等于1表示该矩阵是单位矩阵，即主对角线为1，其余为0
    for(int i=n;i<2*n;i++)
            b.m[i][i]=1;
    for(int i=0;i<n;i++)
            a.m[i][i+n]=1;
    b=fastm(b,k-1);
    Matrix ans=solve(a,b);
    for(int i=0;i<n;i++)
    {
        printf("%lld",ans.m[i][0]);
        for(int j=1;j<n;j++)
        {
            printf(" %lld",ans.m[i][j]);
        }
        printf("\n");
    }
    return 0;
}