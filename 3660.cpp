#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>
using namespace std;
const int maxn = 300;
typedef long long ll;
int n, m, degree[maxn][maxn];
int main()
{
    //思路很简单，就是如果能够做到
    //这个牛的出度出度和入度的和为n-1，也就是
    //确定了这个牛和其他剩下的牛的关系
    //就能确定位置了
    cin >> n >> m;
    memset(degree, 0, sizeof(degree));
    for (int i = 1; i <= m; i++) 
    {
        int x, y;
        cin >> x >> y;
        degree[x][y] = 1;
    }
    for (int k = 1; k <= n; k++) 
    {

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                degree[i][j] |= (degree[i][k]&degree[k][j]);
            }  
        }    
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) 
    {
        int a = 0, b = 0;
        for (int j = 1; j <= n; j++) 
        {
            a += degree[i][j], b += degree[j][i];
        }
        if(a + b == n - 1) 
        {
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}

