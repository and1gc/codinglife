#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
using E = pair<int, int>;
//enum { a, b, c, d, e, f, g, h, i, j, N };
//enum {u,v,w,x,y,z,N1};
enum {s,a,b,c,d,e,f,g,N2};
enum COLOR
{
    WHITE,
    GRAY,
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
    vector<COLOR> color;//存储结点颜色
    vector<int> findtime;//发现的时间
    vector<int> endtime;//结束的时间
};

void DFS_visit(GRAPH &G,int p)
{
    G.time += 1;
    G.findtime[p] = G.time;
    G.color[p] = GRAY;
    for (auto it:G.edge[p])
    {
        if (G.color[it] == WHITE)
        {
            G.pi[it] = p;
            DFS_visit(G, it);
        }
    }
    G.color[p] = BLACK;
    G.time += 1;
    G.endtime[p] = G.time;
    cout << p << " ";
}

void DFS(GRAPH &G)
{
    for (int i = 0; i < G.N; ++i)
    {
        
        if (G.color[i] == WHITE)
            DFS_visit(G, i);  
    }
}

int main()
{
    //vector<E> edge = { {0,1},{0,6},{1,2},{1,5},{2,3},{2,4},{3,4},{5,6},{6,7},{7,8},{7,9},{8,9} };
    //vector<E> edge = { {0,1},{0,3},{1,4},{2,4},{2,5},{3,1},{4,3},{5,5} };
    vector<E> edge = { {0,1},{0,2},{1,3},{2,3},{2,4},{3,5},{3,6},{4,6},{5,7},{6,7} };
    GRAPH G;
    G.type = DIRECTED;
    G.N = N2;
    G.color.resize(G.N, WHITE);
    G.pi.resize(G.N,0);
    G.edge.resize(G.N);
    G.time = 0;
    G.findtime.resize(G.N,0);
    G.endtime.resize(G.N, 0);
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

    DFS(G);
    cout<<endl;
    for_each(G.pi.begin(), G.pi.end(), [](const auto &p) {cout << p << " "; });
    cout << endl;
    for_each(G.findtime.begin(), G.findtime.end(), [](const auto &p) {cout << p << " "; });
    cout << endl; 
    for_each(G.endtime.begin(), G.endtime.end(), [](const auto &p) {cout << p << " "; });
    cout << endl;

    while (1);
    return 0;
}