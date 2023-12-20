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
#define maxn 10005
int n;
int x[maxn], y[maxn];
int disx = 0, disy = 0, mid = 0;
int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> x[i] >> y[i];
	}
	//首先要将y放在同一列上
	sort(y + 1, y + n + 1);
	mid = y[(n + 1) / 2];//可以证明，到中间这个区间到周围的点的距离之和都是相等的
	//因为是没有加权的，所以取左右两端的点都可以
	for (int i = 1; i <= n; i++)
	{
		disy += abs(y[i] - mid);
	}
	//现在对x进行操作
	sort(x + 1, x + n + 1);
	for (int i = 1; i <= n; i++)
	{
		x[i] -= (i + 2);//这样就可以将x变成一个以1为起点的数列
	}
	//这里是因为公式
	// 当前坐标为x1,x2,x3,x4..
	// 最后的位置为x0 + 1,x0 + 2,x0 + 3....
	// 移动的距离为
	// |x1 - (x0 + 1)| + |x2 - (x0 + 2)|
	// |(x1 - 1) - x0| + |(x2 - 2) -x0|//注意，这里的中位数
	// 应该是减完之后的中位数
	// 这就是为啥要减一个i的原因，这里用i - 2也是一样的
	// 整体移动了嘛就是
	// x0就是中位数
	//可以注意到，这些都是要以同一个点为起点然后有个间隔的
	sort(x + 1, x + n + 1);
	mid = x[(n + 1) / 2];
	for (int i = 1; i <= n; i++)
	{
		disx += abs(x[i] - mid);
	}
	cout << disx + disy << endl;
	return 0;
}