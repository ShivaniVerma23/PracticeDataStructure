#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};
class Solution
{
public:
    vector<int> preorder(Node *root)
    {
        vector<int> result;

        preorderPath(root, result);

        return result;
    }
    vector<int> preorderPath(Node *root, vector<int> &path)
    {
        if (root == NULL)
            return path;
        path.push_back(root->val);

        for (int i = 0; i < root->children.size(); i++)
        {
            preorderPath(root->children[i], path);
        }
        return path;
    }
};

int main()
{
    Node* input =  new Node();
    Solution sln;
    vector<int> ans;
    ans = sln.preorder(input);

    for(auto it : ans)
      cout <<ans[it]<< " "<<endl;
}