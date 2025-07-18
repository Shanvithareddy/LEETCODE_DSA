class Solution {
public:
    struct Node{
        string letter;
        vector<pair<Node*,double>> neighbors;
        
    };
    map<string,Node*> createGraph(vector<vector<string>>& equations, vector<double>& values){
        map<string,Node*> graph;
        for(int i=0;i<equations.size();i++){
            if(!graph.contains(equations[i][0])){
                Node * temp = new Node();
                temp->letter = equations[i][0];
                graph[equations[i][0]] = temp;
            }
            if(!graph.contains(equations[i][1])){
                Node* temp = new Node();
                temp->letter = equations[i][1];
                graph[equations[i][1]] = temp;
            }
            Node* tempA = graph[equations[i][0]];
            Node* tempB = graph[equations[i][1]];
            tempA->neighbors.push_back({tempB,values[i]});
            tempB->neighbors.push_back({tempA,1/values[i]});

        }
        return graph;
    }


    bool dfs(Node* curr, Node* target, set<Node*>& visited, double& result, double currentProduct) {
        if (curr == target) {
            result = currentProduct;
            return true;
        }

        visited.insert(curr);

        for (auto& neighbor : curr->neighbors) {
            Node* next = neighbor.first;
            double weight = neighbor.second;

            if (!visited.count(next)) {
                if (dfs(next, target, visited, result, currentProduct * weight)) {
                    return true;
                }
            }
        }

        return false;
    }









    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        //first of all need to construct a graph out of equations and values;
        map<string,Node*> graph;
        graph = createGraph(equations,values);
        //map each of letter with a value;

        vector<double> res;
        for(auto query: queries){
            if (!graph.contains(query[0]) || !graph.contains(query[1])) {
                res.push_back(-1.0);
                continue;
            }
            set<Node*> visited;
            double result = -1.0;
            bool found = dfs(graph[query[0]], graph[query[1]], visited, result, 1.0);
            res.push_back(found ? result : -1.0);
        }
        return res;
    }
};