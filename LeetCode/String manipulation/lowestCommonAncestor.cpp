#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *right;
    TreeNode *left;
    TreeNode(int v) : val(v), right(NULL), left(NULL)
    {
    }
};

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root->left == NULL ||
            root->right == NULL)
            return root;
        }
        
};