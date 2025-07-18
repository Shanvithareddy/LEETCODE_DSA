class Solution {
public:
    //get all immediate mutations
    vector<char> let = {'A','C','T','G'}; 
    vector<string> muts(string gene, set<string>& bank){
        vector<string> muted;
        for(int i=0;i<gene.size();i++){
            for(auto sym : let){
                if(gene[i] != sym){
                    string temp = gene;
                    temp[i] = sym;
                    if(bank.contains(temp)) muted.push_back(temp);
                }
            }
        }
        return muted;
    }
    int bfs(string startGene, string endGene, set<string>& bank){
        vector<string> current;
        current.push_back(startGene);
        set<string> visited;
        int moves = 0;
        while(!current.empty()){
            int times = current.size();
            while(times > 0){
                string gene = current.front();
                current.erase(current.begin());
                if(gene == endGene) return moves;
                for(auto temp : muts(gene,bank)){
                    if(!visited.contains(temp)){
                        visited.insert(temp);
                        current.push_back(temp);
                    }
                }
                times--;
            }
            moves++;
        }
        return -1;
    }

    int minMutation(string startGene, string endGene, vector<string>& bank) {
        set<string> geneBank;
        for(auto gene: bank){
            geneBank.insert(gene);
        }
        return bfs(startGene,endGene, geneBank);
    }
};