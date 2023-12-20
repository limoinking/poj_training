#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
const int N = 10000;
int x[N],y[N];
int main()
{
	int n,i,j;
	while(cin>>n)
	{
		for(i = 0;i<n;i++)
		cin>>x[i]>>y[i];
		sort(x,x+n);//先排序
		for(i = 0;i<n;i++)
		x[i] -= i;//由于他们之间是从1,2,3,4这样的点，所以还需要减去之间的一些差距
        //即将所有x[i]-i移动到相同位置，问题转换为和y方向上相同。首先重新计算x[i]=x[i]-i，然后重新进行排序。
		sort(x,x+n);//消除了不能重合的影响之后，再进行排序
		sort(y,y+n);
		int ans,ansx,ansy;
		ans = 0;
		ansx = x[n/2];
		ansy = y[n/2];
		for(i = 0;i<n;i++)
		{
			ans += abs(x[i]-ansx);
			ans += abs(y[i]-ansy);
		}
		cout<<ans<<endl;
	}
	return 0;
 } 