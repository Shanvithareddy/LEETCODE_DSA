/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:

    Node* dfs( Node* node, map<Node*,Node*>& graphMap){
        if(graphMap.contains(node)){
            return graphMap[node];
        }
        Node* newNode = new Node(node->val);
        graphMap[node] = newNode;
        for(auto neighbor: node->neighbors){
            newNode->neighbors.push_back(dfs(neighbor,graphMap));
        }
        return newNode;
    }


    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;
        map<Node*,Node*> graphMap;
        return dfs(node,graphMap);
    }
};