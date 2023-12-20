#include<iostream>
#include<algorithm>
#include<math.h>
#include <cstring>
#include <cstdio>
using namespace std;
typedef struct {
	double left;
	double right;
}Parition;
Parition s[1001];
bool cmp(Parition s1, Parition s2) {
	return s1.right < s2.right;//维护右区间保持不变
}
int main() {
	int i, n, d, x, y, flag, num = 1;
	double le;
	while (cin >> n >> d && n && d) {
		flag = 1;//用来判断是否有越界的情况
		if (n == 0 && d == 0)
			break;
		for (i = 0; i < n; i++) {
			cin >> x >> y;
			if (y > d)
				flag = -1;
			le = sqrt(pow((float)d, 2) - pow((float)y, 2));
			s[i].left = x - le;//用一段区间去维护
			s[i].right = x + le;
		}
		if (flag == -1) {
			cout << "Case " << num++ << ": " << flag << endl;
			continue;
		}
		sort(s, s + n, cmp);//s已经按照线段右侧进行了排序
		double tmp = s[0].right;//初始设置一个雷达//这个就是简单的区间合并
		for (i = 1; i < n; i++) {
			if (tmp >= s[i].left) {//当前值与上一个区间有重合
				continue;
			}
			else {
				flag++;
				tmp = s[i].right;
			}
		}
		cout <<"Case "<< num++ <<": "<< flag << endl;
	}
    return 0;
}
