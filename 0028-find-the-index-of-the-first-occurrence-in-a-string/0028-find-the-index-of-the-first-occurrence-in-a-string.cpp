class Solution {
public:
    int strStr(string haystack, string needle) {

        for(int j=0;j<haystack.size();j++){
            if(needle == haystack.substr(j,needle.size())) return j;
        }
        
        return -1;
    }
};