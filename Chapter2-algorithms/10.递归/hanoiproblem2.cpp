#include <iostream>
#include <stack>
#include <string>
#include <limits>
using namespace std;
using DIRECTION = string;
enum ACTION
{
    NO,
    LTOM,
    MTOL,
    MTOR,
    RTOM
};
int fstacktostack(ACTION &act, ACTION pre, ACTION now, stack<int> &fstack, stack<int> &tstack, DIRECTION from, DIRECTION to)
{
    if (act != pre && fstack.top() < tstack.top())
    {
        tstack.push(fstack.top());
        fstack.pop();
        cout << "move " << tstack.top() << " from " << from << " to " << to << endl;
        act = now;
        return 1;

    }
    return 0;
}
int hanoi(int num, DIRECTION left, DIRECTION mid, DIRECTION right)
{
    stack<int> ls;
    stack<int> ms;
    stack<int> rs;
    ls.push(INT_MAX);
    ms.push(INT_MAX);
    rs.push(INT_MAX);
    for (int i = num; i > 0; --i)
        ls.push(i);
    ACTION record = NO;
    int step = 0;
    while (rs.size() != num + 1)
    {
        step += fstacktostack(record, MTOL, LTOM, ls, ms, "LEFT", "MID");
        step += fstacktostack(record, LTOM, MTOL, ms, ls, "MID", "LEFT");
        step += fstacktostack(record, RTOM, MTOR, ms, rs, "MID", "RIGHT");
        step += fstacktostack(record, MTOR, RTOM, rs, ms, "RIGHT", "MID");

    }
    return step;
}

int main()
{
    hanoi(2, "LEFT", "MID", "RIGHT");
    int a[] ={ 5,10,15 };
    int *p = a;
    //cout << *p++ << endl;  //5
    //cout << *p++ << endl;
    //cout << (*p)++ << endl;
    ////cout << *(p++) << endl;   //5
    cout << *++p << endl;
    while (1);
    return 0;
}