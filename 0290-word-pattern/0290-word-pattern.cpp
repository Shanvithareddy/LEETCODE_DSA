class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> s_words;//contains words of s separated;
        string temp = "";
        for(int i=0;i<s.size();i++){
            if(s[i] == ' ' || s[i] == '\n'){
                s_words.push_back(temp);
                temp = "";
                continue;
            }
            temp += s[i];
        }
        s_words.push_back(temp);
        if(s_words.size() != pattern.size()) return false;
        unordered_map<char,string> m1;
        unordered_map<string,char> m2;
        for(int i=0;i<pattern.size();i++){
            if(m1.contains(pattern[i])){
                if(m1[pattern[i]] != s_words[i]) return false;
            }
            if(m2.contains(s_words[i])){
                if(m2[s_words[i]]!=pattern[i]) return false;
            }
            else {
                m1[pattern[i]] = s_words[i];
                m2[s_words[i]] = pattern[i];
            }
        }
        
        return true;
    }
};