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
#define M 31
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7;
const int N = 31;
const int INF = 0x3f3f3f3f;
ll qpow(ll base, ll n){ll ans = 1; while (n){if (n & 1) ans = ans * base % mod; base = base * base % mod; n >>= 1;} return ans;}
ll gcd(ll a, ll b){return b ? gcd(b, a % b) : a;}
 
int main()
{
	int n;
	while (cin >> n && n){
		int num[6] = {};
		for (int i = 1; i <= n; ++ i){
			cin >> num[i];
		}
		ll f[num[1] + 1][num[2] + 1][num[3] + 1][num[4] + 1][num[5] + 1];
		memset(f, 0, sizeof(f));
		//fill_n(f[0][0][0][0], (num[1] + 1) * (num[2] + 1) * (num[3] + 1) * (num[4] + 1) * (num[5] + 1), 0);
		f[0][0][0][0][0] = 1;
		for (int a = 0; a <= num[1]; ++ a){
			for (int b = 0; b <= num[2]; ++ b){
				for (int c = 0; c <= num[3]; ++ c){
					for (int d = 0; d <= num[4]; ++ d){
						for (int e = 0; e <= num[5]; ++ e){
							ll &x = f[a][b][c][d][e];
							if (a && a - 1 >= b) x += f[a - 1][b][c][d][e];
							if (b && b - 1 >= c) x += f[a][b - 1][c][d][e];
							if (c && c - 1 >= d) x += f[a][b][c - 1][d][e];
							if (d && d - 1 >= e) x += f[a][b][c][d - 1][e];
							if (e) x += f[a][b][c][d][e - 1];
 
						}
					}
				}
			}
		}
		cout << f[num[1]][num[2]][num[3]][num[4]][num[5]] << '\n';
	}
	return 0;
}
