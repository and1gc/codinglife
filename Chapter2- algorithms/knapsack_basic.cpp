#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N = 4;//物品数目
    int V = 10;//体积大小
    vector<int> value = { 0,2,1,3,2 };
    vector<int> volume = { 0,3,2,4,2 };
    vector<vector<int>> dp(N + 1, vector<int>(V + 1, 0));
    vector<int> result;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= V; ++j)
        {
            dp[i][j] = dp[i - 1][j];
            if (volume[i] <= j && (dp[i - 1][j - volume[i]] + value[i]) > dp[i][j])
            {
                dp[i][j] = dp[i - 1][j - volume[i]] + value[i];
                
            }
        }
    }
    cout << dp[N][V] << endl;
    for (int i = N, j = V; i > 0 && j > 0;)
    {
        if (dp[i][j] == dp[i - 1][j - volume[i]]+ value[i])
        {
            result.push_back(i);
            
            j -= volume[i];
            --i;
        }
        else
            --i;
    }
    for_each(result.rbegin(), result.rend(), [](const auto &p) {cout << p << " "; });
    while (1);
    return 0;
}