#include<iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode* l, TreeNode* r): val(x), left(l), right(r){}
};

class Solution
{
    public:
    int diameterofBinaryTree(TreeNode* root)
    {
        int result = 0;
        dfs(root, result);
        return result;
    }

    int dfs(TreeNode* root, int &result)
    {
        if(root == nullptr)
            return 0;
        
        int left = dfs(root->left, result);
        int right = dfs(root->right, result);
        result = max(result, left + right);

        return 1 + max(left, right);

    }
};

int main() {
    // Example tree:
    //      1
    //     / \
    //    2   3
    //   / \
    //  4   5
    //
    // Diameter (number of edges on longest path) = 3 (path 4 -> 2 -> 1 -> 3)

    TreeNode* n4 = new TreeNode(4);
    TreeNode* n5 = new TreeNode(5);
    TreeNode* n2 = new TreeNode(2, n4, n5);
    TreeNode* n3 = new TreeNode(3);
    TreeNode* root = new TreeNode(1, n2, n3);

    Solution sol;
    int diameter = sol.diameterofBinaryTree(root);
    cout << "Diameter of binary tree (in edges): " << diameter << endl;

    delete n4;
    delete n5;
    delete n2;
    delete n3;
    delete root;

    return 0;
}