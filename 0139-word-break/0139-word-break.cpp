class Solution {
public:
    bool is_present(string s, vector<string> & wordDict){
        for(auto el : wordDict){
            if(el == s) return true;
        }
        return false;
    }
    int can(int x, string s, vector<int> &can_ind, vector<string>& wordDict){
        if(can_ind[x]!= -1) return can_ind[x];
        int can_now = 0;
        for(int i=1;i<=s.size()-x;i++){
            if(is_present(s.substr(x,i),wordDict)) {
                // cout<<s.substr(x,i)<<",";
                can_now = can(x+i,s,can_ind,wordDict);
                // cout<< can_now << " ;";
                if(can_now == 1) break;
            }
        }
        can_ind[x] = can_now;
        return can_ind[x];

    }


    bool wordBreak(string s, vector<string>& wordDict) {
        if( s == "") return false;
        int n = s.size();
        vector<int> can_ind(n+1,-1);
        can_ind[n] = 1;
        // cout<<can(4,s,can_ind,wordDict)<<endl;
        return can(0,s,can_ind,wordDict);
        
    }
};