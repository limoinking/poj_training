
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 10;
const ll INF = 0x3f3f3f3f3f3f3f3f;
 
struct Point {
    double x, y;
    int flag;
}p[MAXN], q[MAXN];
 
bool cmpx(const Point &a, const Point &b) {
    return a.x < b.x;
}
 
bool cmpy(const Point &a, const Point &b) {
    return a.y < b.y;
}
 
double dist(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
 
double solve(int l, int r) {
    if (l == r) return INF;
    if (l + 1 == r) {
        if (p[l].flag != p[r].flag) return dist(p[l], p[r]);
        return INF;
    }
    int m = (l + r) >> 1;
    double res = min(solve(l, m), solve(m + 1, r));
    int cnt = 0;
    for (int i = l; i <= r; i++)
        if (fabs(p[i].x - p[m].y) <= res) q[++cnt] = p[i];
    for (int i = 1; i <= cnt; i++) {
        for (int j = i + 1; j <= cnt; j++) {
            if (q[i].flag != q[j].flag)
                res = min(res, dist(q[i], q[j]));
        }
    }
    return res;
}
 
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%lf%lf", &p[i].x, &p[i].y);
            p[i].flag = 0;
        }
        for (int i = n + 1; i <= 2 * n; i++) {
            scanf("%lf%lf", &p[i].x, &p[i].y);
            p[i].flag = 1;
        }
        sort (p + 1, p + 1 + 2 * n, cmpx);
        printf("%.3f\n", solve(1, 2 * n));
    }
    return 0;
}