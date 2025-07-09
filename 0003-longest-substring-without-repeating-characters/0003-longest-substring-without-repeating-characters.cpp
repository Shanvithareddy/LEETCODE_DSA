class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s == "") return 0;
        int max_len = 1;
        int i = 0; int j=0;
        int x = j+1;
        while(x<s.size()){
            int k;
            for( k=i;k<x;k++){
                if(s[k] == s[x]) {
                    max_len = max(max_len,j-i+1);
                    i = k + 1;
                    j = x;
                    x = j+1;
                    break;
                }
            }
            if(k == x) {
                j++;
                max_len = max(max_len,j-i+1);
                x++;
            }
        }
        max_len = max(max_len,j-i+1);
        return max_len;
    }
};