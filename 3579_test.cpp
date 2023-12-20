#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 100000 + 10;
int n,m;
int a[N];
bool judge(int x)
{
    int cnt = 0;
    for(int i = 0; i < n; i++)
        cnt += n - (lower_bound(a,a + n,a[i] + x) - a);//为啥要倒序加，因为要考虑的是
        //中值本身或者前一位
    return cnt > m;//当a[j] - a[i] >= x的数量超过半数时，表明这个数可能是中值或者更接近中值
    //让后一半处理
}
int main()
{

    while(~scanf("%d",&n)) {
        for(int i = 0; i < n; i++) scanf("%d",&a[i]);
        m = n * (n - 1) / 4;//c(n,2)个数的中值的位置
        sort(a,a + n);
        int l = 0,r = a[n - 1] - a[0];//二分搜索差值
        while(l < r - 1) {//最大化最小值
            int mid = (l + r) / 2;
            if(judge(mid)) l = mid;
            else r = mid;
        }
        printf("%d\n",l);
    }
    return 0;
}
