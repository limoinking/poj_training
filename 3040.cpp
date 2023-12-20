#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <deque>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <set>
#define mod 1000000007
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
pair<int,int> a[25];//硬币面值，数量
int use[25];//这个面值的硬币已经使用了多少
int n,c;//硬币种类，每周最少给多少钱
int main()
{
    cin>>n>>c;
    for(int i=1; i<=n; i++)
        cin>>a[i].first>>a[i].second;
    sort(a+1,a+1+n);
    int ans=0;//答案
    while(true)
    {
        memset(use,0,sizeof(use));
        int rest=c;//还有这么多钱没给奶牛
        for(int i=n; i>=1; i--)//从大到小
        {
            int tmp=min(rest/a[i].first,a[i].second);
            //这种类型的硬币能拿几个,并且这里用res/a[i向下取整]，可以做到用最小代价去取
            rest-=tmp*a[i].first;//还有多少钱没给奶牛
            //这里有可能最后减到负值去了
            use[i]=tmp;//这种硬币用了几个
        }
        if(rest)//还有钱没有发完
        {
            for(int i=1; i<=n; i++)//从小到大
            {
                if(a[i].second&&a[i].first>=rest)//这种硬币没有花完并且这种硬币的价值大于没有发完的钱
                {
                    use[i]++;//这种硬币用了一个
                    rest=0;//钱全部发给奶牛了
                    break;
                }
            }
        }
        if(rest)//钱还没发完，即钱不够了，退出循环
        //正常情况下，这里应该是为0或者小于0的
            break;
        int minx=INF;
        for(int i=1; i<=n; i++)//从小到大
        {
            if(use[i])//算出这一轮，用硬币填充的情况是啥样的
                minx=min(minx,a[i].second/use[i]);//找出最小硬币用量的一周
        }
        ans+=minx;//算出周数
        for(int i=1; i<=n; i++)//把硬币的数量更新
        {
            if(use[i])
                a[i].second-=use[i]*minx;//然后更新实际剩余的硬币数目
        }
    }
    cout<<ans<<endl;
}