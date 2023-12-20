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
vector<vector<int>> mat;//记录输入
vector<int> temp;//记录每一行的压缩矩阵
vector<int> dp;
int n,m;
int res = -2100000000;
void countMat()
{
    dp.assign(n + 2,0);
    for(int i = 1;i <= n;i++)
    {
        dp[i] = max(temp[i - 1], dp[i - 1] + temp[i - 1]);
        res = max(res, dp[i]);
    }
    cout << res << endl;
}
void findMax()
{
    //压缩矩阵置一位，然后求最大连续子串即可
    for(int i = 0;i < n;i++)
    {
        temp.assign(n,0);
        for(int j = i;j < n;j++)//从第i到i + 1..n-1行矩阵压缩
        {
            for(int k = 0;k < n;k++)
            {
                temp[k] += mat[j][k];
            }
            countMat();
        }
        
    }
}
int main()
{
    cin >> n;
    mat.resize(n ,vector<int>(n,0));
    temp.resize(n);
    dp.resize(n + 2);
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < n;j++)
        {
            cin >> mat[i][j];
        }
    }
    findMax();
    cout << res << endl;
    return 0;
}


