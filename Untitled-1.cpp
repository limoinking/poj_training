#include <iostream>
using namespace std;
typedef long long ll;
#define N 101
ll dp[100010];
ll weight[N];

int main()
{
	ll sum = 0;
	ll n;
	cin >> n;

	dp[0] = 1;
	ll ans = 0;
	for (ll i = 0; i < n; i++)
	{
		cin >> weight[i];
		sum += weight[i];
	}
	for (ll i = 0; i < n; i++)
	{
		for (ll j = sum; j >= weight[i]; j--)
		{
			if (dp[j - weight[i]])
			{
				dp[j] = 1;//正的情况有了
			}
		}
	}
	//看看原本的一些情况能不能通过加上然后变成合理的情况
	for (ll i = 0; i < n; i++)
	{
		int size = sum - weight[i];
		for (ll j = 1; j <= size; j++)
		{
			dp[j] = max(dp[j], dp[j + weight[i]]);
		}
	}
	for (ll i = 1; i <= sum; i++)
	{
		if (dp[i])
		{
			ans++;
		}
	}
	cout << ans << endl;
	// 请在此输入您的代码
	return 0;
}