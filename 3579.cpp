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
//本来想用模拟然后找结果的，但是时间复杂度为o(n ^ 2)
//显然不够优
//看到提示为二分，所以查询了相关资料得出的结论是
//我们只需要找到，在差值为n的情况下，这样的差值恰好有占一半的数目
//那么就可以
//这是一道二分答案的题目
//但是思考了一下，不需要
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int t;
vector<int> nums;
bool check(int dis)
{
    int count = 0;//计算这个差值下能有多少
    for(int i = 0;i < nums.size();i++)
    {
        count += nums.size() - (lower_bound(nums.begin(),nums.end(),nums[i] + dis) - nums.begin());
    }//这里的count记录的是，超过dis这个差值的间隔有多少个
    //nums[j] + k >= nums[i]
    //k >= nums[i] - nums[j]
    //时的第一个j是哪个
    //和t的关系比大小
    return count > t;//如果count > t,那就是说明，当前的间隔小了，
    //大于这个间隔的大于一半
    //这个时候就需要去改变间隔让其变大
}

int main()
{
    int n;
    while(cin >> n)
    {
        nums.resize(n);
        for(int i = 0;i < n;i++)
        {
            nums[i] = read();
        }
        sort(nums.begin(),nums.end());
        int l = 0,r = nums[n - 1] - nums[0];//在0 - 最大差值之间进行枚举
        //由公式可以知道
        //一共c(n,2)种可能
        //所以二分个数为(n * (n - 1))/4个数中间值就行了
        t = n * (n - 1) / 4;//应该不会溢出？
        while(l <= r)
        {
            int mid = (l + r)/2;
            if(check(mid))
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        printf("%d\n",r);
    }
    return 0;
}