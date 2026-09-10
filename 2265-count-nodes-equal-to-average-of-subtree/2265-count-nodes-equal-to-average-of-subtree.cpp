/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int matchingCount = 0;
    pair<int, int> postOrder(TreeNode* root) {
        if (!root) {
            return {0, 0};
        }

        auto [leftSum, leftCount] = postOrder(root->left);
        auto [rightSum, rightCount] = postOrder(root->right);

        int totalSum = root->val + leftSum + rightSum;
        int totalCount =1+leftCount+rightCount;

       
        if (totalSum / totalCount == root->val) {
            matchingCount++;
        }

        return {totalSum, totalCount};
    }

public:
    int averageOfSubtree(TreeNode* root) {
        matchingCount = 0;
        postOrder(root);
        return matchingCount;
    }
};