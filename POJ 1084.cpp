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
//问题描述比较简单，核心在于如何才能让其做到检验正方形是否存在的事情
//广搜每一根木棍的情况即可
//但是很不好的是，没有一个合理的最终状态来让我们得到一个
//启发式搜索的结果
//所以，核心问题再次
int T, n, k, totalstick, totalsqaure, neibor, ans, maxd, exist[65], temp[65];

vector <int> stick[65];     //stick[i]需要的square
vector <int> square[65];    // square[i] 需要的stick

int h()//计算启发式函数的代价
{
    int res = 0;
    for(int i = 1; i <= totalsqaure; i++) 
        temp[i] = exist[i];//拷贝
    for(int i = 1; i <= totalsqaure; i++) 
    {
        if(!temp[i])
        {
            res ++;
            temp[i] -= square[i].size();
            for(int j = 0; j < square[i].size(); j++) 
            {
                for(int l = 0; l < stick[square[i][j]].size(); l++)
                {
                    temp[stick[square[i][j]][l]] --;//更新每一个正方形中的情况
                }
            }
            
        }
    }
    return res;
}

bool dfs(int sum)
{
    if(sum+h() >= maxd) //当前状态比最多状态还多，那就减少
        return 0;

    int tmp = 1;
    while(exist[tmp] < 0 && tmp <= totalsqaure) 
    {
        tmp++;  
    }//通过tmp选择一个正方形
    if(tmp > totalsqaure) 
    {
        ans = min(sum, ans); 
        return 1;
    }

    for(int i = 0; i < square[tmp].size(); i++)  //选择一个木棍去删掉
    {
        int sti = square[tmp][i];
        for(int j = 0; j < stick[sti].size(); j++)
        { 
            exist[stick[sti][j]]--;
        }

        if(dfs(sum+1)) 
            return 1;

        for(int j = 0; j < stick[sti].size(); j++) 
        {   
            exist[stick[sti][j]]++;
        }
    }
    return 0;
}

int main()
{
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d", &n, &k);
        totalstick = (n+1)*n*2; //计算出一共的木棍数目
        totalsqaure = 0; 
        neibor = n*2+1; 

        for(int i = 1; i < 65; i++)
        {
            stick[i].clear(); //初始化
            square[i].clear();
        }   

        for(int sz = 1; sz <= n; sz++)
        {
            for(int i = 1; (i-1)/neibor+sz <= n; i += neibor)//遍历每一个neibor
            {
                for(int j = i; j-i+sz <= n; j++)//再看看后面的
                {
                    totalsqaure ++;
                    for(int l = j; l-j < sz; l++)
                    {
                        square[totalsqaure].push_back(l);//将正方形和木棍数目联系起来
                        square[totalsqaure].push_back(l+sz*neibor);
                        stick[l].push_back(totalsqaure);
                        stick[l+sz*neibor].push_back(totalsqaure);   
                    }
                    for(int l = j+n; (l-j-sz)/neibor < sz; l += neibor)
                    {
                        square[totalsqaure].push_back(l);
                        square[totalsqaure].push_back(l+sz);
                        stick[l].push_back(totalsqaure);
                        stick[l+sz].push_back(totalsqaure);       
                    }
                }
            }
        
        }
        

        memset(exist, 0, sizeof exist);
        for(int i = 1; i <= k; i++)
        {
            int t; 
            scanf("%d", &t);
            for(int j = 0; j < stick[t].size(); j++)
            {
                exist[stick[t][j]]--;//处理刚开始初始就有的木棍，将其移去
            }
            totalstick --;
        }

        ans = totalstick;
        for(maxd = 1; ; maxd++) 
        {
            if(dfs(0)) 
            {
                break;//对每一种情况进行搜索
            }
        }
        
        printf("%d\n", ans);
    }
    return 0;
}