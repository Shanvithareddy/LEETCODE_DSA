class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> counts;
        for(int i=0;i<magazine.length();i++){
            // if(counts.contains(magazine[i])){
            //     counts[magazine[i]]++;
            // }
            // else{
            //     counts[magazine[i]] = 1;
            // }
            counts[magazine[i]]++;

        }
        for(int i=0;i<ransomNote.length();i++){
            // if(counts.contains(ransomNote[i])){
                counts[ransomNote[i]]--;
                if(counts[ransomNote[i]]<0) return false;
            // }
            // else return false;
        }
        return true;
    }
};