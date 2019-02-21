#include <iostream>
#include <string>
#include <vector>

using namespace std;

void get_pi(const string &pattern, vector<int> &pi)
{
    pi[0] = 0;
    int k=0;
    for (int i = 1; i < pattern.size(); ++i)
    {
        while (k > 0 && pattern[k] != pattern[i])
            k = pi[k];
        if (pattern[k] == pattern[i])
            ++k;
        pi[i] = k;
    }
}

int kmp_pi(const string& text, const string &pattern)
{
    int k = 0;
    vector<int> pi(pattern.size());
    get_pi(pattern, pi);
    for (int i = 0; i < text.size(); ++i)
    {
        while (k > 0 && pattern[k] != text[i])
            k = pi[k];
        if (pattern[k] == text[i])
            ++k;
        if (k == pattern.size())
            return i - pattern.size()+1;
    }
    return text.size();
}

int main()
{
    cout << kmp_pi("0123456789ababacafd", "ababaca") << endl;
    while (1);
}