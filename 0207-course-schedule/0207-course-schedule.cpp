class Solution {
public:
    struct Node{
        int val;
        vector<int> pres;
        Node(int _val){
            val = _val;
        }
    };

    bool dfs(int k, map<int, Node*>& Graph, vector<bool>& visited, vector<bool>& onPath) {
        visited[k] = true;
        onPath[k] = true;

        for (auto pre : Graph[k]->pres) {
            if (!visited[pre]) {
                if (!dfs(pre, Graph, visited, onPath))
                    return false;
            } else if (onPath[pre]) {
                // Found a cycle
                return false;
            }
        }

        onPath[k] = false; // Backtrack
        return true;
    }





    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        map<int,Node*> Graph;
        for(int i=0;i<numCourses;i++){
            Graph[i] = new Node(i);
        }
        for(int i=0;i<prerequisites.size();i++){
            Graph[prerequisites[i][0]]->pres.push_back(prerequisites[i][1]);
        }
        vector<bool> visited(numCourses,false);
        vector<bool> temp_visited(numCourses,false);

        // bool cycle_found = false;
        for(int i=0;i<numCourses;i++){
            if(visited[i] == false) {
                if(!dfs(i,Graph,visited,temp_visited)) return false;
            }
        }
        return true;
    }
};