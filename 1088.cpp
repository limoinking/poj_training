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
int a[MAXN][MAXN],v[MAXN][MAXN],ma[MAXN][MAXN],sum,ans,aans;
int r,c;//矩阵边框
int dx[4]={0,0,-1,1};//X轴
int dy[4]={-1,1,0,0};//Y轴
int dfs(int x,int y){
	if(ma[x][y]!=0){//如果已经找过了，直接输出
		return ma[x][y];//这一块才是真正的剪枝，不需要重新
		//将前面的值维护一遍，因为那个之前搜过i,j上面已经是最优解了
	}
	else{
		for(int i=0;i<4;i++){//四个方向
			int xx=x+dx[i],yy=y+dy[i];//前进后的坐标
			if(v[xx][yy]==1 || xx<1 || yy<1 || xx>r ||	yy>c || a[x][y]<=a[xx][yy])
                	continue;//越界或向高处前进就不走
				dfs(xx,yy);//往下找
				ma[x][y]=max(ma[x][y],ma[xx][yy]+1);//存贮搜索结果
			}
		return 	ma[x][y];//返回
	}
	
}
int main(){
		
    cin>>r>>c;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cin>>a[i][j];	
        }
    }//输入
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            ans=dfs(i,j);//从每个节点开始找
            aans=max(aans,ans);//找最大值
        }
    }
    cout<<aans+1<<endl;//输出
		
	return 0;

}