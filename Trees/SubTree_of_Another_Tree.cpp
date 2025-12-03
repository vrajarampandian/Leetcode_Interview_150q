#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class solution
{
    public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!subRoot)
            return true;
        
        if(!root)
            return false;
        
        if (isSameTree(root, subRoot))
            return true;
        
        return isSubtree(root->left, subRoot) || isSubtree(root->right,subRoot);
    }
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if(!p && !q)
            return true;
        
        if(p && q && p->val == q->val)
        {
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
        else
        {
            return false;
        }
    }
};
int main() {
    /*
        Main Tree:
                 3
                / \
               4   5
              / \
             1   2

        Sub Tree:
               4
              / \
             1   2
    */

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);

    TreeNode* subRoot = new TreeNode(4);
    subRoot->left = new TreeNode(1);
    subRoot->right = new TreeNode(2);

    solution s;
    bool result = s.isSubtree(root, subRoot);

    if (result)
        cout << "subRoot is a subtree of root\n";
    else
        cout << "subRoot is NOT a subtree of root\n";

    return 0;
}

