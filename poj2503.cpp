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
int main()
{
    map<string,string> dic;
     std::string line;
    
    // 逐行读取输入
    while (std::getline(std::cin, line)) {
        if (line.empty()) {
            break;
        } else {
            // 读取单词
            int pos = line.find(' ');
            string a = line.substr(0,pos);
            string b = line.substr(pos+1);
            dic[b] = a;
        }
    }

    while (cin >> line) 
    {
        if(dic.find(line) != dic.end())
        {
            cout << dic[line] << endl;
        }
        else
        {
            cout << "eh" << endl;
        }
    }
    return 0;
}