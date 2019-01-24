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
        //��һ�������ҵ�Ҫ�����λ��
        int i = 0;
        while (vec[index] > vec[i])
            ++i;
        //�ڶ������ƶ�����
        while (i != tempindex)
        {
            vec[tempindex] = vec[tempindex - 1];
            --tempindex;
        }
        //������������
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