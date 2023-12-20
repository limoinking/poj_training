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
#define inf 0x3f3f3f3f
#define N 10010
typedef long long ll;
using namespace std;
//由题意可以穷举出三种情况，
//因为连续的五个月内，至少有一个月是亏损的
//所以我们列出所有可行的情况
//（不具有很大的代表性，但是足够表示一般情况）
//只有一个亏损 ssssd ssssd ss
//两个 sssdd sssdd ss
//  ssddd ssddd ss
//sdddd sdddd sd
//优先选择前面的月作为s ss,这样后面就能用较少的d dd就能在给较多的表单作贡献,从而放更多的s ss.
//接下来计算每一种情况的最大值就行
int main()
{
    ll s,d,ans;
	while(cin>>s>>d){
		ans=-1;
	if(d>4*s) ans=10*s-2*d;//判断是哪个连续的五个月一直亏损
    //按照盈利顺序从小到大排序
    //也就相当于取了max值，减少了计算量
	else if(2*d>3*s) ans=8*s-4*d;
	else if(3*d>2*s) ans=6*s-6*d;
	else if(4*d>s) ans=3*s-9*d;//这里很容易错，因为最后那块不应该有连续的两个s
	else ans=-1;
	if(ans>0) printf("%d\n",ans);
	else puts("Deficit");
	}
	return 0; 
}