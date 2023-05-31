#include <iostream>
#include <queue>

using namespace std;

// Definition for a binary tree node
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
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        queue<TreeNode *> q;
        q.push(root);
        int depth = 0;

        while (!q.empty())
        {
            int size = q.size();

            for (int i = 0; i < size; i++)
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
            }

            depth++;
        }

        return depth;
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
    // Create a binary tree [3,9,20,null,null,15,7]
    vector<int> nums = {3, 9, 20, -1, -1, 15, 7};
    TreeNode *root = createBinaryTree(nums, 0);

    // Create a solution object
    Solution solution;

    // Calculate the maximum depth of the binary tree
    int maxDepth = solution.maxDepth(root);
    cout << "Maximum Depth of Binary Tree: " << maxDepth << endl;

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
