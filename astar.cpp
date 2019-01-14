#include<vector>
#include<iostream>
#include <utility>
#include <queue>
using namespace std;

using mypair = pair<int, int>;

struct POINT
{
    mypair coord;
    bool isTraveled;
    bool isBlocked;
    int distance;
    mypair formercoord;
    POINT(int x=0,int y=0, bool isdone=false, bool isblocked=false,int distance=0):
        isTraveled(isdone),isBlocked(isblocked),distance(distance)
    {
        coord.first = x;
        coord.second = y;
        formercoord.first = x;
        formercoord.second = y;
    }
};
bool IsinBarrier( POINT &p, const vector<mypair> &barrier)
{
    for (const auto &it:barrier)
    {
        if (p.coord.first == it.first&&p.coord.second == it.second)
            return true;
    }
    return false;
}
int main()
{
    int rows = 7;
    int cols = 7;
    mypair start = { 1,6 };
    mypair end = { 7,3 };
    vector<mypair> barrier = { {1,3},{2,5},{2,6},{2,7},{3,2},{5,2},{5,3},{5,4},{6,3}, {6,5},{6,7},{7,2},{7,4} };
    //第一步：构建地图
    vector<vector<POINT>> map(cols+1,vector<POINT>(rows+1));
    for(int i=0;i<=cols;++i)
        for (int j = 0; j <= rows; ++j)
        {
            map[i][j].coord = { i,j };
            if (IsinBarrier(map[i][j], barrier))
                map[i][j].isBlocked = true;
            
        }
    //第二步：使用A*进行扩散
    queue<POINT> path;
    path.push(POINT(start.first, start.second));
    while (!path.empty())
    {
        POINT current = path.front();
        int i = current.coord.first;
        int j = current.coord.second;
        map[i][j].isTraveled = true;
        //向上
        if (j - 1 >= 0                          //在界内
            && !map[i][j - 1].isBlocked        //不是障碍
            && !map[i][j - 1].isTraveled)      //没有被遍历
        {
            map[i][j - 1].isTraveled = true;
            map[i][j - 1].distance = current.distance + 1;
            map[i][j - 1].formercoord = { i,j };
            if (end.first == i && end.second == j-1)
                break;
            path.push(map[i][j - 1]);
        }
        //向左
        if (i - 1 >= 0                        //在界内
            && !map[i-1][j].isBlocked        //不是障碍
            && !map[i-1][j].isTraveled)      //没有被遍历
        {
            map[i-1][j].isTraveled = true;
            map[i-1][j].distance = current.distance + 1;
            map[i-1][j].formercoord = { i,j };
            if (end.first == i-1 && end.second == j)
                break;
            path.push(map[i-1][j]);
        }
        //向下
        if (j + 1 <= rows                          //在界内
            && !map[i][j + 1].isBlocked        //不是障碍
            && !map[i][j + 1].isTraveled)      //没有被遍历
        {
            map[i][j + 1].isTraveled = true;
            map[i][j + 1].distance = current.distance + 1;
            map[i][j + 1].formercoord = { i,j };
            if (end.first == i && end.second == j+1)
                break;
            path.push(map[i][j + 1]);
        }
        //向右
        if (i + 1 <=cols                        //在界内
            && !map[i + 1][j].isBlocked        //不是障碍
            && !map[i + 1][j].isTraveled)      //没有被遍历
        {
            map[i + 1][j].isTraveled = true;
            map[i + 1][j].distance = current.distance + 1;
            map[i + 1][j].formercoord = { i,j };
            if (end.first == i+1 && end.second == j)
                break;
            path.push(map[i + 1][j]);
        }
        path.pop();
    }
    int x = end.first;
    int y = end.second;
    if (map[x][y].distance > 0)
    {
        while (x != start.first || y != start.second)
        {
            cout << "(" << x << "," << y << ")<--";
            int tempx = map[x][y].formercoord.first;
            int tempy = map[x][y].formercoord.second;
            x = tempx;
            y = tempy;
        }
        cout << "(" << x << "," << y << ")" << endl;
    }
    else
        cout << "no way out!" << endl;
    while (1);
}