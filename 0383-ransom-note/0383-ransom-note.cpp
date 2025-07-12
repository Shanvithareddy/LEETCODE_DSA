class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        for(int i=0;i<ransomNote.length();i++){
            int j;
            for(j=0;j<magazine.length();j++){
                if(magazine[j] == ransomNote[i]){
                    magazine.erase(j,1);
                    j = -1;
                    break;
                }
            }
            // cout<<magazine<<","<<j<<endl;
            if(j != -1) return false;
        }
        return true;
    }
};