/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        int res = 0;
        process(root, L, R, res);
        return res;
    }
    
    void process(TreeNode* root, int L, int R, int& res) {
        if (root == nullptr)
            return;
        processNode(res, root, L, R);
        process(root->left, L, R, res);
        process(root->right, L, R, res);
    }
    
    void processNode(int& res, TreeNode* node, int L, int R) {
        if (node -> val >= L && node -> val <= R) {
            res += node->val;
        }
    }
};
