#include <iostream>
#include <queue>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        if (root == nullptr)
        {
            return true;
        }

        return isMirror(root->left, root->right);
    }

private:
    bool isMirror(TreeNode *leftNode, TreeNode *rightNode)
    {
        if (leftNode == nullptr && rightNode == nullptr)
        {
            return true;
        }

        if (leftNode == nullptr || rightNode == nullptr)
        {
            return false;
        }

        return (leftNode->val == rightNode->val) &&
               isMirror(leftNode->left, rightNode->right) &&
               isMirror(leftNode->right, rightNode->left);
    }
};

// Helper function to create a binary tree
TreeNode *createBinaryTree(vector<int> &nums, int idx)
{
    if (idx >= nums.size() || nums[idx] == -1)
    {
        return nullptr;
    }

    TreeNode *root = new TreeNode(nums[idx]);
    root->left = createBinaryTree(nums, 2 * idx + 1);
    root->right = createBinaryTree(nums, 2 * idx + 2);

    return root;
}

int main()
{
    // Create a binary tree [1,2,2,3,4,4,3]
    vector<int> nums = {1, 2, 2, 3, 4, 4, 3};
    TreeNode *root = createBinaryTree(nums, 0);

    // Create a solution object
    Solution solution;

    // Check if the binary tree is symmetric
    bool isSymmetric = solution.isSymmetric(root);
    cout << "Is the Binary Tree Symmetric? " << (isSymmetric ? "Yes" : "No") << endl;

    // Clean up memory
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();
        if (node->left)
        {
            q.push(node->left);
        }
        if (node->right)
        {
            q.push(node->right);
        }
        delete node;
    }

    return 0;
}
