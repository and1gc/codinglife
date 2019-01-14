#include <iostream>
#include <string>
#include <vector>
#include <boost\graph\dijkstra_shortest_paths.hpp>
using namespace std;

enum WAY{
    NONE,
    LEFT_UP,
    LEFT,
    UP
};

vector<vector<WAY>> findlcs(const string & x, const string &y)
{
    vector<vector<int>> temp(x.size()+1, vector<int>(y.size()+1, 0));
    vector<vector<WAY>> towards(x.size()+1, vector<WAY>(y.size()+1,NONE));
    for(int i=1;i<=x.size();++i)
        for (int j = 1; j <= y.size(); ++j)
        {
            if (x[i - 1] == y[j - 1])
            {
                temp[i][j] = temp[i - 1][j - 1] + 1;
                towards[i][j] =LEFT_UP;
            }
            else if (temp[i][j - 1] > temp[i - 1][j])
            {
                temp[i][j] = temp[i][j - 1];
                towards[i][j] = UP;
            }
            else
            {
                temp[i][j] = temp[i - 1][j];
                towards[i][j] =LEFT;
            }
        }

    return towards;
}

void printlcs(const vector<vector<WAY>> &towards,const string& x,int i,int j)
{
    if (i == 0 || j == 0)
        return;
    if (towards[i][j] == LEFT_UP)
    {
        printlcs(towards,x, i - 1, j - 1);
        cout << x[i - 1];
    }
    else if (towards[i][j] == UP)
        printlcs(towards, x, i, j-1);
    else
        printlcs(towards, x, i - 1, j );
}
int main()
{
    string x = "ABCBDAB", y = "BCBDAB";
    vector<vector<WAY>> towards=findlcs(x, y);
    printlcs(towards, x, x.size(), y.size());
    cout << endl;
    vector<string> ss;
    string a;
    while (cin >> a,a!="eof")
        ss.push_back(a);
    cout << ss.size() << endl;
    return 0;
}