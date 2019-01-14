#include <string>
#include <iostream>
#include <array>
#include <vector>
using namespace std;

string manacher(string str1)
{
    //第一步：加入特殊符号
    string str;
    int flag = 0;
    int ans = 0;
    for (const auto &p : str1)
    {
        str.push_back('#');
        str.push_back(p);
    }
    str.push_back('#');
    //第二步：得到含有特殊符号的最大回文序列
    vector<int> len(str.size(),1);
    int i = 0;
    int mx = 0;
    int id = 0;
    for (i = 1; i < str.size(); ++i)
    {
        if (mx > i)
        {
            len[i] = min(mx - i, len[2 * id - i]);
        }
        else
            len[i] = 1;
        while ((i - len[i]>=0)&& (i + len[i] <= str.size()-1)&&str[i - len[i]] == str[i + len[i]])
            ++len[i];
        if (len[i] + i > mx)
        {
            mx = len[i] + i;
            id = i;
            if (ans < len[i])
            {
                ans = len[i];
                flag = i;
            }
        }
        

    }
    //第三步：去除特殊符号
    str = str.substr(flag - len[flag]+1, 2 * len[flag] - 1);
    //string result;
    /*for (int i = 0; i < str.size(); ++i)
    {
        if (str[i] != '#')
            result.push_back(str[i]);
    }*/
    str.erase(remove(str.begin(), str.end(), '#'),str.end());
    return str;
}

int main()
{
    cout << manacher("habbafgh") << endl;
    while (1);
}