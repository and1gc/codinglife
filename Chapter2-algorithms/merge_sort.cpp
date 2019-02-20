#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
void merge(vector<int> &vec,int p,int q,int r)
{
    vector<int> temp(vec);
    int rindex = q + 1;
    int index = p;
    while (p <= q && rindex <= r)
    {
        if (temp[p] <= temp[rindex])
            vec[index++] = temp[p++];
        else
            vec[index++] = temp[rindex++];
    }
    while(p<=q)
        vec[index++] = temp[p++];
    while (rindex <= r)
        vec[index++] = temp[rindex++];
}
void mergesort(vector<int> &vec,int p,int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        mergesort(vec, p, q);
        mergesort(vec, q + 1, r);
        merge(vec, p, q, r);
    }
}
int main()
{
    vector<int> vec = { 3,5,122,54,444,7,9,1,0,35,2,6,11,5,44,22 };
    mergesort(vec, 0, vec.size() - 1);
    for_each(vec.begin(), vec.end(), [](const auto &p) {cout << p << " "; });
    
    while (1);
    return 0;
}