class Solution {
public:
    static bool comp(vector<int> first, vector<int> second){
        return first[1] < second[1];
    }
    
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),comp);
        int start = points[0][0];
        int end = points[0][1];
        int num =1;
        for(int i=1;i<points.size();i++){
            if(points[i][0] <= end) continue;
            else{
                num++;
                start = points[i][0];
                end = points[i][1];
            }
        }
        return num;
    }
};