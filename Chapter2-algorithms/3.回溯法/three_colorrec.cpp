#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
using E = pair<int, int>;

enum NODE { a,b,c,d,e,N};
enum COLOR { NONE,RED, GREEN, BLUE };
//判断第k个点是不是有效的着色
bool isvalid(int k,const vector<E> &edge,vector<COLOR> &result)
{
    for (const auto &p : edge)
    {
        //找到结点k的相邻结点
        if (p.first == k || p.second==k)
        {
            if (result[p.first] == result[p.second])
                return false;
        }
    }
    return true;
}
void graphcolor(const vector<E> &edge, int k,bool &flag,vector<COLOR> &result)
{
    for (const auto &p : { RED,GREEN,BLUE })
    {
        if (flag == true)
            break;
        result[k] = p;
        if (k == result.size()-1 && isvalid(k,edge,result))
        {
            flag = true;
            break;
        }
        else if (isvalid(k,edge,result))
            graphcolor(edge, k + 1, flag, result);
    }
}
int main()
{
    //定义图的状态
    //vector<E> edge = { E{0,1},E{0,3},E{0,5},E{1,2},E{1,6},E{2,3},E{3,4},{4,6},{5,6} };
    vector<E> edge= {E{a,b},E{a,c},E{b,d},E{b,e},E{d,e},E{d,c},E{e,c}};
    //记录最终的结果
    vector<COLOR> result(7, NONE);

    bool flag = false;
    graphcolor(edge, a, flag,result);
    if (flag == true)
        for_each(result.begin(), result.end(), [](const auto &p) {cout << p << " "; });
    else
        cout << "no solution" << endl;
    while (1);
    return 0;
}
