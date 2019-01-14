#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include <vector>
//#include <boost/compressed_pair.hpp>
using namespace std;

int i = 0;
static int nums = 0;
void permutation(string &str, int start,set<string> &result)
{
    if (start == str.size())
    {
        result.insert(str);
        //cout << ++i << endl;
    }
    else
    {
        for (int i = start; i < str.size(); ++i)
        {
            swap(str[i], str[start]);
            permutation(str, start + 1, result);
            swap(str[i], str[start]);
        }
    }
}

set<string> getpermutation(string  str)
{
    if (str.empty())
        return set<string>();
    set<string> result;
    permutation(str, 0,result);
    return result;
}

void combination(const string &str,int numbers ,int start,set<vector<char>> &result,vector<char> temp )
{
    if (numbers == 0)
    {
        result.insert(temp);
        /*for (const auto& iter : temp) 
        { cout << iter; }
        cout << endl;*/
        
    }
    else
    {
        for (int i = start; i < str.size(); ++i)
        {
            temp.push_back(str[i]);
            combination(str, numbers - 1, i + 1, result, temp);
            temp.pop_back();
        }
        
        
        
    }

}

set<vector<char>> getcombination(string str,int m)
{
    if (m > str.size())
        throw exception("cuowu");
    set<vector<char>> result;
    vector<char> temp;
    combination(str ,m ,0,result,temp);
    return result;
}

void calperm(const string &str, string &temp,int size)
{
    if (str.empty())
        return;
    if (size == str.size())
    {
        size = 0;
        cout << temp << endl;
        ++nums;
    }
    else
    {
        for (int i = 0; i < str.size(); ++i)
        {
            temp[size] = str[i];
            calperm(str, temp, size + 1);
        }
    }
}


int main()
{   
    /*string str = "abbcd";
    set<string> result = getpermutation(str);
    set<vector<char>> result1 = getcombination(str,3);
    for_each(result.begin(), result.end(), [](const auto& p) {cout << p << endl; });
    cout << "size: " << result.size() << endl;
    for_each(result1.begin(), result1.end(), [](const auto& p) {for (const auto& iter : p) { cout << iter;  }cout << endl; });
    cout << "size: " << result1.size() << endl;

    str = "1100";
    sort(str.begin(), str.end());
    
    do
    {
        cout << str << endl;
    } while (next_permutation(str.begin(), str.end()));

    string str1 = "11";
    sort(str1.begin(), str1.end());
    */
    
    string str1 = "abb";
    string temp(str1);
    calperm(str1, temp, 0);
    cout << nums << endl;
    while (1);

}