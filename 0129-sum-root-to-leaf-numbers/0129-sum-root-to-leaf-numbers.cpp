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
    void modify(TreeNode * root){
        if(root == nullptr) return;
        if(root->right != nullptr) root->right->val += 10 * root->val;
        if(root->left != nullptr) root->left->val += 10 * root->val;
        modify(root->left);
        modify(root->right);
    }
    void get_leaves(TreeNode* root,vector<TreeNode*> &leaves){
        if(root == nullptr ) return;
        if(root->left == nullptr && root->right == nullptr) leaves.push_back(root);
        get_leaves(root->left,leaves);
        get_leaves(root->right,leaves);
    }
    int sumNumbers(TreeNode* root) {
        modify(root);
        vector<TreeNode*> leaves;
        get_leaves(root,leaves);
        int sum = 0;
        for(auto node: leaves){
            sum += node->val;
        }
        return sum;
    }
};