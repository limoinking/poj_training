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
using namespace std;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
struct Node{
	int x;
    int y;
}a[N];
int x[N],y[N];
int minn,plan = 0;
int res = 0;

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int main()
{
    int n;
    n = read();
    for(int i = 0;i < n;i++)
    {
        //结构体是用来记录原始数据的
        //因为分别对x,y排序破坏了原有结构
        a[i].x = read();
        x[i] = a[i].x;
        a[i].y = read();
        y[i] = a[i].y;//记录原始的x,y和要改变的xy
    }
    //如果是奇数的话
    //看看这个点是不是和牛所在点重合，如果重合要重新计算距离
    sort(x,x + n);//排序，分别寻找中位数
    sort(y,y + n);
    if(n % 2)//如果为奇数的话
    {
        int tmid = n/2;
        for(int i = 0;i <n;i++)
        {
            if(a[i].x == x[tmid] && a[i].y == y[tmid])
            {
                //如果为牛棚的话
                int minl = inf;
                for(int j = 0;j < 4;j++)//曼哈顿距离不是欧式距离
                //证明为什么的话
                //就是在增大某一个方向的值的情况下
                //另一个方向不变
                //不然就是两个方向都在变就是不对的
                //可以不用管四个对角格子
                {
                    int curx = x[tmid] + dx[j];
                    int cury = y[tmid] + dy[j];
                    int sum = 0;
                    for(int k = 0;k < n;k++)
                    {
                        sum += abs(curx - a[k].x) + abs(cury - a[k].y);
                    }
                    if(sum < minl)
                    {
                        minl = sum;
                        plan = 1;
                    }
                    else if(sum == minl)
                    {
                        plan++;
                    }
                }
                printf("%d %d\n",minl,plan);
                return 0;
            }
            else//如果非牛棚点
            {
                res += abs(a[i].x - x[tmid]) + abs(a[i].y - y[tmid]);
                plan = 1;
            }
        }
        printf("%d %d\n",res,plan);
    }
    else
    {
        //为偶数的时候
        //0 1 2 3 4 5
        //n/2 ,n/2 + 1为两个中间值
        int mid1 = n/2 - 1,mid2 = n/2;
        //可以由题中案例可知
        //在这个方形区域内的所有点都可以
        //但是唯独不能在牛棚上搭建
        //所以将在这个区域内有牛棚的点减去即可
        plan = (x[mid2] - x[mid1] + 1) * (y[mid2] - y[mid1] + 1);
        for(int i = 0;i < n;i++)
        {
            res += abs(a[i].x - x[mid1]) + abs(a[i].y - y[mid1]);
            int x0 = a[i].x,y0 = a[i].y;
            if(x[mid1] <= x0 && x0 <= x[mid2] && y[mid1] <= y0 && y0 <= y[mid2])
            {
                plan--;
            }
            
            //这里可以
        }
        printf("%d %d\n",res,plan);
    }
    return 0;
}

