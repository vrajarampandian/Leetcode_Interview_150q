#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {

        if (root == nullptr)
            return nullptr;

        // Swap the left and right children
        swap(root->left, root->right);

        // Recursively invert left and right subtrees
        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};

// Helper function to print tree (preorder)
void printTree(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}

int main() {
    // Create a simple tree
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution s;
    cout << "Original Tree (Preorder): ";
    printTree(root);

    s.invertTree(root);

    cout << "\nInverted Tree (Preorder): ";
    printTree(root);

    return 0;
}
