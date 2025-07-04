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
    void bfs( vector<TreeNode *> &curr_lev, vector<double> & avgs){
        if(curr_lev.empty()) return;
        double sum = 0;
        for(auto node : curr_lev){
            sum += node->val;
        }
        avgs.push_back(sum/curr_lev.size());
        vector<TreeNode *> new_lev;
        for(auto node: curr_lev){
            if(node->left != nullptr) new_lev.push_back(node->left);
            if(node->right != nullptr) new_lev.push_back(node->right);
        }
        bfs(new_lev,avgs);
    }
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> avgs;
        vector<TreeNode *> curr_lev;
        if(root != nullptr) curr_lev.push_back(root);
        bfs(curr_lev,avgs);
        return avgs;

    }
};