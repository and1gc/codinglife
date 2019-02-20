#include <string>
#include <iostream>

using namespace std;

using LOCATION = string;

int process(int num,LOCATION from, LOCATION to)
{
    if (num == 1)
    {
        if (from == "MID" || to == "MID")
        {
            cout << "move 1 from " << from << " to " << to << endl;
            return 1;
        }
        else
        {
            cout << "move 1 from " << from << " to MID"  << endl;
            cout << "move 1 from " << "MID"<< " to "<<to   << endl;
            return 1;
        }
    }
    if (from == "MID" || to == "MID")
    {
        LOCATION another = (from == "LEFT" || to == "LEFT") ? "RIGHT" : "LEFT";
        int part1 = process(num - 1, from, another);
        int part2 = 1;
        cout << "move "<<num<<" from " << from << " to " << another << endl;
        int part3 = process(num - 1, another, to);
    }
    else
    {
        int part1 = process(num - 1, from, to);
        int part2 = 1;
        cout << "move " << num << " from " << from << " to " << "MID" << endl;
        int part3 = process(num - 1, to, from);
        int part4 = 1;
        cout << "move " << num << " from " << "MID" << " to " << to << endl;
        int part5 = process(num - 1, from, to);
    }
}

int hanoi(int num,LOCATION from,LOCATION to)
{
    if (num < 1)
        return 0;
    return process(num, from, to);
}

int main()
{
    hanoi(2, "LEFT", "RIGHT");
    
    while (1);
    return 0;
}