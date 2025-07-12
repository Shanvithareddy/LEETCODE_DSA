class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!= t.length()) return false;
        map<char,char> d1;
        map<char,char> d2;
        for(int i=0;i<s.length();i++){
            if(d1.contains(s[i])){
                if(d1[s[i]] != t[i]) return false;
            }
            if(d2.contains(t[i])){
                if(d2[t[i]]!= s[i]) return false;
            }
            else{
                d1[s[i]] = t[i];
                d2[t[i]] = s[i];
            }
        }
        
        return true;
    }
};