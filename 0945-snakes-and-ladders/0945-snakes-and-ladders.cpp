class Solution {
public:
    int n;
    vector<int> getNexts(int k, vector<int>& board){
        vector<int> Nexts;
        for(int i=1;i<=6;i++){
            if(k+i <= n*n){
                if(board[k+i] != -1){
                    Nexts.push_back(board[k+i]);
                }
                else Nexts.push_back(k+i);
            }
        }
        return Nexts;
    }
    void print(vector<int>& list){
        for(auto el: list){
            cout<<el<<",";
        }
        cout<<endl;
    }
    int bfs(vector<int>& currNodes, vector<int>& boardL ){
        set<int> covered;
        int level = 0;
        // bool found = false;
        while(!currNodes.empty()){
            int times = currNodes.size();
                print(currNodes);
            while(times > 0){
                int curr = currNodes.front();
                currNodes.erase(currNodes.begin());
                covered.insert(curr);
                if(curr == n*n) return level;
                for(auto tempnext : getNexts(curr,boardL)){
                    if(covered.contains(tempnext)) continue;
                    covered.insert(tempnext);
                    currNodes.push_back(tempnext);
                }
                times--;
            }
            level++;
        }
        return -1;
    }


    int snakesAndLadders(vector<vector<int>>& board) {
        n = board.size();
        //create boardL
        vector<int> boardL(n * n + 1, -1); // 1-based
        int idx = 1;
        bool leftToRight = true;
        for (int i = n - 1; i >= 0; --i) {
            if (leftToRight) {
                for (int j = 0; j < n; ++j) {
                    boardL[idx++] = board[i][j];
                }
            } else {
                for (int j = n - 1; j >= 0; --j) {
                    boardL[idx++] = board[i][j];
                }
            }
            leftToRight = !leftToRight;
        }
        vector<int> currNodes;
        currNodes.push_back(1);
        return bfs(currNodes, boardL);
    }
};