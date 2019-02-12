#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
using E = pair<int, int>;
enum { a, b, c, d, e, f, g, h, i, j, N };

enum COLOR
{
    WHITE,
    BLACK
};
enum GRAPHTYPE
{
    DIRECTED,
    UNDIRECTED
};
struct GRAPH
{
    GRAPHTYPE type;
    int N;//结点数
    int time;//时间流
    vector<vector<int>> edge;//存储边的信息，有向边或者无向边
    vector<int> pi;//存储父结点
    vector<COLOR> color;
    vector<int> findtime;//发现的时间
    vector<int> endtime;//结束的时间
};

void BFS_visit(GRAPH &G, queue<int> &Q, int p)
{
    G.time += 1;
    Q.push(p);
    G.color[p] = BLACK;
    while (!Q.empty())
    {
        int v = Q.front();
        Q.pop();
        G.findtime[v] = G.time;
        G.time += 1;
        for (auto it : G.edge[v])
        {
            if (G.color[it] == WHITE)
            {
                Q.push(it);
                G.color[it] = BLACK;
                G.pi[it] = v;
            }
        }
    }
}

void BFS(GRAPH &G)
{
    queue<int> Q;
    for (int i = 0; i < G.N; ++i)
    {

        if (G.color[i] == WHITE)
            BFS_visit(G,Q, i);
    }
}
int main()
{
    vector<E> edge = { {0,1},{0,6},{1,2},{1,5},{2,3},{2,4},{3,4},{5,6},{6,7},{7,8},{7,9},{8,9} };
    
    GRAPH G;
    G.type = UNDIRECTED;
    G.N = N;
    G.pi.resize(G.N, 0);
    G.color.resize(G.N, WHITE);
    G.edge.resize(G.N);
    G.time = 0;
    G.findtime.resize(G.N, 0);
    //G.endtime.resize(G.N, 0);
    for (const auto p : edge)
    {
        if (G.type == UNDIRECTED)
        {
            G.edge[p.first].push_back(p.second);
            G.edge[p.second].push_back(p.first);
        }
        else
            G.edge[p.first].push_back(p.second);
    }

    BFS(G);
    cout << endl;
    for_each(G.pi.begin(), G.pi.end(), [](const auto &p) {cout << p << " "; });
    cout << endl;
    for_each(G.findtime.begin(), G.findtime.end(), [](const auto &p) {cout << p << " "; });
    cout << endl;
    //for_each(G.endtime.begin(), G.endtime.end(), [](const auto &p) {cout << p << " "; });
    //cout << endl;

    while (1);
    return 0;
}