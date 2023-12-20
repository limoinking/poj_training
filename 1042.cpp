#include <iostream>
#include <cstring>
#include <climits>
#define N 25
using namespace std;
int main(void) 
{
    int n, h;
    int fi[N], di[N], ti[N];//fi[]期望钓鱼数， di[]每五分钟减少鱼数， ti[]位移时间
    int time[N];//在当前湖停下来时在每个湖停留的时间
    int best[N];//最优解对应的在每个湖停留的时间
    int bestFishNum;//最优解钓鱼总数
    int fishNum;//当前钓鱼总数
    while (cin >> n && n)
    {
        cin >> h;
        h *= 12;//共有h个5分钟
        for (int i = 0; i < n; i++) cin >> fi[i];//期望钓鱼数
        for (int i = 0; i < n; i++) cin >> di[i];//每五分钟减少鱼数
        for (int i = 0; i < n - 1; i++) cin >> ti[i];//位移时间
        bestFishNum = INT_MIN;
        memset(best , 0 , sizeof best);//将best数组的值全部设为0 
        for (int p = 0; p < n; p++) {//穷举最终停下的湖的位置
            memset(time , 0 , sizeof(time));
            fishNum = 0;
            int remainingTime = h;//当前剩余时间
            int remainingFish[N];//当前在每个湖剩余能钓的鱼的数目
            for (int i = 0; i < n; i++)
                remainingFish[i] = fi[i];//初始化
            for (int j = 0; j < p; j++)
                remainingTime -= ti[j];//先减去路程，之后假设John可以在lake 0到lake i之间随意位移
            while (remainingTime > 0) {//直到时间用尽
                int max = INT_MIN;
                int pos = 0;//当前能钓鱼最多的位置
                for (int j = 0; j <= p; j++)//每次选出能钓鱼最多的位置
                    if (remainingFish[j] > max) 
                    {
                        max = remainingFish[j];
                        pos = j;//找到位置
                    }
                time[pos]++;//对应时间++
                fishNum += remainingFish[pos];//累加钓鱼数
                remainingFish[pos] =remainingFish[pos]- di[pos]>0?remainingFish[pos]-di[pos]:0;
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
