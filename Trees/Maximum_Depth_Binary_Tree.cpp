#include<iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr)
    {

    }
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
    public:
    int maxDepth(TreeNode *root)
    {
        if(root == nullptr)
            return 0;
        
            return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

int main()
{
    // Create sample tree:
    //        1
    //       / \
    //      2   3
    //     /
    //    4

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);

    Solution s;
    int depth = s.maxDepth(root);

    cout << "Maximum Depth of the Tree = " << depth << endl;

    return 0;
}