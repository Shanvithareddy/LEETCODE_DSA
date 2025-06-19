class Solution {
public:
    bool isAnagram(string s, string t) {
        // if(s.size()!= t.size()) return false;
        // for(int i=0;i<t.size();i++){
        //     for(int j=0;j<s.size();j++){
        //         if(t[i] == s[j]) {
        //             s[j] = '*';
        //             break;
        //         }
        //         else{
        //             if(j==s.size()-1) return false;
        //         }
        //     }
        // }
        
        // return true;
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        if(s==t) return true;
        else return false;
    }
};