class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for(int i = 2;i<nums.size();i++){
            if(nums[i] == nums[i-1] && nums[i-1] == nums[i-2]){
                nums.erase(nums.begin()+i);
                i--;
            }
        }
        return nums.size();
    }
};