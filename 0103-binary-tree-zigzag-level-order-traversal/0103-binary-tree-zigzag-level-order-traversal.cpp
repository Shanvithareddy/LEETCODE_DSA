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
    void bfs( vector<TreeNode *> curr_lev, vector<vector<int>> & levels,int order){
        if(curr_lev.empty()) return;
        vector<int> curr_vals;
        vector<TreeNode *> new_lev;
        if(order == 1){
            for(int i= curr_lev.size()-1;i>=0;i--){
                curr_vals.push_back(curr_lev[i]->val);
            }
        }
        else{
            for(int i=0;i<curr_lev.size();i++){
                curr_vals.push_back(curr_lev[i]->val);
            }
        }
        levels.push_back(curr_vals);
        for(auto node: curr_lev){
            // curr_vals.push_back(node->val);
            if(node->left != nullptr) new_lev.push_back(node->left);
            if(node->right != nullptr) new_lev.push_back(node->right);
        }
        bfs(new_lev,levels,1^order);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> levels;
        vector<TreeNode*> curr_lev;
        if(root != nullptr) curr_lev.push_back(root);
        bfs(curr_lev,levels,0);
        return levels;
    }
};