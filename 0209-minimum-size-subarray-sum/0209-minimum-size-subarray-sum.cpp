class Solution {
public:
    int maxSum(int w, vector<int>& nums){
        int sum = 0;
        for(int i=0;i<w;i++){
            sum += nums[i];
        }
        int max_sum = sum;
        for(int i=w;i<nums.size();i++){
            sum = sum - nums[i-w] + nums[i];
            if(sum > max_sum) max_sum = sum;
        }
        return max_sum;
    }
    int minSubArrayLen(int target, vector<int>& nums) {
        int low = 1;
        int high = nums.size();
        int mid;
        while(high > low){
            mid = (high + low)/2;
            if(maxSum(mid,nums) >= target) high = mid;
            else low = mid+1;
        }
        if(maxSum(low,nums)>=target) return low;
        else return 0;
    }
};