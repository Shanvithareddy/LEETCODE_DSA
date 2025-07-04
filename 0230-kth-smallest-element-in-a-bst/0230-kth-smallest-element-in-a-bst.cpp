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
    void get_els(vector<int> & nums, TreeNode * root){
        if(root == nullptr) return;
        get_els(nums,root->left);
        nums.push_back(root->val);
        get_els(nums,root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> nums;
        get_els(nums,root);
        return nums[k-1];
        
    }
};