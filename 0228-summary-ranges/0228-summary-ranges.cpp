class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        if(nums.size() < 1) return result;
        int firstNum = nums[0];
        int i;
        for(i=1;i<nums.size();i++){
            if(nums[i] == nums[i-1]+1) continue;
            else{
                if(nums[i-1] == firstNum) {
                    string s = to_string(nums[i-1]);
                    result.push_back(s);
                }
                else{
                    string s = to_string(firstNum) + "->" + to_string(nums[i-1]);
                    result.push_back(s);
                }
                firstNum = nums[i];
                continue;
            }
        }
        i--;
        if(nums[i] == firstNum) {
            string s = to_string(nums[i]);
            result.push_back(s);
        }
        else{
            string s = to_string(firstNum) + "->" + to_string(nums[i]);
            result.push_back(s);
        }
        return result;
    }
};