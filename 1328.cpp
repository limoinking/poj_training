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
//这道题主要是如何转为区间合并模型
//从中心点处理就行
static bool cmp(const vector<int> &a, const vector<int> &b)
{
    return a[0] < b[0];
}
double sqr(int dis,int y)
{
    double c = dis * dis - y * y;
    return sqrt(c);
}
vector< vector< int> > merge(vector<vector<int> >& input) {
    int n = input.size();
    vector< vector< int > > res;
    sort(input.begin(),input.end(),cmp);
    int start = input[0][0];
    vector<int> rang;
    rang.push_back(start);
    for(int i = 1;i < input.size();i++)
    {
        if(input[i][0] > input[i-1][1])
        {
            rang.push_back(input[i-1][1]);
            res.push_back(rang);
            rang.clear();
            start = input[i][0];
            rang.push_back(start);
        }
        else
        {
            input[i][1] = max(input[i-1][1],input[i][1]);
        }
    }
    rang.push_back(input[n-1][1]);
    res.push_back(rang);
    return res;
    }
int main()
{
    int T = 1;
    int n,dis;
    while(cin >> n >> dis && n && dis)
    {
        int flag = 0;
        vector<vector<int> > partition;
        for(int i = 0;i < n;i++)
        {
            int xx,yy;
            cin >> xx >> yy;
            if(yy > dis)
            {
                flag = 1;
                continue;
            }
            if(flag == 0)
            {
                int offset = (int)sqr(dis,yy);
                int curx1 = xx - offset;
                int curx2 = xx + offset;
                partition.push_back({curx1,curx2});
            }
            
        }
        if(flag == 1)
        {
            printf("Case %d: %d\n",T++,-1);
            T++;
            continue;
        }
        int res = merge(partition).size();
        printf("Case %d: %d\n",T++,res);
        //      Case 2: 1

    }
    return 0;
}