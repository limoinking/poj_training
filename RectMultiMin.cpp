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
using namespace std;


int longestCommonSubsequence(string text1, string text2) 
{
    //2为对角线，1为上，-1为左
    vector<vector<int>> record(text1.size() + 1, vector<int>(text2.size() + 1, 0));
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
        for (int i = 1; i <= text1.size(); i++) {
            for (int j = 1; j <= text2.size(); j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    record[i][j] = 2;
                    //
                } else {
                    if(dp[i - 1][j] >= dp[i][j - 1])
                    {
                        record[i][j] = 1;
                    }
                    else
                    {
                        record[i][j] = -1;
                    }
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[text1.size()][text2.size()];
}

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

int main()
{
    // int n = 7;
    // vector<vector<int>>m(7,vector<int>(7,0));
    // vector<int> p = {5,10,3,12,5,50,6};
    // for(int i = 1;i < n;i++)
    // {
    //     m[i][i] = 0;
    // }
    // for(int l = 2;l < n;l++)//这是一个区间dp的模板
    // {
    //     for(int i = 1;i < n - l + 1;i++)
    //     {
    //         int j = i + l - 1;
    //         m[i][j] = INT_MAX;
    //         for(int k = i;k <= j - 1;k++)
    //         {
    //             int q = m[i][k] + m[k + 1][j] + p[i - 1]*p[k] * p[j];
    //             m[i][j] = min(m[i][j],q);
    //         }
    //     }
    // }
    string text1 = "ABCBDAD";
    string text2 = "BDCABA";
    int res = longestCommonSubsequence(text1,text2); 
     return 0;

}