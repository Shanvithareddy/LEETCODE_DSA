class Solution {
public:

    //get neighbors function here
    bool is_mut(string s, string t){
        int changes = 0;
        for(int i=0;i<s.size();i++){
            if(s[i] != t[i]) changes++;
            if(changes > 1) return false;
        }
        if(changes == 1) return true;
        else return false;
    }
    vector<string> get_neighbors(string s, vector<string>& wordList) {
        vector<string> res;
        for(auto word : wordList) {
            if(is_mut(s,word)) res.push_back(word);
        }
        return res;
    }
    int bfs ( string start, string end, vector<string>& wordList){
        vector<string> current;
        current.push_back(start);
        int moves = 1;
        set<string> covered;
        while(!current.empty()){
            int times = current.size();
            while(times > 0){
                string curr = current.front();
                current.erase(current.begin());
                if(curr == end) return moves;
                for(auto s: get_neighbors(curr,wordList)){
                    if(covered.contains(s)) continue;
                    covered.insert(s);
                    current.push_back(s);
                }
                times--;
            }
            moves++;
        }
        return 0;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        return bfs(beginWord, endWord, wordList);
    }
};