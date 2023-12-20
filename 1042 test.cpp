#include <iostream>
#include <cstring>
#include <climits>
#include <vector>
#include <queue>
#include <utility> // 包含 <utility> 头文件来使用 pair 类型
#define N 30
using namespace std;
//如果只取鱼的数目，三元组为最优的结果
//不然，还需要考虑停留的时间
struct Compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        // 按照第一个元素降序
        // 如果第一个元素相同，按照第二个元素升序
        if (a.first != b.first) {
            return a.first < b.first;
        }
        else {
            return a.second > b.second;
        }
    }
};

int n, h;
int main(void)
{
    int fi[N], di[N], ti[N];
    int time[N];
    int best[N];//最优解对应的在每个湖停留的时间
    int bestFishNum;//最优解钓鱼总数
    int fishNum;//当前钓鱼总数
    while (cin >> n && n)
    {
        cin >> h;
        h *= 12;
        for (int i = 0; i < n; i++)
            cin >> fi[i];
        for (int i = 0; i < n; i++)
            cin >> di[i];
        for (int i = 0; i < n - 1; i++)
            cin >> ti[i];
        bestFishNum = INT_MIN;
        memset(best, 0, sizeof best);
        for (int p = 0; p < n; p++) {//穷举最后停下来的位置
            priority_queue<pair<int, int>, vector<pair<int, int> >, Compare > q;
            memset(time, 0, sizeof(time));
            fishNum = 0;
            int remainingTime = h;//当前剩余时间
            int remainingFish[N];//当前在每个湖剩余能钓的鱼的数目
            for (int i = 0; i < n; i++)
                remainingFish[i] = fi[i];//初始化
            for (int j = 0; j < p; j++)
            {
                remainingTime -= ti[j];//先减去路程，之后假设John可以在lake 0到lake i之间随意位移
                
            }
            for (int j = 0; j <= p; j++)
            {
                q.push({ remainingFish[j],j });
            }
            while (remainingTime > 0) {//直到时间用尽


                int max = INT_MIN;
                int pos = 0;//当前能钓鱼最多的位置
                pair<int, int> cur = q.top();
                q.pop();
                pos = cur.second;
                time[pos]++;//对应时间++
                fishNum += remainingFish[pos];//累加钓鱼数
                remainingFish[pos] = remainingFish[pos] - di[pos] > 0 ? remainingFish[pos] - di[pos] : 0;
                q.push({ remainingFish[pos],pos });
                remainingTime--;
            }
            if (fishNum > bestFishNum)
            {
                bestFishNum = fishNum;
                for (int i = 0; i < n; i++)
                {
                    best[i] = time[i];
                }
            }
        }
        for (int i = 0; i < n - 1; i++)
            cout << best[i] * 5 << ", ";
        cout << best[n - 1] * 5 << endl;//注意输出格式
        cout << "Number of fish expected: " << bestFishNum << endl << endl;
    }
    return 0;
}
