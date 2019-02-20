#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
void bubble_sort(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); ++i)
    {
        for (int j = 0; j < vec.size()-1; ++j)
        {
            if (vec[j] > vec[j+1])
                swap(vec[j],vec[j+1]);
        }
        
    }
}
int main()
{
    vector<int> vec = { 3,5,122,54,444,7,9,1,0,35,2,6,11,5,44,22 };
    bubble_sort(vec);
    for_each(vec.begin(), vec.end(), [](const auto &p) {cout << p << " "; });

    while (1);
    return 0;
}