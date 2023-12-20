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
//不用真实写出表达式
//最多的可能为32 * length中计算可能
int p,q,r,s,t;//数字
char input[310];
int len;
bool StackSave(char input[])
{
    stack<int> st;//用一个数字栈去维护值
    //最后的答案就是栈顶的值
    for(int i = len - 1;i >= 0;i--)//由于栈的特性，这里应当使用倒序
    {
        //分情况写，如果为数字就直接压入栈
        //如果为大写字母
        //看看他是哪种字母
        char cur = input[i];
        if(cur == 'p')
        {
            st.push(p);
        }
        else if(cur == 'q')
        {
            st.push(q);
        }
        else if(cur == 'r')
        {
            st.push(r);
        }
        else if(cur == 's')
        {
            st.push(s);
        }
        else if(cur == 't')
        {
            st.push(t);
        }
        //K 对应K --> and:  x && y
        //   *A --> or:  x || y
        //   *N --> not :  ! x
        //   *C --> implies :  (!x)||y
        //   *E --> equals :  x==y
        else if(cur == 'K')//从这里开始就是简单的模拟就行了
        {
            int x = st.top();
            st.pop();
            int y = st.top();
            st.pop();
            st.push(x && y);

        }
        else if(cur == 'A')
        {
            int x = st.top();
            st.pop();
            int y = st.top();
            st.pop();
            st.push(x || y);
        }
        else if(cur == 'N')
        {
            int x = st.top();
            st.pop();
            st.push(!x);
        }
        else if(cur == 'C')
        {
            int x = st.top();
            st.pop();
            int y = st.top();
            st.pop();
            st.push((!x) || y);
        }
        else if(cur == 'E')
        {
            int x = st.top();
            st.pop();
            int y = st.top();
            st.pop();
            st.push(x == y);
        }
    }
    return st.top();
}
bool cal(char a[])
{
    // int p,q,r,s,t;//数字
    //枚举5个变量的值
    for(p = 0;p <= 1;p++)
    {
        for(q = 0;q <= 1;q++)
        {
            for(r = 0;r <= 1;r++)
            {
                for(s = 0;s <= 1;s++)
                {
                    for(t = 0;t <= 1;t++)
                    {
                        if(!StackSave(a))//发现不是永真的了
                        {
                            return false;
                        }
                    
                    }
                }
            }
        }
    }
    return true;
}
int main()
{
    memset(input,0,sizeof(input));
    while(cin >> input)
    {
        if(input[0] == '0')
        {
            return 0;
        }
        len = strlen(input);
        if(cal(input))
        {
            cout << "tautology" << endl;
        }
        else
        {
            cout << "not" << endl;
        }
        memset(input,0,sizeof(input));
    }
    return 0;
}