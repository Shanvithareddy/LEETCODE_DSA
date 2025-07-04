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
    void get_els(vector<int> & nums, TreeNode * root,int k){
        if(root == nullptr) return;
        if(nums.size() < k) get_els(nums,root->left,k);
        if(nums.size() < k) nums.push_back(root->val);
        if(nums.size() < k) get_els(nums,root->right,k);
        return;
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> nums;
        get_els(nums,root,k);
        return nums[k-1];
        
    }
};