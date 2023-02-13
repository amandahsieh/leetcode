/*-----------------Author: Hsin-Yu Hsieh-----------------*/
/*First Trial: DFS recursive   T:3 97.13%    M:8.6 87.25%*/

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
    Node* v[105];
    Node* cloneGraph(Node* node) {
        if(!node)   return NULL;
        int t = node->val;
        if(v[t])    return v[t];
        v[t] = new Node(t);
        for(int i=0; i<node->neighbors.size(); i++){
            v[t]->neighbors.push_back(cloneGraph(node->neighbors[i]));
        }
        return v[t];
    }
};