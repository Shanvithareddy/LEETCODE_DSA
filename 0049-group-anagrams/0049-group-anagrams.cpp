class Solution {
public:
    bool isAngrm(string s, string t){
        if(s.size()!=t.size()) return false;
        for(int i=0;i<s.size();i++){
            for(int j=0;j<t.size();j++){
                if(t[j] == s[i]){
                    t[j] = '*';
                    s[i] = '*';
                    break;
                }
            }
            if(s[i]!='*') return false;
        }
        return true;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        while(!strs.empty()){
            string s = strs[0];
            strs.erase(strs.begin());
            vector<string> temp;
            temp.push_back(s);
            for(int j=0;j<strs.size();j++){
                if(isAngrm(s,strs[j])){
                    temp.push_back(strs[j]);
                    strs.erase(strs.begin()+j);
                    j--;
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};