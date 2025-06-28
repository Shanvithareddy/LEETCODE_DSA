class Solution {
public:

    int maxAmount(int x,int y, vector<int> & ways,vector<int> & nums){
        if(x>y) return 0;
        if(ways[x] != -1) return ways[x];
        if(x == y) {
            ways[x] = nums[x];
            return ways[x];
        }
        ways[x] = max(maxAmount(x+2,y,ways,nums)+nums[x],maxAmount(x+1,y,ways,nums));
        return ways[x];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> ways(n,-1);
        return maxAmount(0,n-1,ways,nums);

    }
};