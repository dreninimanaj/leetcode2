#include <iostream>
#include <vector>

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
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == nullptr && q == nullptr)
        {
            return true;
        }
        if (p == nullptr || q == nullptr)
        {
            return false;
        }
        if (p->val != q->val)
        {
            return false;
        }

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
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
    // Create two binary trees
    vector<int> nums1 = {1, 2, 3};
    TreeNode *p = createBinaryTree(nums1, 0);

    vector<int> nums2 = {1, 2, 3};
    TreeNode *q = createBinaryTree(nums2, 0);

    // Create a solution object
    Solution solution;

    // Check if the two trees are the same
    bool isSame = solution.isSameTree(p, q);
    if (isSame)
    {
        cout << "The two trees are the same." << endl;
    }
    else
    {
        cout << "The two trees are not the same." << endl;
    }

    // Clean up memory
    delete p;
    delete q;

    return 0;
};
