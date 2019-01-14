#include <iostream>
#include <queue>
#include <memory>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
using namespace std;

struct  TreeNode
{
    char ch;
    int freq;
    string code;
    shared_ptr<TreeNode> left;
    shared_ptr<TreeNode> right;
    TreeNode(char ch='?',int freq=0,string str=""):ch(ch),freq(freq),code(str),
        left(nullptr),right(nullptr){}
};

int main()
{
    auto cmp = [](shared_ptr<TreeNode> ch1, shared_ptr<TreeNode> ch2) {return ch1->freq > ch2->freq; };
    //vector<CH> vec{ {'a',45},{'b',13},{'c',12},{'d',16},{'e',9},{'f',5} };
    priority_queue<shared_ptr<TreeNode>, vector<shared_ptr<TreeNode>>, decltype(cmp)> Q(cmp);
    Q.push(make_shared<TreeNode>(TreeNode('a', 45))); 
    Q.push(make_shared<TreeNode>(TreeNode('b', 13)));
    Q.push(make_shared<TreeNode>(TreeNode('c', 12)));
    Q.push(make_shared<TreeNode>(TreeNode('d', 16)));
    Q.push(make_shared<TreeNode>(TreeNode('e', 9)));
    Q.push(make_shared<TreeNode>(TreeNode('f', 5)));

    int nums = Q.size();
    //得到huffman树
    while (nums>1)
    {
        
        shared_ptr<TreeNode> left, right;
        //shared_ptr<TreeNode> right = make_shared<TreeNode>();
        shared_ptr<TreeNode> z = make_shared<TreeNode>();
        /*left->ch= Q.top()->ch;
        left->freq = Q.top()->freq;
        left->code = "0";
        Q.pop();
        right->ch = Q.top()->ch;
        right->freq = Q.top()->freq;
        right->code = "1";
        Q.pop();*/
        left = Q.top();
        left->code = "0";
        z->left = left;
        Q.pop();
        right= Q.top();
        right->code = "1";
        z->right = right;
        Q.pop();
        z->freq = left->freq + right->freq;
        Q.push(z);
        --nums;
    }
    //得到huffman编码
    vector<pair<string,char>> code;
    queue<shared_ptr<TreeNode>> que;
    que.push(Q.top());
    while (!que.empty())
    {
        auto front = que.front();
        auto left = front->left;
        auto right = front->right;
        if (left)
        {
            left->code = front->code+left->code;
            que.push(left);
        }
        if (right)
        {
            right->code = front->code + right->code;
            que.push(right);
        }
        if(!left&&!right)
        {
            code.push_back({ front->code, front->ch });
        }




        que.pop();
    }

    for_each(code.begin(), code.end(), [](const auto &p) {cout << "character " << p.second << "  hfmcode is : " << p.first << endl; });
    while (1);
    return 0;
}