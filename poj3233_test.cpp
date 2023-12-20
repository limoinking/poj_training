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
typedef long long ll;
int n;
int mod;

struct Mar {
    ll a[100][100];
};


Mar mul(Mar a, Mar b) {
    Mar ret;
    for (int i = 1; i <= 2 * n; i++) {
        for (int j = 1; j <= 2 * n; j++) {
            ret.a[i][j] = 0;
            for (int k = 1; k <= 2 * n; k++) {
                ret.a[i][j] = (ret.a[i][j] + a.a[i][k] * b.a[k][j]) % mod;
            }
        }
    }
    return ret;
}


Mar powmod(Mar a, int b) {
    Mar ret;
    memset(ret.a, 0, sizeof(ret.a));
    for (int i = 0; i < 80; i++) ret.a[i][i] = 1;//初始化单位矩阵
    while (b) {
        if (b & 1)ret = mul(ret, a);
        a = mul(a, a);
        b >>= 1;
    }
    return ret;
}

int main() {
    //这个是对于公式中的A和S
    //其中S ^ k = [[A ^ k, A ^(k - 1) + A ^ (k - 2) + .. + E],[0,E]]
    //提取的部分在最右上角
    //原始矩阵为[[A,E],[0,E]]
    //构造的时候也有点技巧
    //注意矩阵的范围和n的范围
    Mar A, S;
    memset(A.a, 0, sizeof(A.a));
    int k;
    cin >> n >> k >> mod;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> A.a[i][j];
        }
        A.a[i][i + n] = 1;//右侧两个填入E
        A.a[i + n][i + n] = 1;
    }

    S = powmod(A, k + 1);//计算k + 1下的值

    for (int i = 1; i <= n; i++) {
        int flag = 0;
        for (int j = 1; j <= n; j++) {
            if (i == j)S.a[i][j + n]--;
            if (flag) cout << " ";
            flag = 1;
            cout << (S.a[i][j + n] + mod) % mod;
        }
        cout << endl;
    }
    return 0;
}