#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
void selection_sort(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); ++i)
    {
        int tempmax = i;
        for (int j = i + 1; j < vec.size(); ++j)
        {
            if (vec[tempmax] > vec[j])
                tempmax = j;
        }
        swap(vec[i], vec[tempmax]);
    }
}
int main()
{
    vector<int> vec = { 3,5,122,54,444,7,9,1,0,35,2,6,11,5,44,22 };
    selection_sort(vec);
    for_each(vec.begin(), vec.end(), [](const auto &p) {cout << p << " "; });

    while (1);
    return 0;
}