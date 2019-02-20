// TSPProblems.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <limits>
using namespace std;


int main()
{
    int citycounts = 4;
    vector<int> parents(citycounts, -1);
    //ͼ���ڽ�����
    vector<vector<int>> edges = 
    {
        {0, 1, 10},
        {1, 0, 10},
        {1, 3, 25},
        {3, 1, 25},
        {3, 2, 30},
        {2, 3, 30},
        {0, 2, 15},
        {2, 0, 15},
        {1, 2, 35},
        {2, 1, 35}    
    };
    //ת��Ϊ�ڽӾ���
    vector<vector<int>> map(citycounts,vector<int>(citycounts,INT_MAX));
    for (int i = 0; i < edges.size(); ++i)
    {
        map[edges[i][0]][edges[i][1]] = edges[i][2];
    }
    //����DP��
    vector<vector<int>> dp(citycounts, vector<int>(1<<(citycounts-1),INT_MAX));//-1��ʾȨ��Ϊ�����
    //ÿ�㵽0��·����С
    for (int i = 0; i < citycounts; ++i)
        dp[i][0] = map[i][0];
    //0��ÿ�����·����С
    /*for (int i = 0; i < citycounts; ++i)
        dp[0][i] = map[0][i] + dp[i][0];*/
    //���������У�j>=1
    for (int j = 1; j < 1 << (citycounts - 1); ++j)
    {
        int i = 0;
        for (; i < citycounts; ++i)
        {
            dp[i][j] = INT_MAX;
            if (((j >> (i - 1)) & 1) == 1)//����j�����Ƿ����i
                continue;
            for (int k = 1; k < citycounts; ++k)
            {
                if (((j >> (k-1)) & 1) == 0)//����j���治����k���Ͳ��ܽ���ѡ��
                    continue;
                if (map[i][k] == INT_MAX|| dp[k][j ^ (1 << (k - 1))]==INT_MAX)//i->k�߲�ͨ����k->m�߲�ͨʱ�򣬾�û�б�Ҫ�����ж���
                    continue;
                if (dp[i][j] > map[i][k] + dp[k][j ^ (1 << (k - 1))])
                {
                    dp[i][j] = map[i][k] + dp[k][j ^ (1 << (k - 1))];
                    parents[k] = i;
                }
            }
        }
    }

    //while (1);
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
