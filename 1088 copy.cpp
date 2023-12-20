//这个不过的原因是，重复的计算了每一次的路径
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
using namespace std;
#define MAXN 105
int a[MAXN][MAXN], v[MAXN][MAXN], ma[MAXN][MAXN], sum, ans, aans;
int dp[MAXN][MAXN];
int r, c;//矩阵边框
int dx[4] = { 0,0,-1,1 };//X轴
int dy[4] = { -1,1,0,0 };//Y轴
void dfs(int x, int y) {
	if (ma[x][y] != 0) {//如果已经找过了，直接输出
	}
	else {
		for (int i = 0; i < 4; i++) {//四个方向
			int xx = x + dx[i], yy = y + dy[i];//前进后的坐标
			if (v[xx][yy] == 1 || xx<1 || yy<1 || xx>r || yy>c || a[x][y] <= a[xx][yy])
				continue;//越界或向高处前进就不走
			dfs(xx, yy);//往下找
			ma[x][y] = max(ma[x][y], ma[xx][yy] + 1);//存贮搜索结果
		}
	}

}
void mydfs(int x, int y, int cur)
{
	for (int i = 0; i < 4; i++)
	{
		int xx = x + dx[i], yy = y + dy[i];//前进后的坐标
		if (xx<1 || yy<1 || xx>r || yy>c || a[x][y] <= a[xx][yy])
			continue;//越界或向高处前进就不走
		if (cur + 1 <= dp[xx][yy])
		{
			//剪枝，这里如果滑的区域没有之前长，那就不用再搜下去了
			continue;
		}
		dp[xx][yy] = cur + 1;
		mydfs(xx, yy, cur + 1);
	}
}
int main() {

	cin >> r >> c;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> a[i][j];
		}
	}//输入
	int res = 0;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++)
		{
			if (dp[i][j] == 0)
			{
				dp[i][j] = 1;
				mydfs(i, j, 1);

			}
			
		}
	}
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++)
		{
			res = max(res, dp[i][j]);

		}
	}
	cout << res << endl;//输出

	return 0;

}