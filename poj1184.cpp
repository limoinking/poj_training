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
#include <string>
using namespace std;
//题目分析：在状态的最后一位补一个记录光标然后BFS，两个剪枝

//1.Up，Down只有在当前位和目标位不同时才进行，这是显然的

//2.Left，Right时只有中间四位和目标位相同时才进行，因为移动光标不会影响数字的状态，因此数字位不同时，只移动光标没有什么意义


struct NODE
{
    string s;
    int step;
};//用来记录每一次的情况和目标之间的差距
//和8数码问题很像
//但是不能很好的写出估价函数，所以这里还是采用BFS的模式

string ed, change;
queue <NODE> q;
map <string, bool> mp;

//每一次都会分出很多枝叶出来
//但是核心的剪枝过程就是
//如果这个状态达到过，那就不用搜索了
//两个复杂度都是很高的
int BFS(NODE st)
{
    //使用BFS
    q.push(st);
    while(!q.empty())
    {
        NODE cur = q.front(), next;
        q.pop();
        bool flag = true;
        for(int i = 0; i < 6; i++)
        {
            if(cur.s[i] != ed[i])
            {
                flag = false;
                break;
            }
        }
        if(flag)
            return cur.step;//看看本次是否每一位都对的上
        
        change = cur.s;
        //检验一下如果使用swap1得到结果
        //并且看看是否之前达到过的的状态
        //如果是之前到达过的状态
        //肯定是不优的，因为次数更多，达到了一个之前达到过的状态
        int idx = cur.s[6] - '0';
        if(idx != 0)
            swap(change[0], change[idx]);
        
        if(!mp.count(change))
        {
            next.s = change;
            next.step = cur.step + 1;
            q.push(next);
            mp[next.s] = true;
        }

        //检验一下如果使用swap2得到的结果
        
        change = cur.s;
        idx = cur.s[6] - '0';
        if(idx != 5)
            swap(change[5], change[idx]);
        if(!mp.count(change))
        {
            next.s = change;
            next.step = cur.step + 1;
            q.push(next);
            mp[next.s] = true;
        }

        //使用减位进行操作
        change = cur.s;
        idx = cur.s[6] - '0';
        if(change[idx] != '9' && change[idx] != ed[idx])
            change[idx] += 1;
        if(!mp.count(change))
        {
            next.s = change;
            next.step = cur.step + 1;
            q.push(next);
            mp[next.s] = true;
        }

        //使用加位进行操作
        change = cur.s;
        idx = cur.s[6] - '0';
        if(change[idx] != '0' && change[idx] != ed[idx])
            change[idx] -= 1;
        if(!mp.count(change))
        {
            next.s = change;
            next.step = cur.step + 1;
            q.push(next);
            mp[next.s] = true;
        }

        //光标左移操作
        change = cur.s;
        idx = cur.s[6] - '0';
        if(idx != 0)
        {
            if(idx == 5)
                change[6] -= 1;
            else if(change[idx] == ed[idx])
                change[6] -= 1;
        }       
        if(!mp.count(change))
        {
            next.s = change;
            next.step = cur.step + 1;
            q.push(next);
            mp[next.s] = true;
        }

        //光标右移操作
        change = cur.s;
        idx = cur.s[6] - '0';
        if(idx != 5)
        {
            if(idx == 0)
                change[6] += 1;
            else if(change[idx] == ed[idx])
                change[6] += 1;
        }
        if(!mp.count(change))
        {
            next.s = change;
            next.step = cur.step + 1;
            q.push(next);
            mp[next.s] = true;
        }
    }
    return 0;
}

int main()
{
    NODE st;
    while(cin >> st.s >> ed)
    {
        while(!q.empty())
            q.pop();
        mp.clear();
        st.s += '0';//这个是记录当前光标的位置的
        st.step = 0;
        mp[st.s] = true;
        int ans = BFS(st);
        printf("%d\n", ans);
    }   
}