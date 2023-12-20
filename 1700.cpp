#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
#define N 1010
int T,n;
int nums[N];
//简而言之，这个问题是一个
//最小化 区域最大值和最小值和的问题
//但是有两种可行的思路
//一种是第一种带着所有人
//第二种，1，2差不多快
//所以用两个都去带（这个是源自于题目中的样例解释）
//最快的和次快的过河，然后最快的将船划回来；次慢的和最慢的过河，然后次快的将船划回来，所需时间为：
int solve()
{
    for(int i = 0;i < n;i++)
    {
        cin >> nums[i];
    }
    sort(nums,nums + n);
    int least = 0;
    while(n > 3)
    {
        //当三种下的的时候，特殊化处理
        least += min(2 * nums[1] + nums[0] + nums[n - 1], nums[n - 1] + nums[n - 2] + 2 * nums[0]);//从上述两种方案中选取较快的运送最慢的两人
        n -= 2;
    }
    if (n == 3) {//最后3人需特殊处理
        least += nums[0] + nums[2];
        n--;
    }
    return least + nums[n - 1];//最后1人或2人也要特殊处理
}

int main()
{
    int times;
    cin >> T;
    while(T--)
    {
        cin >> n;
        cout << solve() << endl;
    }
    return 0;
}