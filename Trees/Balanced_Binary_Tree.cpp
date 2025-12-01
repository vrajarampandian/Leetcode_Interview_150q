#include<iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x ) : val(x),  left(nullptr), right(nullptr) {}
    TreeNode(int x , TreeNode* l, TreeNode* r):val(x), left(l), right(r){}
};

class solution
{
    public:
    int isbal(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        
        int l = isbal(root->left);
        if(l == -1)
            return -1;
        
        int r = isbal(root->right);
        if(r == -1)
            return -1;
        
        if(abs(l - r) > 1)
            return -1;
        else
            return max(l,r) + 1;
    }
    bool isBalanced(TreeNode * root)
    {
        if(isbal(root) == -1)
            return false;
        
        return true;
    }
};

int main()
{
    // Creating a balanced tree:
    //        1
    //      /   \
    //     2     3

    TreeNode *root = new TreeNode(1);
    root->left  = new TreeNode(2);
    root->right = new TreeNode(3);

    solution s;

    if (s.isBalanced(root))
        cout << "Tree is Balanced" << endl;
    else
        cout << "Tree is NOT Balanced" << endl;

    // Creating an unbalanced tree:
    //        1
    //       /
    //      2
    //     /
    //    3

    TreeNode *u = new TreeNode(1);
    u->left = new TreeNode(2);
    u->left->left = new TreeNode(3);

    if (s.isBalanced(u))
        cout << "Tree is Balanced" << endl;
    else
        cout << "Tree is NOT Balanced" << endl;

    return 0;
}