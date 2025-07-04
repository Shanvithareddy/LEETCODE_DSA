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
    // int INF = pow(10,5) + 1;
    // int get_min(TreeNode * root){
    //     if(root->left == nullptr) return root->val;
    //     else return get_min(root->left);
    // }
    // int get_max(TreeNode * root){
    //     if(root ->right == nullptr) return root->val;
    //     else return get_max(root->right);
    // }
    void get_els(vector<int> & nums, TreeNode * root){
        if(root == nullptr) return;
        get_els(nums,root->left);
        nums.push_back(root->val);
        get_els(nums,root->right);
    }




    int getMinimumDifference(TreeNode* root) {
        // // int minofRight;
        // // int maxofLeft;
        // if(root == nullptr) return INF;
        // int rootval = root->val;
        // int ans1 = INF;
        // int ans2 = INF;
        // if(root->left != nullptr){
        //     ans1 = rootval - get_max(root->left);
        //     // if(root-> right == nullptr) return ans1;
        // }
        // if(root->right != nullptr){
        //     ans2 = get_min(root->right) - rootval;
        // }
        
        // return min(min(ans1,ans2),min(getMinimumDifference(root->left),getMinimumDifference(root->right)));
        vector<int> nums;
        get_els(nums, root);
        int diff = nums[1] - nums[0];
        for(int i=2;i<nums.size();i++){
            int temp = nums[i] - nums[i-1];
            if(temp < diff) diff = temp;
        }
        return diff;
        
    }
};