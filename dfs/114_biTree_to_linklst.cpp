#include "../pub.h"
using namespace std;

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
    void flatten(TreeNode* root) {
        TreeNode* cur = root;
        while (cur != nullptr) {
            if (cur->left == nullptr) {
                cur = cur->right;
            } else {
                TreeNode* preRight = cur->right;
                TreeNode* preLeft = cur->left;
                TreeNode* mostRight = preLeft;
                while (mostRight->right != nullptr) {
                    mostRight = mostRight -> right;
                }
                cur -> right = preLeft;
                mostRight -> right = preRight;
                cur -> left = nullptr;
                cur = cur -> right;
            }
        }
    }
};
