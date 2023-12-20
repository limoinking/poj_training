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

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int main()
{
    bool flag = 0;
    int a,b;
    scanf("%d",&a);
    vector<int> nums1(a,0);
    
    for(int i = 0;i < a;i++)
    {
        scanf("%d",&nums1[i]);
    }
    scanf("%d",&b);
    vector<int> nums2(b,0);
    for(int i = 0;i < b;i++)
    {
        scanf("%d",&nums2[i]);
    }
    for(int i = 0;i < b;i++)
    {
        int target = 10000 - nums2[i];
        int index = lower_bound(nums1.begin(),nums1.end(),target) - nums1.begin();
        if(index == a)//防止越界
        {
            continue;
        }
        if(nums1[index] == target)
        {
            flag = 1;
            break;
        }
    }
    if(flag)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}