#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//$(OutDir)$(TargetName)$(TargetExt)
void insertion_sort(vector<int> &vec)
{
    for (int index = 1; index < vec.size(); ++index)
    {
        int temp = vec[index];
        int tempindex = index;
        //第一步：先找到要插入的位置
        int i = 0;
        while (vec[index] > vec[i])
            ++i;
        //第二步：移动数据
        while (i != tempindex)
        {
            vec[tempindex] = vec[tempindex - 1];
            --tempindex;
        }
        //第三步：插入
        vec[i] = temp;

    }
}

int main()
{
    vector<int> vec = { 2,1,5,7,9,4,0,3,8 };
    insertion_sort(vec);
    for_each(vec.begin(), vec.end(), [](const auto &p) {cout << p << " "; });
    while (1);
    return 0;
}