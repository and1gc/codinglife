/*#include <iostream>
#include <string>
#include <vector>

using namespace std;

void get_dfa(const string &pattern, vector<vector<int>> &dfa)
{
    dfa[pattern[0]][0] = 1;
    int x = 0, j = 1;
    for (; j < pattern.size(); ++j)
    {
        for (int index = 0; index < 256; ++index)
            dfa[index][j] = dfa[index][x];
        dfa[pattern[j]][j] = j + 1;
        x = dfa[pattern[j]][x];
    }
}

int kmp_dfa(const string& text, const string &pattern)
{
    vector<vector<int>> dfa(256, vector<int>(pattern.size()));
    get_dfa(pattern, dfa);
    int i = 0, j = 0;
    for (; i < text.size() && j < pattern.size(); ++i)
        j = dfa[text[i]][j];
    if (j == pattern.size())
        return i - pattern.size();
    else
        return text.size();
}

int main()
{
    cout << kmp_dfa("afdsafabababcfd", "abababc") << endl;
    while (1);
}*/