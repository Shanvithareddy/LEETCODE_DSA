class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        // int n = nums.size();
        // for(int i=0;i<k;i++){
        //     int temp = nums.back();
        //     nums.erase(nums.end());
        //     nums.insert(nums.begin(),temp);
        // }
        if( k == 0 ) return;
        vector<int> temp;
        temp.assign(nums.end()-k , nums.end());
        nums.erase(nums.end()-k , nums.end());
        nums.insert(nums.begin(),temp.cbegin(),temp.cend());
    }
};