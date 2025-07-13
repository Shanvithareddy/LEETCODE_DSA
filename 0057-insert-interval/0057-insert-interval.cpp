class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i;
        for(i=0;i<intervals.size();i++){
            if(intervals[i][0] > newInterval[0]) break;
        }
        intervals.insert(intervals.begin()+i,newInterval);
        if(i==0) i++;
        cout<<i<<endl;
        for(int j=i;j<intervals.size();j++){
            if(intervals[j][0] <= intervals[j-1][1]){
                intervals[j-1][1] = max(intervals[j-1][1],intervals[j][1]);
                intervals.erase(intervals.begin()+j);
                j--;
            }
            else if(j == i) continue;
            else break;
            
        }
        return intervals;
    }
};