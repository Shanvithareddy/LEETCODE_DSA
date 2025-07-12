class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!= t.length()) return false;
        map<char,char> d;
        for(int i=0;i<s.length();i++){
            if(d.contains(s[i])){
                if(d[s[i]] != t[i]) return false;
            }
            else{
                d[s[i]] = t[i];
            }
        }
        map<char,char> m;
        for(int i=0;i<t.length();i++){
            if(m.contains(t[i])){
                if(m[t[i]]!= s[i]) return false;
            }
            else{
                m[t[i]] = s[i];
            }
        }
        return true;
    }
};