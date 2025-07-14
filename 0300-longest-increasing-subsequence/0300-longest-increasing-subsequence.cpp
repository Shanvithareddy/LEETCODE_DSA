class Solution {
public:
    int fillLIS(int k, vector<int>&nums, vector<int>& LIS){
        if(LIS[k]!=0) return LIS[k];
        LIS[k] = 1;
        for(int i =0;i<k;i++){
            int temp = fillLIS(i,nums,LIS);
            if(nums[i] < nums[k]) LIS[k] = max(LIS[k],+temp+1);
            // else LIS[k] = max(LIS[k],fillLIS(i,nums,LIS
        }
        return LIS[k];
    }
    // void print_vector(vector<int>& lis){
    //     for(auto el: lis){
    //         cout<<el<<",";
    //     }
    //     cout<<endl;
    // }



    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> LIS(n,0);
        LIS[0] = 1;
        int k = fillLIS(n-1,nums,LIS);
        for(int i=0;i<n;i++){
            if(LIS[i]>k) k = LIS[i];
        }
        // if(n>6) cout<<LIS[6]<<endl;
        // print_vector(LIS);
        return k;
    }
};