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
public:
    int get_min(TreeNode * root){
        if(root->left == nullptr) return root->val;
        else return get_min(root->left);
    }
    int get_max(TreeNode * root){
        if(root ->right == nullptr) return root->val;
        else return get_max(root->right);
    }
    bool isValidBST(TreeNode* root) {
        if(root == nullptr) return true;
        if(root->left != nullptr){
            if(root->val <= get_max(root->left)) return false;
        }
        if(root->right != nullptr){
            if(root->val >= get_min(root->right)) return false;
        }
        return isValidBST(root->left) && isValidBST(root->right);
        
    }
};