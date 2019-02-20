#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


#define left(x) (2*x+1)
#define right(x) (2*x+2)

//i表示结点，low和high分别表示范围
//维护堆的削智
void MaxHeapify(vector<int> &vec, int i, int low, int high)
{
    int l = left(i);
    int r = right(i);
    int maxindex;
    if (l <= high && vec[l] > vec[i])
        maxindex = l;
    else
        maxindex = i;
    if (r <= high && vec[r] > vec[maxindex])
        maxindex = r;

    if (maxindex != i)
    {
        swap(vec[maxindex], vec[i]);
        MaxHeapify(vec, maxindex, low, high);
    }
}

void BuildMaxHeap(vector<int> &vec)
{
    for (int i = vec.size()/2-1; i >= 0; --i)
    {
        MaxHeapify(vec, i, 0, vec.size()-1);
    }
}
void heapsort(vector<int> &vec)
{
    
    BuildMaxHeap(vec);
    for (int i = vec.size()-1; i >= 0; --i)
    {
        swap(vec[0], vec[i]);
        MaxHeapify(vec, 0, 0, i - 1);
    }

}

int main()
{
    vector<int> vec = { 2,1,5,7,9,4,0,3,8 };
    heapsort(vec);
    for_each(vec.begin(), vec.end(), [](const auto &p) {cout << p << " "; });
    while (1);
    return 0;
}