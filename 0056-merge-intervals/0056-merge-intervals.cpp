class Solution {
public:
    static bool comp(vector<int> first, vector<int> second){
        return first[0] < second[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        int n = intervals.size();
        // struct
        // {
        //     bool operator()(vector<int> first, vector<int> second)const{ return first[0]<second[0]; }
        // }comp;
        sort(intervals.begin(),intervals.end(),comp);
        vector<int> ivl(2,0);
        ivl = intervals[0];
        for(int i=1;i<n;i++){
            if(intervals[i][0] <= ivl[1]) ivl[1] = max(intervals[i][1],ivl[1]);
            else{
                res.push_back(ivl);
                ivl = intervals[i];
            } 
        }
        res.push_back(ivl);
        return res;
    }
};