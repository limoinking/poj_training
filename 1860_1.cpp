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
	//����Ҫ��y����ͬһ����
	sort(y + 1, y + n + 1);
	mid = y[(n + 1) / 2];//����֤�������м�������䵽��Χ�ĵ�ľ���֮�Ͷ�����ȵ�
	//��Ϊ��û�м�Ȩ�ģ�����ȡ�������˵ĵ㶼����
	for (int i = 1; i <= n; i++)
	{
		disy += abs(y[i] - mid);
	}
	//���ڶ�x���в���
	sort(x + 1, x + n + 1);
	for (int i = 1; i <= n; i++)
	{
		x[i] -= (i + 2);//�����Ϳ��Խ�x���һ����1Ϊ��������
	}
	//��������Ϊ��ʽ
	// ��ǰ����Ϊx1,x2,x3,x4..
	// ����λ��Ϊx0 + 1,x0 + 2,x0 + 3....
	// �ƶ��ľ���Ϊ
	// |x1 - (x0 + 1)| + |x2 - (x0 + 2)|
	// |(x1 - 1) - x0| + |(x2 - 2) -x0|//ע�⣬�������λ��
	// Ӧ���Ǽ���֮�����λ��
	// �����ΪɶҪ��һ��i��ԭ��������i - 2Ҳ��һ����
	// �����ƶ��������
	// x0������λ��
	//����ע�⵽����Щ����Ҫ��ͬһ����Ϊ���Ȼ���и������
	sort(x + 1, x + n + 1);
	mid = x[(n + 1) / 2];
	for (int i = 1; i <= n; i++)
	{
		disx += abs(x[i] - mid);
	}
	cout << disx + disy << endl;
	return 0;
}